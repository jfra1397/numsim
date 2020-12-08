#include "../includes/staggered_grid.h"

StaggeredGrid::StaggeredGrid(const std::array<int, 2> &size, const std::array<double, 2> &physicalSize, std::array<edgetype, 4> &edgestype) 
        : u_(size, VRIGHT, physicalSize, edgestype), v_(size, VTOP, physicalSize, edgestype), 
          p_(size, VCENTRE, physicalSize, edgestype), f_(size, VRIGHT, physicalSize, edgestype), 
          g_(size, VTOP, physicalSize, edgestype), rhs_(size, VCENTRE, physicalSize, edgestype)
{   
    //pressure uses Neummann boundary conditions
    set_p().set_boundary_type(NEUMANN, NEUMANN, NEUMANN, NEUMANN);

}

// //set boundary values of u and v according to given boundary condition values
// void StaggeredGrid::set_boundary_uv(const std::array<double, 2> &bottomBound, const std::array<double, 2> &rightBound, const std::array<double, 2> &topBound, const std::array<double, 2> &leftBound)
// {
//     set_u().set_boundary_dirichlet(BOTTOM, bottomBound[0]);, rightBound[0], topBound[0], leftBound[0]);
//     set_v().set_boundary(bottomBound[1], rightBound[1], topBound[1], leftBound[1]);
// }

// //set boundary values of F and G equal to u and v
// void StaggeredGrid::set_boundary_fg(const FieldVariable &u, const FieldVariable &v)
// {
//     //calculate maximum indices of u and v in each direction
//     int iumax = u.size()[0], ivmax = v.size()[0], jumax = u.size()[1], jvmax = v.size()[1];
//     int i, j;

//     //set boundary values of F at bottom and top boundary
//     for (i = 0; i < iumax; i++)
//     {
//         set_f(i, 0) = u(i, 0);
//         set_f(i, jumax - 1) = u(i, jumax - 1);
//     }

//     //set boundary values of G at bottom and top boundary
//     for (i = 0; i < ivmax; i++)
//     {
//         set_g(i, 0) = v(i, 0);
//         set_g(i, jvmax - 1) = v(i, jvmax - 1);
//     }

//     //set boundary values of F at left and right boundary
//     for (j = 1; j < jumax - 1; j++)
//     {
//         set_f(0, j) = u(0, j);
//         set_f(iumax - 1, j) = u(iumax - 1, j);
//     }

//     //set boundary values of G at left and right boundary
//     for (j = 0; j < jvmax; j++)
//     {
//         set_g(0, j) = v(0, j);
//         set_g(ivmax - 1, j) = v(ivmax - 1, j);
//     }
// }




int StaggeredGrid::uIBegin() const{}
int StaggeredGrid::uIEnd() const{}
int StaggeredGrid::uJBegin() const{}
int StaggeredGrid::uJEnd() const{}
int StaggeredGrid::vIBegin() const{}
int StaggeredGrid::vIEnd() const{}
int StaggeredGrid::vJBegin() const{}
int StaggeredGrid::vJEnd() const{}
int StaggeredGrid::pIBegin() const{}
int StaggeredGrid::pIEnd() const{}
int StaggeredGrid::pJBegin() const{}
int StaggeredGrid::pJEnd() const{}