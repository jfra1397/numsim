#pragma once

#include <memory>

#include "field_variable.h"
#include "discretization.h"
#include "settings.h"
#include "output_writer_paraview.h"


/** This class contains functions to compute the field variables
 * after a certain time step. This is an abstract class! 
 */
class Solver
{
public:
    //compute pressure p
    virtual void compute_p(const Discretization &discr, FieldVariable &p) = 0;

    //compute timestep dt
    double compute_dt(double tau, double re, double maximumDt, const std::array<double, 2> &meshWidth, const FieldVariable &u, const FieldVariable &v);

    //compute F
    void compute_f(double re, double gx, double dt, const Discretization &discr, FieldVariable &f);

    //compute G
    void compute_g(double re, double gy, double dt, const Discretization &discr, FieldVariable &g);

    //compute right hand side of pressure poisson equation
    void compute_rhs(double dt, const Discretization &discr, FieldVariable &rhs);

    //compute velocity u in x direciton
    void compute_u(double dt, const Discretization &discr, FieldVariable &u);

    //compute velocity v in y direction
    void compute_v(double dt, const Discretization &discr, FieldVariable &v);

    //solve for velocities u and v
    void solve_uv(const Settings &settings, Discretization &discr, OutputWriterParaview &writer);
};