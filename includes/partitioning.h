#pragma once

#include <mpi.h>

#include "settings.h"
#include "array2d.h"
#include "central_differences.h"
#include "donor_cell.h"

class Partitioning
{
public:
    Partitioning()
    {
        MPI_Comm_rank(MPI_COMM_WORLD, &ownRank_);
        MPI_Comm_size(MPI_COMM_WORLD, &noRanks_);
    };

    void set_ghost(Array2D &data, int messageTag) const
    {
        std::vector<double> row(data.size()[0]);
        std::vector<double> column(data.size()[1]);
        if (leftProcess_ != 4)
        {
            MPI_Recv(column.data(), data.size()[1], MPI_DOUBLE, leftProcess_, messageTag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            data.set_column(0, column);
        }
        if (rightProcess_ != 4)
        {
            MPI_Recv(column.data(), data.size()[1], MPI_DOUBLE, rightProcess_, messageTag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            data.set_column(data.size()[0] - 1, column);
        }
        if (upProcess_ != 4)
        {
            MPI_Recv(row.data(), data.size()[0], MPI_DOUBLE, upProcess_, messageTag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            data.set_row(data.size()[1] - 1, row);
        }
        if (downProcess_ != 4)
        {
            MPI_Recv(row.data(), data.size()[0], MPI_DOUBLE, downProcess_, messageTag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            data.set_row(0, row);
        }
    };

    double get_time(double myTime) const
    {
        double newTime;
        MPI_Allreduce(&myTime, &newTime, 1, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD);

        return newTime;
    };

    int noRanks_;
    int ownRank_;

    //holds rank of neighbor process if rank equals to nRanks there is no neighbor bc-condition has to be applied
    int leftProcess_;
    int rightProcess_;
    int upProcess_;
    int downProcess_;

    //holds rank of neighbor process if rank equals to nRanks there is no neighbor bc-condition has to be applied
    std::array<int, 2> nCells_;
    std::array<double, 2> physicalSize_;

    //get discretization instance depending on settings
    std::shared_ptr<Discretization> get_discretization(const Settings &settings)
    //get discretization instance depending on settings
    {
        std::array<edgetype, 4> edgestype;
        if (ownRank_ == 0)
        {
            leftProcess_ = 4;
            rightProcess_ = 1;
            upProcess_ = 4;
            downProcess_ = 2;
            nCells_[0] = settings.nCells()[0] / 2 + settings.nCells()[0] % 2;
            nCells_[1] = settings.nCells()[1] / 2 + settings.nCells()[1] % 2;
            physicalSize_[0] = settings.physicalSize()[0] / settings.nCells()[0] * nCells_[0];
            physicalSize_[1] = settings.physicalSize()[1] / settings.nCells()[1] * nCells_[1];
            //top, bottom, left, right
            edgestype = {HALO, GHOST, HALO, GHOST};
        }
        else if (ownRank_ == 1)
        {
            leftProcess_ = 0;
            rightProcess_ = 4;
            upProcess_ = 4;
            downProcess_ = 3;
            nCells_[0] = settings.nCells()[0] / 2;
            nCells_[1] = settings.nCells()[1] / 2 + settings.nCells()[1] % 2;
            physicalSize_[0] = settings.physicalSize()[0] / settings.nCells()[0] * nCells_[0];
            physicalSize_[1] = settings.physicalSize()[1] / settings.nCells()[1] * nCells_[1];
            edgestype = {HALO, GHOST, GHOST, HALO};
        }
        else if (ownRank_ == 2)
        {
            leftProcess_ = 4;
            rightProcess_ = 3;
            upProcess_ = 0;
            downProcess_ = 4;
            nCells_[0] = settings.nCells()[0] / 2 + settings.nCells()[0] % 2;
            nCells_[1] = settings.nCells()[1] / 2;
            physicalSize_[0] = settings.physicalSize()[0] / settings.nCells()[0] * nCells_[0];
            physicalSize_[1] = settings.physicalSize()[1] / settings.nCells()[1] * nCells_[1];
            edgestype = {GHOST, HALO, HALO, GHOST};
        }
        else if (ownRank_ == 3)
        {
            leftProcess_ = 2;
            rightProcess_ = 4;
            upProcess_ = 1;
            downProcess_ = 4;
            nCells_[0] = settings.nCells()[0] / 2;
            nCells_[1] = settings.nCells()[1] / 2;
            physicalSize_[0] = settings.physicalSize()[0] / settings.nCells()[0] * nCells_[0];
            physicalSize_[1] = settings.physicalSize()[1] / settings.nCells()[1] * nCells_[1];
            edgestype = {GHOST, HALO, GHOST, HALO};
        }

        //create discretization depending on a settings value
        if (settings.useDonorCell())
        {
            //create donor cell discretization
            return std::make_shared<DonorCell>(nCells_, physicalSize_, settings.alpha(), edgestype);
        }
        else
        {
            //create central differences
            return std::make_shared<CentralDifferences>(nCells_, physicalSize_, edgestype);
        }
    };

    void exchange_uv(FieldVariable &u, FieldVariable &v, const Settings &settings) const
    {
        std::vector<MPI_Request> sendRequests;

        if (leftProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(u.get_column(1).data(), u.size()[1], MPI_DOUBLE, leftProcess_, 1, MPI_COMM_WORLD, &sendRequests.back());
            sendRequests.emplace_back();
            MPI_Isend(v.get_column(1).data(), v.size()[1], MPI_DOUBLE, leftProcess_, 2, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            u.set_boundary_dirichlet(LEFT, settings.dirichletBcLeft()[0]);
            v.set_boundary_dirichlet(LEFT, settings.dirichletBcLeft()[1]);
        }

        if (rightProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(u.get_column(u.size()[0] - 2).data(), u.size()[1], MPI_DOUBLE, rightProcess_, 1, MPI_COMM_WORLD, &sendRequests.back());
            sendRequests.emplace_back();
            MPI_Isend(v.get_column(v.size()[0] - 2).data(), v.size()[1], MPI_DOUBLE, rightProcess_, 2, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            u.set_boundary_dirichlet(RIGHT, settings.dirichletBcRight()[0]);
            v.set_boundary_dirichlet(RIGHT, settings.dirichletBcRight()[1]);
        }
        if (upProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(u.get_row(u.size()[1] - 2).data(), u.size()[0], MPI_DOUBLE, upProcess_, 1, MPI_COMM_WORLD, &sendRequests.back());
            sendRequests.emplace_back();
            MPI_Isend(v.get_row(v.size()[1] - 2).data(), v.size()[0], MPI_DOUBLE, upProcess_, 2, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            u.set_boundary_dirichlet(TOP, settings.dirichletBcTop()[0]);
            v.set_boundary_dirichlet(TOP, settings.dirichletBcTop()[1]);
        }
        if (downProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(u.get_row(1).data(), u.size()[0], MPI_DOUBLE, downProcess_, 1, MPI_COMM_WORLD, &sendRequests.back());
            sendRequests.emplace_back();
            MPI_Isend(v.get_row(1).data(), v.size()[0], MPI_DOUBLE, downProcess_, 2, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            u.set_boundary_dirichlet(BOTTOM, settings.dirichletBcBottom()[0]);
            v.set_boundary_dirichlet(BOTTOM, settings.dirichletBcBottom()[1]);
        }

        //wait for all pending send requests to complete
        MPI_Waitall(sendRequests.size(), sendRequests.data(), MPI_STATUSES_IGNORE);
        set_ghost(u, 1);
        set_ghost(v, 2);

        //wait for all pending send requests to complete
        MPI_Waitall(sendRequests.size(), sendRequests.data(), MPI_STATUSES_IGNORE);
    };

    void exchange_fg(FieldVariable &f, FieldVariable &g, const FieldVariable &u, const FieldVariable &v) const
    {
        std::vector<MPI_Request> sendRequests;

        if (leftProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(f.get_column(1).data(), f.size()[1], MPI_DOUBLE, leftProcess_, 3, MPI_COMM_WORLD, &sendRequests.back());
            sendRequests.emplace_back();
            MPI_Isend(g.get_column(1).data(), g.size()[1], MPI_DOUBLE, leftProcess_, 4, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            f.set_column(0, u.get_column(0));
            g.set_column(0, v.get_column(0));
        }

        if (rightProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(f.get_column(f.size()[0] - 2).data(), f.size()[1], MPI_DOUBLE, rightProcess_, 3, MPI_COMM_WORLD, &sendRequests.back());
            sendRequests.emplace_back();
            MPI_Isend(g.get_column(g.size()[0] - 2).data(), g.size()[1], MPI_DOUBLE, rightProcess_, 4, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            f.set_column(f.size()[0] - 1, u.get_column(f.size()[0] - 1));
            g.set_column(g.size()[0] - 1, v.get_column(g.size()[0] - 1));
        }
        if (upProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(f.get_row(f.size()[1] - 2).data(), f.size()[0], MPI_DOUBLE, upProcess_, 3, MPI_COMM_WORLD, &sendRequests.back());
            sendRequests.emplace_back();
            MPI_Isend(g.get_row(g.size()[1] - 2).data(), g.size()[0], MPI_DOUBLE, upProcess_, 4, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            f.set_row(f.size()[1] - 1, u.get_row(f.size()[1] - 1));
            g.set_row(g.size()[1] - 1, v.get_row(g.size()[1] - 1));
        }
        if (downProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(f.get_row(1).data(), f.size()[0], MPI_DOUBLE, downProcess_, 3, MPI_COMM_WORLD, &sendRequests.back());
            sendRequests.emplace_back();
            MPI_Isend(g.get_row(1).data(), g.size()[0], MPI_DOUBLE, downProcess_, 4, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            f.set_row(0, u.get_row(0));
            g.set_row(0, v.get_row(0));
        }

        //wait for all pending send requests to complete
        MPI_Waitall(sendRequests.size(), sendRequests.data(), MPI_STATUSES_IGNORE);

        set_ghost(f, 3);
        set_ghost(g, 4);
    };

    void exchange_p(FieldVariable &p) const
    {
        std::vector<MPI_Request> sendRequests;
        if (leftProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(p.get_column(1).data(), p.size()[1], MPI_DOUBLE, leftProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            p.set_boundary_neumann(LEFT, 0);
        }

        if (rightProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(p.get_column(p.size()[0] - 2).data(), p.size()[1], MPI_DOUBLE, rightProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            p.set_boundary_neumann(RIGHT, 0);
        }
        if (upProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(p.get_row(p.size()[1] - 2).data(), p.size()[0], MPI_DOUBLE, upProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            p.set_boundary_neumann(TOP, 0);
        }
        if (downProcess_ != 4)
        {
            sendRequests.emplace_back();
            MPI_Isend(p.get_row(1).data(), p.size()[0], MPI_DOUBLE, downProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
        }
        else
        {
            p.set_boundary_neumann(BOTTOM, 0);
        }

        //wait for all pending send requests to complete
        MPI_Waitall(sendRequests.size(), sendRequests.data(), MPI_STATUSES_IGNORE);

        set_ghost(p, 5);
    };
};