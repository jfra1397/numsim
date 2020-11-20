#pragma once

#include "solver.h"

class SOR : public Solver
{
public:
    //constructor
    SOR(int maximumNumberOfIterations, double epsilon, double omega);

    //solve pressure poisson equation by using SOR iterations
    virtual void compute_p(const std::shared_ptr<Discretization> discr);

private:
    //stopping criteria: maximum number of iterations
    int maximumNumberOfIterations_;

    //stopping criteria: error tolerance
    double epsilon_;

    //overrelaxation factor
    double omega_;
};