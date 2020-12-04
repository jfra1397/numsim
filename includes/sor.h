#pragma once

#include "solver.h"


/** This class contains the iterative SOR-solver to solve 
 * the pressure-poisson-equation. All other needed methods 
 * to sovler for the other field variables are inherited 
 * from abstract class solver.
 */
class SOR : public Solver
{
public:
    //constructor
    SOR(int maximumNumberOfIterations, double epsilon, double omega);

    //solve pressure poisson equation by using SOR iterations
    virtual void compute_p(const Discretization &discr, FieldVariable &p, const Partitioning &partition);

private:
    //stopping criteria: maximum number of iterations
    int maximumNumberOfIterations_;

    //stopping criteria: error tolerance
    double epsilon_;

    //overrelaxation factor
    double omega_;
};