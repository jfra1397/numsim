#include "../includes/partitioning.h"

#include <math.h>


Partitioning::Partitioning()
{
    MPI_Comm_rank(MPI_COMM_WORLD, &ownRank_);
    MPI_Comm_size(MPI_COMM_WORLD, &noRanks_);
}

void Partitioning::set_ghost(Array2D &data, int messageTag) const
{
    std::vector<double> row(data.size()[0]);
    std::vector<double> column(data.size()[1]);
    if (leftProcess_ != noRanks_)
    {
        MPI_Recv(column.data(), data.size()[1], MPI_DOUBLE, leftProcess_, messageTag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data.set_column(0, column);
    }
    if (rightProcess_ != noRanks_)
    {
        MPI_Recv(column.data(), data.size()[1], MPI_DOUBLE, rightProcess_, messageTag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data.set_column(data.size()[0] - 1, column);
    }
    if (upProcess_ != noRanks_)
    {
        MPI_Recv(row.data(), data.size()[0], MPI_DOUBLE, upProcess_, messageTag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data.set_row(data.size()[1] - 1, row);
    }
    if (downProcess_ != noRanks_)
    {
        MPI_Recv(row.data(), data.size()[0], MPI_DOUBLE, downProcess_, messageTag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data.set_row(0, row);
    }
}

double Partitioning::get_time(double myTime) const
{
    double newTime;
    MPI_Allreduce(&myTime, &newTime, 1, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD);

    return newTime;
}


//get discretization instance depending on settings
std::shared_ptr<Discretization> Partitioning::get_discretization(const Settings &settings)
{
    nCellsGlobal_ = settings.nCells();
    physicalSizeGlobal_ = settings.physicalSize();

    float temp = float(nCellsGlobal_[0]) / float(nCellsGlobal_[1]);
    bool changed = false;
    if (temp < 1)
    {
        temp = 1/temp;
        changed = true;
    }
    int n = int(ceil(sqrt(float(noRanks_) * temp)));
    while (noRanks_ % n !=0)
    {
        n--;
    }
    int m = noRanks_/n;
    int noRanksx, noRanksy;
    if (changed)
    {
        noRanksx = std::min(n,m);
        noRanksy = std::max(n,m);
    }
    else
    {
        noRanksx = std::max(n,m);
        noRanksy = std::min(n,m);
    }
    //top, bottom, left, right
    std::array<edgetype, 4> edgestype = {GHOST, GHOST, GHOST, GHOST};
    int ownPosy = ownRank_/noRanksx;
    int ownPosx = ownRank_-ownPosy * noRanksx;
    if (ownPosx-1>=0) leftProcess_ = ownRank_-1;
    else
    {
        leftProcess_ = noRanks_;
        edgestype[2] = HALO;
    }
    if (ownPosx+1 < noRanksx) rightProcess_ = ownRank_+1;
    else
    {
        rightProcess_ = noRanks_;
        edgestype[3] = HALO;
    }
    if (ownPosy-1 >= 0) downProcess_ = ownRank_ - noRanksx;
    else
    {
        downProcess_ = noRanks_;
        edgestype[1] = HALO;
    }
    if (ownPosy+1 < noRanksy) upProcess_ = ownRank_ + noRanksx;
    else
    {
        upProcess_ = noRanks_;
        edgestype[0] = HALO;
    }

    int nCellsx = nCellsGlobal_[0] / noRanksx;
    int nCellsy = nCellsGlobal_[1] / noRanksy; 

    if (nCellsGlobal_[0]%noRanksx > ownPosx) nCells_[0] = nCellsx + 1;
    else nCells_[0] = nCellsx;
    if (nCellsGlobal_[1]%noRanksy > ownPosy) nCells_[1] = nCellsy + 1;
    else nCells_[1] = nCellsy;
    
    physicalSize_[0] = physicalSizeGlobal_[0] / nCellsGlobal_[0] * nCells_[0];
    physicalSize_[1] = physicalSizeGlobal_[1] / nCellsGlobal_[1] * nCells_[1];

    nodeOffset_[0] = ownPosx * nCellsx + std::min(ownPosx, nCellsGlobal_[0]%noRanksx);
    nodeOffset_[1] = ownPosy * nCellsy + std::min(ownPosy, nCellsGlobal_[1]%noRanksy);
    
    // std::array<edgetype, 4> edgestype;
    // if (ownRank_ == 0)
    // {
    //     leftProcess_ = 4;
    //     rightProcess_ = 1;
    //     upProcess_ = 4;
    //     downProcess_ = 2;
    //     nCells_[0] = settings.nCells()[0] / 2 + settings.nCells()[0] % 2;
    //     nCells_[1] = settings.nCells()[1] / 2 + settings.nCells()[1] % 2;
    //     physicalSize_[0] = settings.physicalSize()[0] / settings.nCells()[0] * nCells_[0];
    //     physicalSize_[1] = settings.physicalSize()[1] / settings.nCells()[1] * nCells_[1];
    //     nodeOffset_[0] = 0;
    //     nodeOffset_[1] = nCellsGlobal_[1] - nCells_[1];
    //     //top, bottom, left, right
    //     edgestype = {HALO, GHOST, HALO, GHOST};
    // }
    // else if (ownRank_ == 1)
    // {
    //     leftProcess_ = 0;
    //     rightProcess_ = 4;
    //     upProcess_ = 4;
    //     downProcess_ = 3;
    //     nCells_[0] = settings.nCells()[0] / 2;
    //     nCells_[1] = settings.nCells()[1] / 2 + settings.nCells()[1] % 2;
    //     physicalSize_[0] = settings.physicalSize()[0] / settings.nCells()[0] * nCells_[0];
    //     physicalSize_[1] = settings.physicalSize()[1] / settings.nCells()[1] * nCells_[1];
    //     edgestype = {HALO, GHOST, GHOST, HALO};

    //     nodeOffset_[0] = nCellsGlobal_[0] - nCells_[0];
    //     nodeOffset_[1] = nCellsGlobal_[1] - nCells_[1];
    // }
    // else if (ownRank_ == 2)
    // {
    //     leftProcess_ = 4;
    //     rightProcess_ = 3;
    //     upProcess_ = 0;
    //     downProcess_ = 4;
    //     nCells_[0] = settings.nCells()[0] / 2 + settings.nCells()[0] % 2;
    //     nCells_[1] = settings.nCells()[1] / 2;
    //     physicalSize_[0] = settings.physicalSize()[0] / settings.nCells()[0] * nCells_[0];
    //     physicalSize_[1] = settings.physicalSize()[1] / settings.nCells()[1] * nCells_[1];
    //     edgestype = {GHOST, HALO, HALO, GHOST};
    //     nodeOffset_[0] = 0;
    //     nodeOffset_[1] = 0;
    // }
    // else if (ownRank_ == 3)
    // {
    //     leftProcess_ = 2;
    //     rightProcess_ = 4;
    //     upProcess_ = 1;
    //     downProcess_ = 4;
    //     nCells_[0] = settings.nCells()[0] / 2;
    //     nCells_[1] = settings.nCells()[1] / 2;
    //     physicalSize_[0] = settings.physicalSize()[0] / settings.nCells()[0] * nCells_[0];
    //     physicalSize_[1] = settings.physicalSize()[1] / settings.nCells()[1] * nCells_[1];
    //     edgestype = {GHOST, HALO, GHOST, HALO};
    //     nodeOffset_[0] = nCellsGlobal_[0] - nCells_[0];
    //     nodeOffset_[1] = 0;
    // }

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
}

void Partitioning::exchange_uv(FieldVariable &u, FieldVariable &v, const Settings &settings) const
{
    std::vector<MPI_Request> sendRequests;

    if (leftProcess_ != noRanks_)
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

    if (rightProcess_ != noRanks_)
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
    if (upProcess_ != noRanks_)
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
    if (downProcess_ != noRanks_)
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
}

void Partitioning::exchange_fg(FieldVariable &f, FieldVariable &g, const FieldVariable &u, const FieldVariable &v) const
{
    std::vector<MPI_Request> sendRequests;

    if (leftProcess_ != noRanks_)
    {
        sendRequests.emplace_back();
        MPI_Isend(f.get_column(1).data(), f.size()[1], MPI_DOUBLE, leftProcess_, 3, MPI_COMM_WORLD, &sendRequests.back());
        // sendRequests.emplace_back();
        // MPI_Isend(g.get_column(1).data(), g.size()[1], MPI_DOUBLE, leftProcess_, 4, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        f.set_column(0, u.get_column(0));
        // g.set_column(0, v.get_column(0));
    }

    if (rightProcess_ != noRanks_)
    {
        sendRequests.emplace_back();
        MPI_Isend(f.get_column(f.size()[0] - 2).data(), f.size()[1], MPI_DOUBLE, rightProcess_, 3, MPI_COMM_WORLD, &sendRequests.back());
        // sendRequests.emplace_back();
        // MPI_Isend(g.get_column(g.size()[0] - 2).data(), g.size()[1], MPI_DOUBLE, rightProcess_, 4, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        f.set_column(f.size()[0] - 1, u.get_column(f.size()[0] - 1));
        // g.set_column(g.size()[0] - 1, v.get_column(g.size()[0] - 1));
    }
    if (upProcess_ != noRanks_)
    {
        // sendRequests.emplace_back();
        // MPI_Isend(f.get_row(f.size()[1] - 2).data(), f.size()[0], MPI_DOUBLE, upProcess_, 3, MPI_COMM_WORLD, &sendRequests.back());
        sendRequests.emplace_back();
        MPI_Isend(g.get_row(g.size()[1] - 2).data(), g.size()[0], MPI_DOUBLE, upProcess_, 4, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        // f.set_row(f.size()[1] - 1, u.get_row(f.size()[1] - 1));
        g.set_row(g.size()[1] - 1, v.get_row(g.size()[1] - 1));
    }
    if (downProcess_ != noRanks_)
    {
        // sendRequests.emplace_back();
        // MPI_Isend(f.get_row(1).data(), f.size()[0], MPI_DOUBLE, downProcess_, 3, MPI_COMM_WORLD, &sendRequests.back());
        sendRequests.emplace_back();
        MPI_Isend(g.get_row(1).data(), g.size()[0], MPI_DOUBLE, downProcess_, 4, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        // f.set_row(0, u.get_row(0));
        g.set_row(0, v.get_row(0));
    }

    //wait for all pending send requests to complete
    MPI_Waitall(sendRequests.size(), sendRequests.data(), MPI_STATUSES_IGNORE);

    set_ghost_fg(f, g);
}


void Partitioning::set_ghost_fg(Array2D &f, Array2D &g) const
{
    std::vector<double> row_f(f.size()[0]);
    std::vector<double> row_g(g.size()[0]);
    std::vector<double> column_f(f.size()[1]);
    std::vector<double> column_g(g.size()[1]);
    if (leftProcess_ != noRanks_)
    {
        MPI_Recv(column_f.data(), column_f.size(), MPI_DOUBLE, leftProcess_, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        f.set_column(0, column_f);
        // MPI_Recv(column_g.data(), column_g.size(), MPI_DOUBLE, leftProcess_, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        // g.set_column(0, column_g);
    }
    if (rightProcess_ != noRanks_)
    {
        MPI_Recv(column_f.data(), column_f.size(), MPI_DOUBLE, rightProcess_, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        f.set_column(f.size()[0] - 1, column_f);
        // MPI_Recv(column_g.data(), column_g.size(), MPI_DOUBLE, rightProcess_, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        // g.set_column(g.size()[0] - 1, column_g);
    }
    if (upProcess_ != noRanks_)
    {
        // MPI_Recv(row_f.data(), row_f.size(), MPI_DOUBLE, upProcess_, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        // f.set_row(f.size()[1] - 1, row_f);
        MPI_Recv(row_g.data(), row_g.size(), MPI_DOUBLE, upProcess_, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        g.set_row(g.size()[1] - 1, row_g);
    }
    if (downProcess_ != noRanks_)
    {
        // MPI_Recv(row_f.data(), row_f.size(), MPI_DOUBLE, downProcess_, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        // f.set_row(0, row_f);
        MPI_Recv(row_g.data(), row_g.size(), MPI_DOUBLE, downProcess_, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        g.set_row(0, row_g);
    }
}

void Partitioning::exchange_p(FieldVariable &p, int startPos) const
{
    std::vector<MPI_Request> sendRequests;
    int size;
    int startAdvanced;
    if (leftProcess_ != noRanks_)
    {
        size = p.size()[1]/2 + (1-startPos)* p.size()[1]%2;
        sendRequests.emplace_back();
        MPI_Isend(p.get_column(1, startPos, 2).data(), size, MPI_DOUBLE, leftProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        p.set_boundary_neumann(LEFT, 0);
    }

    if (rightProcess_ != noRanks_)
    {
        startAdvanced = (startPos + nCells_[0] + 1)%2;
        size = p.size()[1]/2 + (1-startAdvanced)* p.size()[1]%2;
        sendRequests.emplace_back();
        MPI_Isend(p.get_column(p.size()[0] - 2, startAdvanced, 2).data(),size, MPI_DOUBLE, rightProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        p.set_boundary_neumann(RIGHT, 0);
    }
    if (upProcess_ != noRanks_)
    {
        startAdvanced = (startPos + nCells_[1] + 1)%2;
        size = p.size()[0]/2 + (1-startAdvanced)* p.size()[0]%2;
        sendRequests.emplace_back();
        MPI_Isend(p.get_row(p.size()[1] - 2, startAdvanced, 2).data(), size, MPI_DOUBLE, upProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        p.set_boundary_neumann(TOP, 0);
    }
    if (downProcess_ != noRanks_)
    {
        size = p.size()[0]/2 + (1-startPos)* p.size()[0]%2;
        sendRequests.emplace_back();
        MPI_Isend(p.get_row(1, startPos, 2).data(), size, MPI_DOUBLE, downProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        p.set_boundary_neumann(BOTTOM, 0);
    }

    //wait for all pending send requests to complete
    MPI_Waitall(sendRequests.size(), sendRequests.data(), MPI_STATUSES_IGNORE);

    set_ghost_p(p, startPos);
}

void Partitioning::set_ghost_p(Array2D &p, int startPos) const
{
    int startAdvanced; 
    int size;
    std::vector<double> row(p.size()[0]);
    if (leftProcess_ != noRanks_)
    {
        size = p.size()[1]/2 + (1-(startPos+1)%2)* p.size()[1]%2;
        std::vector<double> column(size);
        MPI_Recv(column.data(), column.size(), MPI_DOUBLE, leftProcess_, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        p.set_column(0, column, (startPos+1)%2, 2);
    }
    if (rightProcess_ != noRanks_)
    {
        startAdvanced = (startPos + 1 + nCells_[0] + 1)%2;
        size = p.size()[1]/2 + (1-startAdvanced)* p.size()[1]%2;
        std::vector<double> column(size);
        MPI_Recv(column.data(), column.size(), MPI_DOUBLE, rightProcess_, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        p.set_column(p.size()[0] - 1, column, startAdvanced, 2);
    }
    if (upProcess_ != noRanks_)
    {
        startAdvanced = (startPos + 1 + nCells_[1] + 1)%2;
        size = p.size()[0]/2 + (1-startAdvanced)* p.size()[0]%2;
        std::vector<double> row(size);
        MPI_Recv(row.data(), row.size(), MPI_DOUBLE, upProcess_, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        p.set_row(p.size()[1] - 1, row, startAdvanced, 2);
    }
    if (downProcess_ != noRanks_)
    {
        size = p.size()[0]/2 + (1-(startPos+1)%2)* p.size()[0]%2;
        std::vector<double> row(size);
        MPI_Recv(row.data(), row.size(), MPI_DOUBLE, downProcess_, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        p.set_row(0, row, (startPos+1)%2, 2);
    }
}


std::array<int, 2> Partitioning::nCells() const
{
    return nCells_;
}
std::array<double, 2> Partitioning::physicalSize() const
{
    return physicalSize_;
}
std::array<int, 2> Partitioning::nCellsGlobal() const
{
    return nCellsGlobal_;
}
std::array<double, 2> Partitioning::physicalSizeGlobal() const
{
    return physicalSizeGlobal_;
}


bool Partitioning::ownPartitionContainsRightBoundary() const
{
    return (rightProcess_ == noRanks_);
}
bool Partitioning::ownPartitionContainsTopBoundary() const
{
    return (upProcess_ == noRanks_);
}

int Partitioning::noRanks() const { return noRanks_;}
int Partitioning::ownRankNo() const { return ownRank_;}
std::array<int,2> Partitioning::nodeOffset() const { return nodeOffset_;}