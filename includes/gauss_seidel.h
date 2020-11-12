#pragma once

#include "solver.h"

class GaussSeidel: public Solver
{
    public:
    GaussSeidel(int maximumNumberOfIterations, double epsilon);
    virtual Array2D compute_p(const std::shared_ptr<Discretization> discr);

    private:
    int maximumNumberOfIterations_;
    double epsilon_;
};