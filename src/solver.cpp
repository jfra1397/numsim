#include "../includes/solver.h"

//compute timestep dt
double Solver::compute_dt(double tau, double re,double pr, double maximumDt, const std::array<double, 2> &meshWidth, const FieldVariable &u, const FieldVariable &v)
{
    //get maximum velocities in each direction
    double umax = u.get_abs_max();
    double vmax = v.get_abs_max();

    //get minimum of timestep possibilities (avoid dividing by zero)
    double temp = re*pr / 2 * meshWidth[0] * meshWidth[0] * meshWidth[1] * meshWidth[1] / (meshWidth[0] * meshWidth[0] + meshWidth[1] * meshWidth[1]);
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
void Solver::compute_f(double re, double gx, double dt, double beta, const Discretization &discr, FieldVariable &f)
{
    std::array<int, 2> size = f.size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate F at position (i,j)
            if (discr.flag(i, j) != FLUID || discr.flag(i + 1, j) != FLUID)
                continue;
            f(i, j) = discr.u(i, j) + dt * (1 / re * (discr.computeD2uDx2(i, j) + discr.computeD2uDy2(i, j)) - discr.computeDu2Dx(i, j) - discr.computeDuvDy(i, j) + gx * (1 - beta * discr.T(i, j)));
        }
    }
}

void Solver::compute_g(double re, double gy, double dt, double beta, const Discretization &discr, FieldVariable &g)
{
    std::array<int, 2> size = g.size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate G at position (i,j)
            if (discr.flag(i, j) != FLUID || discr.flag(i, j + 1) != FLUID)
                continue;
            g(i, j) = discr.v(i, j) + dt * (1 / re * (discr.computeD2vDx2(i, j) + discr.computeD2vDy2(i, j)) - discr.computeDv2Dy(i, j) - discr.computeDuvDx(i, j) + gy * (1 - beta * discr.T(i, j)));
        }
    }
}

void Solver::compute_rhs(double dt, const Discretization &discr, FieldVariable &rhs)
{
    std::array<int, 2> size = rhs.size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate right hand side at position (i,j)
            if (discr.flag(i, j) != FLUID)
                continue;
            rhs(i, j) = 1 / dt * (discr.computeDFDx(i, j) + discr.computeDGDy(i, j));
        }
    }
}

//compute T
void Solver::compute_T(double re, double pr, double q, double dt, const Discretization &discr, FieldVariable &T)
{
    std::array<int, 2> size = T.size();

    Array2D<double> tempT(size);

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate F at position (i,j)
            if (discr.flag(i, j) != FLUID)
                continue;
            tempT(i, j) = discr.T(i, j) + dt * (1 / (re * pr) * (discr.computeD2TDx2(i, j) + discr.computeD2TDy2(i, j)) - discr.computeDuTDx(i, j) - discr.computeDvTDy(i, j) + q);
        }
    }

    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            T(i, j) = tempT(i, j);
        }
    }
}

//compute velocity u in x direciton
void Solver::compute_u(double dt, const Discretization &discr, FieldVariable &u)
{
    std::array<int, 2> size = u.size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate u at position (i,j)
            if (discr.flag(i, j) != FLUID || discr.flag(i + 1, j) != FLUID)
                continue;
            u(i, j) = discr.f(i, j) - dt * discr.computeDpDx(i, j);
        }
    }
}

//compute velocity v in y direction
void Solver::compute_v(double dt, const Discretization &discr, FieldVariable &v)
{
    std::array<int, 2> size = v.size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate v at position (i,j)
            if (discr.flag(i, j) != FLUID || discr.flag(i, j + 1) != FLUID)
                continue;
            v(i, j) = discr.g(i, j) - dt * discr.computeDpDy(i, j);
        }
    }
}

void Solver::solve_uv(const Settings &settings, Discretization &discr, OutputWriterParaview &writer, bool feedback)
{

    //initialize time
    double t = 0;
    int fileNo = 0;
    double dt;
    double res;

    //writer.writeFile(t);
    //return;

    //set boundary condition values of u,v
    discr.set_boundary_uvfg();
    discr.set_boundary_T(discr.set_T());
    //return;

    //iterate until given endtime in settings is reached
    while (t < settings.endTime())
    {
        //compute time step
        dt = compute_dt(settings.tau(), settings.re(),settings.pr(), settings.maximumDt(), discr.meshWidth(), discr.u(), discr.v());

        //set timestep s.t. given endtime is not exceeded
        //set time step s.t. given endtime is not exceeded
        if (t + dt > settings.endTime())
            dt = settings.endTime() - t;
        else if (int(t + dt) - t > 0)
            dt = int(t + dt) - t;
        else if(ceil(t+dt)-(t+dt)<0.0001)
            dt =ceil(t+dt)-t;

        //compute T
        compute_T(settings.re(), settings.pr(), settings.q(), dt, discr, discr.set_T());
        discr.set_boundary_T(discr.set_T());


        // compute f,g
        compute_f(settings.re(), settings.g()[0], dt, settings.beta(), discr, discr.set_f());
        compute_g(settings.re(), settings.g()[1], dt, settings.beta(), discr, discr.set_g());

        //set boundary values of f,g to boundary values of u,v
        //discr.set_boundary_fg(discr.u(), discr.v());

        //compute right hand side and pressure (with given pressure solver)
        compute_rhs(dt, discr, discr.set_rhs());
        res = compute_p(discr, discr.set_p());

        //compute new u,v
        compute_u(dt, discr, discr.set_u());
        compute_v(dt, discr, discr.set_v());

        //set new boundary values s.t. boundary conditions are met
        discr.set_boundary_uvfg();

        //increment actual time by time step
        t += dt;

        //write results to output files
        //if (int(t) == t)
        //{
        writer.writeFile(t);
        discr.write_to_file(fileNo++, t);
        //}
        if (feedback) std::cout << "time:\t" << t <<"\tres:\t" << res << std::endl;


    }
}