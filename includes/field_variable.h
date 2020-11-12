#pragma once

#include "array2d.h"

enum vposition
{
    VCENTRE,
    VRIGHT,
    VTOP
};

enum btype
{
    DIRICHLET,
    NEUMANN
};

class FieldVariable: public Array2D
{
    public:
    FieldVariable(const std::array<int,2> size, vposition pos);

    int set_boundary_type(btype top = DIRICHLET, btype bottom = DIRICHLET, btype left = DIRICHLET, btype right = DIRICHLET);
    int set_boundary(double bottomBound, double rightBound, double topBound, double leftBound, double h=0);
    


    private:
    FieldVariable();
    bool verticalBoundInterpolate;
    btype topBoundType = DIRICHLET;
    btype bottomBoundType = DIRICHLET;
    bool horizontalBoundInterpolate;
    btype leftBoundType = DIRICHLET;
    btype rightBoundType = DIRICHLET;

};





