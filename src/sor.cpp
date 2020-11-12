#include <math.h>

#include "../includes/sor.h"

SOR::SOR(int maximumNumberOfIterations, double epsilon, double omega)
{
    maximumNumberOfIterations_ = maximumNumberOfIterations;
    epsilon_ = epsilon;
    omega_ = omega;
}

Array2D SOR::compute_p(const std::shared_ptr<Discretization> discr)
{
    std::array<int,2> size = discr->p().size();
    Array2D temp_p(size);
    temp_p = discr->p();
    double temp_res, norm_res = 2*epsilon_;
    int iter = 0;
    double hx = discr->meshWidth()[0];
    double hy = discr->meshWidth()[1];

    double debug1, debg2, debug3;

    while (iter < maximumNumberOfIterations_ &&  norm_res > epsilon_)
    {
        norm_res = 0;
        for (int i = 1; i < size[0] - 1; i++)
        {
            for (int j = 1; j < size[1] - 1; j++)
            {
                debug1 = discr->rhs(i,j);
                debg2 = discr->computeD2pDx2(i,j);
                debug3 =  discr->computeD2pDy2(i,j);

                temp_res = discr->rhs(i,j) - discr->computeD2pDx2(i,j) - discr->computeD2pDy2(i,j);
                temp_p(i,j) = temp_p(i,j) - omega_/2 * hx * hx * hy * hy / (hx * hx + hy * hy) * temp_res;
                norm_res += temp_res * temp_res;
            }
        }
        norm_res = sqrt(norm_res/((size[0] - 2) * (size[1] - 2)));
        iter += 1;

    }

    return temp_p;

}