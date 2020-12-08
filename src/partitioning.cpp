#include "../includes/partitioning.h"

#include <math.h>

//constructor
Partitioning::Partitioning()
{
    //get rank of own process
    MPI_Comm_rank(MPI_COMM_WORLD, &ownRank_);

    //get amount of acting processes
    MPI_Comm_size(MPI_COMM_WORLD, &noRanks_);
}

//get calculated timestep of each process and return minimum
double Partitioning::get_time(double myTime) const
{
    double newTime;

    //set new timestep of all processes to minimum of all received timsteps
    MPI_Allreduce(&myTime, &newTime, 1, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD);
    return newTime;
}

//get discretization instance depending on settings
std::shared_ptr<Discretization> Partitioning::get_discretization(const Settings &settings)
{
    //number of cells of global area
    nCellsGlobal_ = settings.nCells();

    //physical size of global area
    physicalSizeGlobal_ = settings.physicalSize();

    //aspect ratio
    float temp = float(nCellsGlobal_[0]) / float(nCellsGlobal_[1]);

    bool changed = false;

    //change ratio if smaller than 1
    if (temp < 1)
    {
        temp = 1 / temp;
        changed = true;
    }

    //first guess for factorization of amount of processes
    int n = int(ceil(sqrt(float(noRanks_) * temp)));

    //decrement n until real divider
    while (noRanks_ % n != 0)
    {
        n--;
    }

    //second factor
    int m = noRanks_ / n;

    //set number of processes in both directions corresponding to aspect ratio
    int noRanksx, noRanksy;
    if (changed)
    {
        noRanksx = std::min(n, m);
        noRanksy = std::max(n, m);
    }
    else
    {
        noRanksx = std::max(n, m);
        noRanksy = std::min(n, m);
    }

    //initialize edge types in order top, bottom, left, right
    std::array<edgetype, 4> edgestype = {GHOST, GHOST, GHOST, GHOST};

    //set position of own process and identify neighboring processes
    int ownPosy = ownRank_ / noRanksx;
    int ownPosx = ownRank_ - ownPosy * noRanksx;
    if (ownPosx - 1 >= 0)
        leftProcess_ = ownRank_ - 1;
    else
    {
        leftProcess_ = noRanks_;
        edgestype[2] = HALO;
    }
    if (ownPosx + 1 < noRanksx)
        rightProcess_ = ownRank_ + 1;
    else
    {
        rightProcess_ = noRanks_;
        edgestype[3] = HALO;
    }
    if (ownPosy - 1 >= 0)
        bottomProcess_ = ownRank_ - noRanksx;
    else
    {
        bottomProcess_ = noRanks_;
        edgestype[1] = HALO;
    }
    if (ownPosy + 1 < noRanksy)
        topProcess_ = ownRank_ + noRanksx;
    else
    {
        topProcess_ = noRanks_;
        edgestype[0] = HALO;
    }

    //get average amount of cells per process in both directions
    int nCellsx = nCellsGlobal_[0] / noRanksx;
    int nCellsy = nCellsGlobal_[1] / noRanksy;

    //increment amount of cells until global amount of cells is matched
    if (nCellsGlobal_[0] % noRanksx > ownPosx)
        nCells_[0] = nCellsx + 1;
    else
        nCells_[0] = nCellsx;
    if (nCellsGlobal_[1] % noRanksy > ownPosy)
        nCells_[1] = nCellsy + 1;
    else
        nCells_[1] = nCellsy;

    //compute physical size
    physicalSize_[0] = physicalSizeGlobal_[0] / nCellsGlobal_[0] * nCells_[0];
    physicalSize_[1] = physicalSizeGlobal_[1] / nCellsGlobal_[1] * nCells_[1];

    //compute node offset
    nodeOffset_[0] = ownPosx * nCellsx + std::min(ownPosx, nCellsGlobal_[0] % noRanksx);
    nodeOffset_[1] = ownPosy * nCellsy + std::min(ownPosy, nCellsGlobal_[1] % noRanksy);

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

//set boundary condition or exchange values of the edges of u, v
void Partitioning::exchange_uv(FieldVariable &u, FieldVariable &v, const Settings &settings) const
{
    //declare array for send requests to be able to wait
    std::vector<MPI_Request> sendRequests;

    //check if (left) neighbor process exists
    if (leftProcess_ != noRanks_)
    {
        //add entry at the end of send request array
        sendRequests.emplace_back();
        //send (left) column of u
        MPI_Isend(u.get_column(1).data(), u.size()[1], MPI_DOUBLE, leftProcess_, 1, MPI_COMM_WORLD, &sendRequests.back());
        //add entry at the end of send request array
        sendRequests.emplace_back();
        //send (left) column of v
        MPI_Isend(v.get_column(1).data(), v.size()[1], MPI_DOUBLE, leftProcess_, 2, MPI_COMM_WORLD, &sendRequests.back());
    }
    //otherwise apply boundary conditions
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
    if (topProcess_ != noRanks_)
    {
        sendRequests.emplace_back();
        MPI_Isend(u.get_row(u.size()[1] - 2).data(), u.size()[0], MPI_DOUBLE, topProcess_, 1, MPI_COMM_WORLD, &sendRequests.back());
        sendRequests.emplace_back();
        MPI_Isend(v.get_row(v.size()[1] - 2).data(), v.size()[0], MPI_DOUBLE, topProcess_, 2, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        u.set_boundary_dirichlet(TOP, settings.dirichletBcTop()[0]);
        v.set_boundary_dirichlet(TOP, settings.dirichletBcTop()[1]);
    }
    if (bottomProcess_ != noRanks_)
    {
        sendRequests.emplace_back();
        MPI_Isend(u.get_row(1).data(), u.size()[0], MPI_DOUBLE, bottomProcess_, 1, MPI_COMM_WORLD, &sendRequests.back());
        sendRequests.emplace_back();
        MPI_Isend(v.get_row(1).data(), v.size()[0], MPI_DOUBLE, bottomProcess_, 2, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        u.set_boundary_dirichlet(BOTTOM, settings.dirichletBcBottom()[0]);
        v.set_boundary_dirichlet(BOTTOM, settings.dirichletBcBottom()[1]);
    }

    //receive all entries of send request array
    set_ghost_uv(u, v);

    //wait for all pending send requests to complete
    MPI_Waitall(sendRequests.size(), sendRequests.data(), MPI_STATUSES_IGNORE);
}

//set values at ghost edges or apply boundary condition of u, v
void Partitioning::set_ghost_uv(Array2D &u, Array2D &v) const
{
    //allocate memory to be able to receive arrays from other process
    std::vector<double> row_u(u.size()[0]);
    std::vector<double> column_u(u.size()[1]);
    std::vector<double> row_v(v.size()[0]);
    std::vector<double> column_v(v.size()[1]);

    //check if (left) neighbor process exists
    if (leftProcess_ != noRanks_)
    {
        //receive column of u of (left) neighbor process
        MPI_Recv(column_u.data(), u.size()[1], MPI_DOUBLE, leftProcess_, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        //assign column to u
        u.set_column(0, column_u);
        //receive column of v of (left) neighbor process
        MPI_Recv(column_v.data(), v.size()[1], MPI_DOUBLE, leftProcess_, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        //asign column to v
        v.set_column(0, column_v);
    }
    if (rightProcess_ != noRanks_)
    {
        MPI_Recv(column_u.data(), u.size()[1], MPI_DOUBLE, rightProcess_, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        u.set_column(u.size()[0] - 1, column_u);
        MPI_Recv(column_v.data(), v.size()[1], MPI_DOUBLE, rightProcess_, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        v.set_column(v.size()[0] - 1, column_v);
    }
    if (topProcess_ != noRanks_)
    {
        MPI_Recv(row_u.data(), u.size()[0], MPI_DOUBLE, topProcess_, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        u.set_row(u.size()[1] - 1, row_u);
        MPI_Recv(row_v.data(), v.size()[0], MPI_DOUBLE, topProcess_, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        v.set_row(v.size()[1] - 1, row_v);
    }
    if (bottomProcess_ != noRanks_)
    {
        MPI_Recv(row_u.data(), u.size()[0], MPI_DOUBLE, bottomProcess_, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        u.set_row(0, row_u);
        MPI_Recv(row_v.data(), v.size()[0], MPI_DOUBLE, bottomProcess_, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        v.set_row(0, row_v);
    }
}

//set boundary condition or exchange values of the edges of f, g
//f is not needed at top& bottom and g is not needed at left& right, since
//corresponding values are not needed for further calculations
void Partitioning::exchange_fg(FieldVariable &f, FieldVariable &g, const FieldVariable &u, const FieldVariable &v) const
{
    //declare array for send requests to be able to wait
    std::vector<MPI_Request> sendRequests;

    //check if (left) neighbor process exists
    if (leftProcess_ != noRanks_)
    {
        //add entry at the end of send request array
        sendRequests.emplace_back();
        //send (left) column of f
        MPI_Isend(f.get_column(1).data(), f.size()[1], MPI_DOUBLE, leftProcess_, 3, MPI_COMM_WORLD, &sendRequests.back());
    }
    //otherwise apply boundary conditions
    else
    {
        f.set_column(0, u.get_column(0));
    }

    if (rightProcess_ != noRanks_)
    {
        sendRequests.emplace_back();
        MPI_Isend(f.get_column(f.size()[0] - 2).data(), f.size()[1], MPI_DOUBLE, rightProcess_, 3, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        f.set_column(f.size()[0] - 1, u.get_column(f.size()[0] - 1));
    }
    if (topProcess_ != noRanks_)
    {
        sendRequests.emplace_back();
        MPI_Isend(g.get_row(g.size()[1] - 2).data(), g.size()[0], MPI_DOUBLE, topProcess_, 4, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        g.set_row(g.size()[1] - 1, v.get_row(g.size()[1] - 1));
    }
    if (bottomProcess_ != noRanks_)
    {
        sendRequests.emplace_back();
        MPI_Isend(g.get_row(1).data(), g.size()[0], MPI_DOUBLE, bottomProcess_, 4, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        g.set_row(0, v.get_row(0));
    }

    //receive all entries of send request array
    set_ghost_fg(f, g);

    //wait for all pending send requests to complete
    MPI_Waitall(sendRequests.size(), sendRequests.data(), MPI_STATUSES_IGNORE);
}

//set values at ghost edges or apply boundary condition of f, g
//f is not needed at top& bottom and g is not needed at left& right, since
//corresponding values are not needed for further calculations
void Partitioning::set_ghost_fg(Array2D &f, Array2D &g) const
{
    //allocate memory to be able to receive arrays from other process
    std::vector<double> row_f(f.size()[0]);
    std::vector<double> row_g(g.size()[0]);
    std::vector<double> column_f(f.size()[1]);
    std::vector<double> column_g(g.size()[1]);

    //check if (left) neighbor process exists
    if (leftProcess_ != noRanks_)
    {
        //receive column of f of (left) neighbor process
        MPI_Recv(column_f.data(), column_f.size(), MPI_DOUBLE, leftProcess_, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        //assign column to f
        f.set_column(0, column_f);
    }
    if (rightProcess_ != noRanks_)
    {
        MPI_Recv(column_f.data(), column_f.size(), MPI_DOUBLE, rightProcess_, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        f.set_column(f.size()[0] - 1, column_f);
    }
    if (topProcess_ != noRanks_)
    {
        MPI_Recv(row_g.data(), row_g.size(), MPI_DOUBLE, topProcess_, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        g.set_row(g.size()[1] - 1, row_g);
    }
    if (bottomProcess_ != noRanks_)
    {
        MPI_Recv(row_g.data(), row_g.size(), MPI_DOUBLE, bottomProcess_, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        g.set_row(0, row_g);
    }
}

//set boundary condition or exchange values of the edges of p
void Partitioning::exchange_p(FieldVariable &p, int startPos) const
{
    //declare array for send requests to be able to wait
    std::vector<MPI_Request> sendRequests;

    //size of sent array
    int size;

    //start for right and top edge (differs from "start")
    int startAdvanced;

    //check if (left) neighbor process exists
    if (leftProcess_ != noRanks_)
    {
        //calculate "size" (in y-direction) of current partition, depending on "red/black"
        size = p.size()[1] / 2 + (1 - startPos) * p.size()[1] % 2;
        //add entry at the end of send request
        sendRequests.emplace_back();
        //send every second value of (left) column of p
        MPI_Isend(p.get_column(1, startPos, 2).data(), size, MPI_DOUBLE, leftProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
    }
    //otherwise apply boundary conditions
    else
    {
        p.set_boundary_neumann(LEFT, 0);
    }

    if (rightProcess_ != noRanks_)
    {
        //calculate if starting postion (of right edge) is "red or black"
        startAdvanced = (startPos + nCells_[0] + 1) % 2;
        size = p.size()[1] / 2 + (1 - startAdvanced) * p.size()[1] % 2;
        sendRequests.emplace_back();
        MPI_Isend(p.get_column(p.size()[0] - 2, startAdvanced, 2).data(), size, MPI_DOUBLE, rightProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        p.set_boundary_neumann(RIGHT, 0);
    }
    if (topProcess_ != noRanks_)
    {
        startAdvanced = (startPos + nCells_[1] + 1) % 2;
        size = p.size()[0] / 2 + (1 - startAdvanced) * p.size()[0] % 2;
        sendRequests.emplace_back();
        MPI_Isend(p.get_row(p.size()[1] - 2, startAdvanced, 2).data(), size, MPI_DOUBLE, topProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        p.set_boundary_neumann(TOP, 0);
    }
    if (bottomProcess_ != noRanks_)
    {
        size = p.size()[0] / 2 + (1 - startPos) * p.size()[0] % 2;
        sendRequests.emplace_back();
        MPI_Isend(p.get_row(1, startPos, 2).data(), size, MPI_DOUBLE, bottomProcess_, 5, MPI_COMM_WORLD, &sendRequests.back());
    }
    else
    {
        p.set_boundary_neumann(BOTTOM, 0);
    }

    //receive all entries of send request array
    set_ghost_p(p, startPos);

    //wait for all pending send requests to complete
    MPI_Waitall(sendRequests.size(), sendRequests.data(), MPI_STATUSES_IGNORE);
}

//set values at ghost edges or apply boundary condition of p
void Partitioning::set_ghost_p(Array2D &p, int startPos) const
{
    //start for right and top edge (differs from "start")
    int startAdvanced;

    //size of sent array
    int size;

    //check if (left) neighbor process exists
    if (leftProcess_ != noRanks_)
    {
        //calculate "size" (in y-direction) of current partition, depending on "red/black"
        size = p.size()[1] / 2 + (1 - (startPos + 1) % 2) * p.size()[1] % 2;
        //allocate memory to be able to receive arrays from other process
        std::vector<double> column(size);
        //receive column of p of (left) neighbor process
        MPI_Recv(column.data(), column.size(), MPI_DOUBLE, leftProcess_, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        //assign column to p
        p.set_column(0, column, (startPos + 1) % 2, 2);
    }
    if (rightProcess_ != noRanks_)
    {
        startAdvanced = (startPos + 1 + nCells_[0] + 1) % 2;
        size = p.size()[1] / 2 + (1 - startAdvanced) * p.size()[1] % 2;
        std::vector<double> column(size);
        MPI_Recv(column.data(), column.size(), MPI_DOUBLE, rightProcess_, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        p.set_column(p.size()[0] - 1, column, startAdvanced, 2);
    }
    if (topProcess_ != noRanks_)
    {
        startAdvanced = (startPos + 1 + nCells_[1] + 1) % 2;
        size = p.size()[0] / 2 + (1 - startAdvanced) * p.size()[0] % 2;
        std::vector<double> row(size);
        MPI_Recv(row.data(), row.size(), MPI_DOUBLE, topProcess_, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        p.set_row(p.size()[1] - 1, row, startAdvanced, 2);
    }
    if (bottomProcess_ != noRanks_)
    {
        size = p.size()[0] / 2 + (1 - (startPos + 1) % 2) * p.size()[0] % 2;
        std::vector<double> row(size);
        MPI_Recv(row.data(), row.size(), MPI_DOUBLE, bottomProcess_, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        p.set_row(0, row, (startPos + 1) % 2, 2);
    }
}