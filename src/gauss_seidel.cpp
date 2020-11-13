#include <math.h>

#include "../includes/gauss_seidel.h"

GaussSeidel::GaussSeidel(int maximumNumberOfIterations, double epsilon)
{
    maximumNumberOfIterations_ = maximumNumberOfIterations;
    epsilon_ = epsilon;
}

Array2D GaussSeidel::compute_p(const std::shared_ptr<Discretization> discr)
{
    std::array<int,2> size = discr->p().size();
    //Array2D temp_p(size);
    //temp_p = discr->p();
    double temp_res, norm_res = 2*epsilon_;
    int iter = 0;
    double hx = discr->meshWidth()[0];
    double hy = discr->meshWidth()[1];

    while (iter < maximumNumberOfIterations_ &&  norm_res < epsilon_)
    {
        norm_res = 0;
        for (int i = 1; i < size[0] - 1; i++)
        {
            for (int j = 1; j < size[1] - 1; j++)
            {

                temp_res = discr->rhs(i,j) - discr->computeD2pDx2(i,j) - discr->computeD2pDy2(i,j);
                discr->set_p(i,j) = discr->p(i,j) - 1/2 * hx * hx * hy * hy / (hx * hx + hy * hy) * temp_res;
                norm_res += temp_res * temp_res;
            }
        }
        norm_res = sqrt(norm_res/((size[0] - 2) * (size[1] - 2)));
        iter += 1;

    }

    return discr->p();

}