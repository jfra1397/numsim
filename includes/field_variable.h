#pragma once

#include <fstream>

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
    FieldVariable(const std::array<int,2> size, vposition pos, const std::array<double,2> physicalSize);

    int set_boundary_type(btype top = DIRICHLET, btype bottom = DIRICHLET, btype left = DIRICHLET, btype right = DIRICHLET);
    int set_boundary(double bottomBound, double rightBound, double topBound, double leftBound, double h=0);

    void operator= (const Array2D &data);

    void write_to_file(std::string fileName, std::string name, bool append = false) const;

    double interpolateAt(double x, double y) const;
    


    private:
    FieldVariable();
    bool verticalBoundInterpolate_;
    btype topBoundType_;
    btype bottomBoundType_;
    bool horizontalBoundInterpolate_;
    btype leftBoundType_;
    btype rightBoundType_;
    vposition pos_;
    double meshx_, meshy_;


};






