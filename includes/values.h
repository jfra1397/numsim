#pragma once

#include <vector>
#include <array>

//describe boundary condition type
enum btype
{
    DIRICHLET,
    NEUMANN,
    NOTHING
};

enum CELLTYPE
{
    FLUID,
    EMPTY,
    OBJLEFT,
    OBJRIGHT,
    OBJTOP,
    OBJBOTTOM,
    OBJTOPLEFT,
    OBJTOPRIGHT,
    OBJBOTTOMLEFT,
    OBJBOTTOMRIGHT,
    LEFTBOUND,
    RIGHTBOUND,
    TOPBOUND,
    BOTTOMBOUND
};

enum SHAPE{
    RECTANGLE,
    TRIANGLE,
    ELLIPSE
};


struct Obstacle
{
    SHAPE shape;
    std::vector<double> position;
    btype velType = DIRICHLET;
    btype pType = NEUMANN;
    std::array<double,2> velValue = {0,0};
    double pValue = 0;
    CELLTYPE type = EMPTY;
    btype tType = NEUMANN;
    double tValue = 0;
};