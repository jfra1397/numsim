#include "../includes/solver.h"

//compute timestep dt
double Solver::compute_dt(double tau, double re, double maximumDt, const std::array<double, 2> &meshWidth, const FieldVariable &u, const FieldVariable &v)
{
    //get maximum velocities in each direction
    double umax = u.get_abs_max();
    double vmax = v.get_abs_max();

    //get minimum of timestep possibilities (avoid dividing by zero)
    double temp = re / 2 * meshWidth[0] * meshWidth[0] * meshWidth[1] * meshWidth[1] / (meshWidth[0] * meshWidth[0] + meshWidth[1] * meshWidth[1]);
    double temp_min = std::min(temp, maximumDt);

    if (umax == 0 && vmax == 0)
        return tau * temp_min;
    else if (umax != 0 && vmax == 0)
        return tau * std::min(temp_min, meshWidth[0] / umax);
    else if (umax == 0 && vmax != 0)
        return tau * std::min(temp_min, meshWidth[1] / vmax);
    else
        return tau * std::min(temp_min, std::min(meshWidth[0] / umax, meshWidth[1] / vmax));
}

//compute F
void Solver::compute_f(double re, double gx, double dt, const std::shared_ptr<Discretization> discr)
{
    std::array<int, 2> size = discr->f().size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate F at position (i,j)
            discr->set_f(i, j) = discr->u(i, j) + dt * (1 / re * (discr->computeD2uDx2(i, j) + discr->computeD2uDy2(i, j)) - discr->computeDu2Dx(i, j) - discr->computeDuvDy(i, j) + gx);
        }
    }
}

void Solver::compute_g(double re, double gy, double dt, const std::shared_ptr<Discretization> discr)
{
    std::array<int, 2> size = discr->g().size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate G at position (i,j)
            discr->set_g(i, j) = discr->v(i, j) + dt * (1 / re * (discr->computeD2vDx2(i, j) + discr->computeD2vDy2(i, j)) - discr->computeDv2Dy(i, j) - discr->computeDuvDx(i, j) + gy);
        }
    }
}

void Solver::compute_rhs(double dt, const std::shared_ptr<Discretization> discr)
{
    std::array<int, 2> size = discr->rhs().size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate right hand side at position (i,j)
            discr->set_rhs(i, j) = 1 / dt * (discr->computeDFDx(i, j) + discr->computeDGDy(i, j));
        }
    }
}

//compute velocity u in x direciton
void Solver::compute_u(double dt, const std::shared_ptr<Discretization> discr)
{
    std::array<int, 2> size = discr->u().size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate u at position (i,j)
            discr->set_u(i, j) = discr->f(i, j) - dt * discr->computeDpDx(i, j);
        }
    }
}

//compute velocity v in y direction
void Solver::compute_v(double dt, const std::shared_ptr<Discretization> discr)
{
    std::array<int, 2> size = discr->v().size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate v at position (i,j)
            discr->set_v(i, j) = discr->g(i, j) - dt * discr->computeDpDy(i, j);
        }
    }
}