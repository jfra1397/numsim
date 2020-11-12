#include "../includes/solver.h"


double Solver::compute_dt(double tau, double re, double maximumDt, const std::array<double,2> &meshWidth, const FieldVariable &u, const FieldVariable &v)
{
    double umax = u.get_abs_max();
    double vmax = v.get_abs_max();
    double temp = re/2 * meshWidth[0]*meshWidth[0] * meshWidth[1] * meshWidth[1] / (meshWidth[0]*meshWidth[0] + meshWidth[1]*meshWidth[1]);
    double temp_min = std::min(temp, maximumDt);

    if (umax == 0 && vmax == 0) return tau * temp_min;
    else if (umax != 0 && vmax == 0) return tau * std::min(temp_min, meshWidth[0]/umax);
    else if (umax == 0 && vmax != 0) return tau * std::min(temp_min, meshWidth[1]/vmax);
    else return tau * std::min(temp_min, std::min(meshWidth[0]/umax, meshWidth[1]/vmax));

}

Array2D Solver::compute_f(double re, double gx, double dt, const std::shared_ptr<Discretization> discr)
{
    std::array<int,2> size = discr->f().size();
    Array2D result(size);
    result = discr->f();
    for (int i=1; i < size[0] - 1; i++)
    {
        for (int j=1; j < size[1] - 1; j++)
        {
            result(i,j) = discr->u(i,j) + dt * (1/re * (discr->computeD2uDx2(i,j) + discr->computeD2uDy2(i,j)) - discr->computeDu2Dx(i,j) - discr->computeDuvDy(i,j) +gx);

        }
    }

    return result;
    
}

Array2D Solver::compute_g(double re, double gy, double dt, const std::shared_ptr<Discretization> discr)
{
    std::array<int,2> size = discr->g().size();
    Array2D result(size);
    result = discr->g();
    for (int i=1; i < size[0] - 1; i++)
    {
        for (int j=1; j < size[1] - 1; j++)
        {
            result(i,j) = discr->v(i,j) + dt * (1/re * (discr->computeD2vDx2(i,j) + discr->computeD2vDy2(i,j)) - discr->computeDv2Dy(i,j) - discr->computeDuvDx(i,j) +gy);

        }
    }

    return result;
    
}

Array2D Solver::compute_rhs(double dt, const std::shared_ptr<Discretization> discr)
{
    std::array<int,2> size = discr->rhs().size();
    Array2D result(size);
    for (int i=1; i < size[0] - 1; i++)
    {
        for (int j=1; j < size[1] - 1; j++)
        {
            result(i,j) = 1/dt * (discr->computeDFDx(i,j) + discr->computeDGDy(i,j));

        }
    }

    return result;
    
}

Array2D Solver::compute_u(double dt, const std::shared_ptr<Discretization> discr)
{
    std::array<int,2> size = discr->u().size();
    Array2D result(size);
    result = discr->u();
    for (int i=1; i < size[0] - 1; i++)
    {
        for (int j=1; j < size[1] - 1; j++)
        {
            result(i,j) = discr->f(i,j) - dt * discr->computeDpDx(i,j);

        }
    }

    return result;
    
}

Array2D Solver::compute_v(double dt, const std::shared_ptr<Discretization> discr)
{
    std::array<int,2> size = discr->v().size();
    Array2D result(size);
    result = discr->v();
    for (int i=1; i < size[0] - 1; i++)
    {
        for (int j=1; j < size[1] - 1; j++)
        {
            result(i,j) = discr->g(i,j) - dt * discr->computeDpDy(i,j);

        }
    }

    return result;
    
}