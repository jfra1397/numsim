#include <math.h>

#include "../includes/gauss_seidel.h"

GaussSeidel::GaussSeidel(int maximumNumberOfIterations, double epsilon)
{
    //set stopping criteria: maximum number of iterations
    maximumNumberOfIterations_ = maximumNumberOfIterations;

    //set stopping criteria: error tolerance
    epsilon_ = epsilon;
}

void GaussSeidel::compute_p(const std::shared_ptr<Discretization> discr)
{
    std::array<int, 2> size = discr->p().size();

    //initialize residuum and iteration counter
    double temp_res, norm_res;
    int iter = 0;

    //set meshwidth in each direction
    double hx = discr->meshWidth()[0];
    double hy = discr->meshWidth()[1];

    //calculate prefactor
    double factor = hx * hx * hy * hy / (2.0 * (hx * hx + hy * hy));

    //GS algorithm
    do
    {
        //adjust boundary values for p
        discr->set_p().set_boundary(0, 0, 0, 0);

        //reset residuum norm
        norm_res = 0;

        //GS iteration over whole matrix
        for (int i = 1; i < size[0] - 1; i++)
        {
            for (int j = 1; j < size[1] - 1; j++)
            {
                //calculate residuum at position (i,j)
                temp_res = discr->computeD2pDx2(i, j) + discr->computeD2pDy2(i, j) - discr->rhs(i, j);

                //calculate new p at position (i,j)
                discr->set_p(i, j) = discr->p(i, j) + (factor * temp_res);

                //update residuum norm
                norm_res = norm_res + (temp_res * temp_res);
            }
        }

        //finish calculation of residuum
        norm_res = norm_res / ((discr->nCells()[0]) * (discr->nCells()[1]));

        //next iteration
        iter += 1;

    }
    //check if stopping criteria achieved (error tolerance, maximum number of iterations)
    while (iter < maximumNumberOfIterations_ && norm_res > epsilon_ * epsilon_);

    //set correct boundary values (safety first)
    discr->set_p().set_boundary(0,0,0,0);

}