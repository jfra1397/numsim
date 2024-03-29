#include <math.h>

#include "../includes/sor.h"

SOR::SOR(int maximumNumberOfIterations, double epsilon, double omega)
{
    //set stopping criteria: maximum number of iterations
    maximumNumberOfIterations_ = maximumNumberOfIterations;

    //set stopping criteria: error tolerance
    epsilon_ = epsilon;

    //set overrelaxation factor
    omega_ = omega;
}

//solve pressure poisson equation by using SOR iterations
void SOR::compute_p(const Discretization &discr, FieldVariable &p, const Partitioning &partition)
{
    std::array<int, 2> size = p.size();

    int start = (partition.nodeOffset()[0] + partition.nodeOffset()[1]) % 2;
    //initialize residuum and iteration counter
    double temp_res, norm_res;
    int iter = 0;

    //set meshwidth in each direction
    double hx = discr.dx();
    double hy = discr.dy();

    //calculate prefactor
    double factor = hx * hx * hy * hy / (2.0 * (hx * hx + hy * hy));

    //SOR algorithm
    do
    {
        //reset residuum norm
        norm_res = 0;
        int jstart = start;
        //SOR iteration over "red" part of matrix
        for (int i = 1; i < size[0] - 1; i++)
        {
            for (int j = jstart % 2 + 1; j < size[1] - 1; j += 2)
            {
                //calculate residuum at position (i,j)
                temp_res = discr.computeD2pDx2(i, j) + discr.computeD2pDy2(i, j) - discr.rhs(i, j);

                //calculate new p at position (i,j)
                p(i, j) = discr.p(i, j) + (omega_ * factor * temp_res);

                //update residuum norm
                norm_res = norm_res + (temp_res * temp_res);
            }
            jstart++;
        }

        //exchange edge values of pressure
        partition.exchange_p(p, (start + 1) % 2);

        jstart = start + 1;

        //SOR iteration over "black" part of matrix
        for (int i = 1; i < size[0] - 1; i++)
        {
            for (int j = jstart % 2 + 1; j < size[1] - 1; j += 2)
            {
                //calculate residuum at position (i,j)
                temp_res = discr.computeD2pDx2(i, j) + discr.computeD2pDy2(i, j) - discr.rhs(i, j);

                //calculate new p at position (i,j)
                p(i, j) = discr.p(i, j) + (omega_ * factor * temp_res);

                //update residuum norm
                norm_res = norm_res + (temp_res * temp_res);
            }
            jstart++;
        }

        //exchange edge values of pressure
        partition.exchange_p(p, start);

        //finish calculation of residuum
        MPI_Allreduce(&norm_res, &norm_res, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
        norm_res = norm_res / ((partition.nCellsGlobal()[0]) * (partition.nCellsGlobal()[1]));

        //next iteration
        iter += 1;
    }
    //check if stopping criteria achieved (error tolerance, maximum number of iterations)
    while (iter < maximumNumberOfIterations_ && norm_res > epsilon_ * epsilon_);
}