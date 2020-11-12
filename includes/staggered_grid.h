
#pragma once

#include "field_variable.h"


class StaggeredGrid
{
    public:
    StaggeredGrid(std::array<int,2> size);
    
    FieldVariable u;
    FieldVariable v;
    FieldVariable p;
    FieldVariable f;
    FieldVariable g;
    FieldVariable rhs;

    int set_boundery_uv(std::array<double,2> bottomBound, std::array<double,2> rightBound, std::array<double,2> topBound, std::array<double,2> leftBound);
    int set_boundery_fg(std::array<double,2> bottomBound, std::array<double,2> rightBound, std::array<double,2> topBound, std::array<double,2> leftBound);

};