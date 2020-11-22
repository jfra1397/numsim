#pragma once

#include "field_variable.h"
#include <memory>
#include "discretization.h"

class Solver
{
public:
    //compute pressure p
    virtual void compute_p(const std::shared_ptr<Discretization> discr) = 0;

    //compute timestep dt
    double compute_dt(double tau, double re, double maximumDt, const std::array<double, 2> &meshWidth, const FieldVariable &u, const FieldVariable &v);

    //compute F
    void compute_f(double re, double gx, double dt, const std::shared_ptr<Discretization> discr);

    //compute G
    void compute_g(double re, double gy, double dt, const std::shared_ptr<Discretization> discr);

    //compute right hand side of pressure poisson equation
    void compute_rhs(double dt, const std::shared_ptr<Discretization> discr);

    //compute velocity u in x direciton
    void compute_u(double dt, const std::shared_ptr<Discretization> discr);

    //compute velocity v in y direction
    void compute_v(double dt, const std::shared_ptr<Discretization> discr);
};