#pragma once

#include "array2d.h"

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
    using Array2D::Array2D;

    int set_boundary_type(btype top = DIRICHLET, btype bottom = DIRICHLET, btype left = DIRICHLET, btype right = DIRICHLET);
    int set_boundary(bposition pos, double bound, bool interpolate, double h = 0);
    void print() const;
    


    private:
    FieldVariable();
    btype topBound = DIRICHLET;
    btype bottomBound = DIRICHLET;
    btype leftBound = DIRICHLET;
    btype rightBound = DIRICHLET;

};




