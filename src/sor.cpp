#include <math.h>
#include <mpi.h>

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

void SOR::compute_p(const Discretization &discr, FieldVariable &p, const Partitioning &partition)
{
    std::array<int,2> size = p.size();

    //initialize residuum and iteration counter
    double temp_res, norm_res;
    int iter = 0;

    //set meshwidth in each direction
    double hx = discr.dx();
    double hy = discr.dy();

    //calculate prefactor
    double factor =  hx * hx * hy * hy / (2.0*(hx * hx + hy * hy));

    //SOR algorithm
    do
    {
        //adjust boundary values for p
        partition.exchange_p(p);

        //reset residuum norm
        norm_res = 0;

        //SOR iteration over whole matrix
        for (int i = 1 ; i < size[0] - 1; i++)
        {
            for (int j = 1; j < size[1] - 1; j++)
            {   
                //calculate residuum at position (i,j)
                temp_res =  discr.computeD2pDx2(i,j) + discr.computeD2pDy2(i,j)-discr.rhs(i,j);

                //calculate new p at position (i,j)
                p(i,j) = discr.p(i,j) + (omega_ * factor * temp_res);

                //update residuum norm
                norm_res = norm_res + (temp_res * temp_res);
            }
        }
        
        //finish calculation of residuum
        norm_res = norm_res/((discr.nCells()[0]) * (discr.nCells()[1]));
        MPI_Allreduce( &norm_res, &norm_res, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

        //next iteration
        iter += 1;
    }
    //check if stopping criteria achieved (error tolerance, maximum number of iterations)
    while (iter < maximumNumberOfIterations_ &&  norm_res > epsilon_*epsilon_);

    //set correct boundary values (safety first)
    partition.exchange_p(p);

}