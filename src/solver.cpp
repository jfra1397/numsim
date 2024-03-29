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
void Solver::compute_f(double re, double gx, double dt, const Discretization &discr, FieldVariable &f)
{
    std::array<int, 2> size = f.size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate F at position (i,j)
            f(i, j) = discr.u(i, j) + dt * (1 / re * (discr.computeD2uDx2(i, j) + discr.computeD2uDy2(i, j)) - discr.computeDu2Dx(i, j) - discr.computeDuvDy(i, j) + gx);
        }
    }
}

//compute G
void Solver::compute_g(double re, double gy, double dt, const Discretization &discr, FieldVariable &g)
{
    std::array<int, 2> size = g.size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate G at position (i,j)
            g(i, j) = discr.v(i, j) + dt * (1 / re * (discr.computeD2vDx2(i, j) + discr.computeD2vDy2(i, j)) - discr.computeDv2Dy(i, j) - discr.computeDuvDx(i, j) + gy);
        }
    }
}

//compute right hand side
void Solver::compute_rhs(double dt, const Discretization &discr, FieldVariable &rhs)
{
    std::array<int, 2> size = rhs.size();

    //iterate over whole matrix
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            //calculate right hand side at position (i,j)
            rhs(i, j) = 1 / dt * (discr.computeDFDx(i, j) + discr.computeDGDy(i, j));
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
            v(i, j) = discr.g(i, j) - dt * discr.computeDpDy(i, j);
        }
    }
}

//solve for velocities u and v
void Solver::solve_uv(const Settings &settings, Discretization &discr, const Partitioning &partitioning, OutputWriterParaviewParallel &writer)
{
    //initialize time
    double t = 0;
    //int fileNo = 0;
    double dt;

    //set boundary condition or exchange values of the edges of u, v
    partitioning.exchange_uv(discr.set_u(), discr.set_v(), settings);

    //iterate until given endtime in settings is reached
    while (t < settings.endTime())
    {
        //compute timestep
        dt = compute_dt(settings.tau(), settings.re(), settings.maximumDt(), discr.meshWidth(), discr.u(), discr.v());
        //communicate with other process to get minimum time step
        dt = partitioning.get_time(dt);

        //set timestep s.t. given endtime is not exceeded
        if (t + dt > settings.endTime())
            dt = settings.endTime() - t;
        
        //set time step s.t. integer timesteps are matched
        else if (int(t + dt) - t > 0){
            dt = int(t + dt) - t;
        }

        // compute F, G
        compute_f(settings.re(), settings.g()[0], dt, discr, discr.set_f());
        compute_g(settings.re(), settings.g()[1], dt, discr, discr.set_g());

        //set boundary condition or exchange values of the edges of f, g
        partitioning.exchange_fg(discr.set_f(), discr.set_g(), discr.u(), discr.v());

        
        //compute right hand side and pressure (with given pressure solver)
        compute_rhs(dt, discr, discr.set_rhs());
        compute_p(discr, discr.set_p(), partitioning);

        //compute new u,v
        compute_u(dt, discr, discr.set_u());
        compute_v(dt, discr, discr.set_v());

        //set boundary condition or exchange values of the edges of u, v
        partitioning.exchange_uv(discr.set_u(), discr.set_v(), settings);

        //increment actual time by time step
        t += dt;

        //write results to output files
        if ((int) t == t) 
        {
            writer.writeFile(t);
            //discr.write_to_file(fileNo++, t, partitioning.ownRankNo());
        }
    }

}