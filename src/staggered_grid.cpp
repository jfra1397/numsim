#include "../includes/staggered_grid.h"


StaggeredGrid::StaggeredGrid(std::array<int,2> size):
u(size, VRIGHT), v(size, VTOP), p(size, VCENTRE), f(size, VRIGHT), g(size, VTOP), rhs(size, VCENTRE)
{}


int StaggeredGrid::set_boundery_uv(std::array<double,2> bottomBound, std::array<double,2> rightBound, std::array<double,2> topBound, std::array<double,2> leftBound)
{
    u.set_boundary(bottomBound[0], rightBound[0], topBound[0], leftBound[0]);
    v.set_boundary(bottomBound[1], rightBound[1], topBound[1], leftBound[1]);

}

int StaggeredGrid::set_boundery_fg(std::array<double,2> bottomBound, std::array<double,2> rightBound, std::array<double,2> topBound, std::array<double,2> leftBound)
{
    f.set_boundary(bottomBound[0], rightBound[0], topBound[0], leftBound[0]);
    g.set_boundary(bottomBound[1], rightBound[1], topBound[1], leftBound[1]);

}