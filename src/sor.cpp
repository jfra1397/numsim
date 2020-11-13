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
    //Array2D temp_p(size);
    //temp_p = discr->p();
    double temp_res, norm_res = 2*epsilon_*epsilon_;
    int iter = 0;
    double hx = discr->meshWidth()[0];
    double hy = discr->meshWidth()[1];

    while (iter < maximumNumberOfIterations_ &&  norm_res > epsilon_*epsilon_)
    {
        norm_res = 0;
        for (int i = 1; i < size[0] - 1; i++)
        {
            for (int j = 1; j < size[1] - 1; j++)
            {
                temp_res = omega_ * (discr->rhs(i,j) - discr->computeD2pDx2(i,j) - discr->computeD2pDy2(i,j)) * hx * hx * hy * hy / (2*(hx * hx + hy * hy));
                discr->set_p(i,j) = discr->p(i,j) - temp_res;
                norm_res += temp_res * temp_res;
            }
        }
        norm_res = norm_res/((size[0] - 2) * (size[1] - 2));
        iter += 1;

    }

    return discr->p();

}