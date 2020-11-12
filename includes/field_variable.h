#pragma once

#include "array2d.h"

enum vposition
{
    VCENTRE,
    VRIGHT,
    VTOP
};

enum bposition
{
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
};

enum btype
{
    DIRICHLET,
    NEUMANN
};

class FieldVariable: public Array2D
{
    public:
    FieldVariable(std::array<int,2> size, vposition pos);

    int set_boundary_type(btype top = DIRICHLET, btype bottom = DIRICHLET, btype left = DIRICHLET, btype right = DIRICHLET);
    int set_boundary(double bottomBound, double rightBound, double topBound, double leftBound, double h=0);
    void print() const;
    


    private:
    FieldVariable();
    bool verticalBoundInterpolate;
    btype topBoundType = DIRICHLET;
    btype bottomBoundType = DIRICHLET;
    bool horizontalBoundInterpolate;
    btype leftBoundType = DIRICHLET;
    btype rightBoundType = DIRICHLET;

};


// AllFieldVariables variables

// u.setboundary()
// v.setboundary()

// Discretization dis;

// f = solver.compute_f(variables.u, variables.v)
// g = .....

// rhs = solver.compute(.....)

// solver.iter_solve(.....,result, epsilon)

// solver.compute(...)


// output()






