#pragma once

#include "solver.h"

class SOR: public Solver
{
    public:
    SOR(int maximumNumberOfIterations, double epsilon, double omega);
    virtual Array2D compute_p(const std::shared_ptr<Discretization> discr);

    private:
    int maximumNumberOfIterations_;
    double epsilon_;
    double omega_;
};