#pragma once

#include "field_variable.h"
#include <memory>
#include "discretization.h"


class Solver
{
    public:
    virtual Array2D compute_p(const std::shared_ptr<Discretization> discr) = 0;
    double compute_dt(double tau, double re, double maximumDt, const std::array<double,2> &meshWidth, const FieldVariable &u, const FieldVariable &v);
    Array2D compute_f(double re, double gx, double dt, const std::shared_ptr<Discretization> discretization);
    Array2D compute_g(double re, double gy, double dt, const std::shared_ptr<Discretization> discretization);
    Array2D compute_rhs(double dt, const std::shared_ptr<Discretization> discretization);
    Array2D compute_u(double dt, const std::shared_ptr<Discretization> discretization);
    Array2D compute_v(double dt, const std::shared_ptr<Discretization> discretization);

    private:
    bool comp(double a, double b) 
    { 
        return (a < b); 
    } 

};