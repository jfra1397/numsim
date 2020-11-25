#pragma once

#include "solver.h"


/** This class contains the iterative GS-solver to solve 
 * the pressure-poisson-equation. All other needed methods 
 * to sovler for the other field variables are inherited 
 * from abstract class solver.
 */
class GaussSeidel : public Solver
{
public:
    //constructor
    GaussSeidel(int maximumNumberOfIterations, double epsilon);

    //solve pressure poisson equation by using GS iterations
    virtual void compute_p(const Discretization &discr, FieldVariable &p);

private:

    //stopping criteria: maximum number of iterations
    int maximumNumberOfIterations_;

    //stopping criteria: error tolerance
    double epsilon_;
};