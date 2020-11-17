#include <math.h>
#include <iostream>

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
    double factor =  hx * hx * hy * hy / (2.0*(hx * hx + hy * hy));

    while (iter < maximumNumberOfIterations_ &&  norm_res > epsilon_*epsilon_)
    {
        discr->set_p().set_boundary(0,0,0,0);
        norm_res = 0;
        //maybe change i and j, see GS)?!
        for (int j = 1 ; j < size[1] - 1; j++)
        {
            for (int i = 1; i < size[0] - 1; i++)
            {
                temp_res =  discr->computeD2pDx2(i,j) + discr->computeD2pDy2(i,j)-discr->rhs(i,j);
                discr->set_p(i,j) = discr->p(i,j) + (omega_ * factor * temp_res);
                norm_res = norm_res + (temp_res * temp_res);
            }
        }
        
        //nCells of discretization!!!!
        norm_res = norm_res/((discr->nCells()[0]) * (discr->nCells()[1]));
        iter += 1;
    }
    std::cout << iter << std::endl;

    return discr->p();

}