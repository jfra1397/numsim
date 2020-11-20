#pragma once

#include "solver.h"

class GaussSeidel : public Solver
{
public:
    //constructor
    GaussSeidel(int maximumNumberOfIterations, double epsilon);

    //solve pressure poisson equation by using GS iterations
    virtual void compute_p(const std::shared_ptr<Discretization> discr);

private:

    //stopping criteria: maximum number of iterations
    int maximumNumberOfIterations_;

    //stopping criteria: error tolerance
    double epsilon_;
};