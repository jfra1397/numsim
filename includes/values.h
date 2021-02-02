#pragma once

#include <vector>
#include <array>

//describe position of corresponding variable on grid
enum vposition
{
    VCENTRE,
    VRIGHT,
    VTOP
};

//describe boundary condition type
enum btype
{
    NOTHING,
    DIRICHLET,
    NEUMANN
    
};

//describe celltype
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

//decribe shape of obstacle
enum SHAPE{
    RECTANGLE,
    TRIANGLE,
    ELLIPSE
};


//describe properties of obstacle
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
