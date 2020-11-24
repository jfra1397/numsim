#include "../includes/staggered_grid.h"

StaggeredGrid::StaggeredGrid(const std::array<int, 2> size, const std::array<double, 2> physicalSize) : u_(size, VRIGHT, physicalSize), v_(size, VTOP, physicalSize), p_(size, VCENTRE, physicalSize), f_(size, VRIGHT, physicalSize), g_(size, VTOP, physicalSize), rhs_(size, VCENTRE, physicalSize)
{   
    //pressure uses Neummann boundary conditions
    set_p().set_boundary_type(NEUMANN, NEUMANN, NEUMANN, NEUMANN);

}

//set boundary values of u and v according to given boundary condition values
void StaggeredGrid::set_boundary_uv(const std::array<double, 2> bottomBound, const std::array<double, 2> rightBound, const std::array<double, 2> topBound, const std::array<double, 2> leftBound)
{
    set_u().set_boundary(bottomBound[0], rightBound[0], topBound[0], leftBound[0]);
    set_v().set_boundary(bottomBound[1], rightBound[1], topBound[1], leftBound[1]);
}

//set boundary values of F and G equal to u and v
void StaggeredGrid::set_boundary_fg(const FieldVariable u, const FieldVariable v)
{
    //calculate maximum indices of u and v in each direction
    int iumax = u.size()[0], ivmax = v.size()[0], jumax = u.size()[1], jvmax = v.size()[1];
    int i, j;

    //set boundary values of F at bottom and top boundary
    for (i = 0; i < iumax; i++)
    {
        set_f(i, 0) = u(i, 0);
        set_f(i, jumax - 1) = u(i, jumax - 1);
    }

    //set boundary values of G at bottom and top boundary
    for (i = 0; i < ivmax; i++)
    {
        set_g(i, 0) = v(i, 0);
        set_g(i, jvmax - 1) = v(i, jvmax - 1);
    }

    //set boundary values of F at left and right boundary
    for (j = 1; j < jumax - 1; j++)
    {
        set_f(0, j) = u(0, j);
        set_f(iumax - 1, j) = u(iumax - 1, j);
    }

    //set boundary values of G at left and right boundary
    for (j = 0; j < jvmax; j++)
    {
        set_g(0, j) = v(0, j);
        set_g(ivmax - 1, j) = v(ivmax - 1, j);
    }
}

//get the whole field variable, declared const, i.e. it is not possible to change it
const FieldVariable &StaggeredGrid::u() const { return u_; }
const FieldVariable &StaggeredGrid::v() const { return v_; }
const FieldVariable &StaggeredGrid::p() const { return p_; }
const FieldVariable &StaggeredGrid::f() const { return f_; }
const FieldVariable &StaggeredGrid::g() const { return g_; }
const FieldVariable &StaggeredGrid::rhs() const { return rhs_; }

//get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
double StaggeredGrid::u(int i, int j) const { return u_(i, j); }
double StaggeredGrid::v(int i, int j) const { return v_(i, j); }
double StaggeredGrid::p(int i, int j) const { return p_(i, j); }
double StaggeredGrid::f(int i, int j) const { return f_(i, j); }
double StaggeredGrid::g(int i, int j) const { return g_(i, j); }
double StaggeredGrid::rhs(int i, int j) const { return rhs_(i, j); }

//access the field variable, declared not const, i.e. the values can be changed
FieldVariable &StaggeredGrid::set_u() { return u_; }
FieldVariable &StaggeredGrid::set_v() { return v_; }
FieldVariable &StaggeredGrid::set_p() { return p_; }
FieldVariable &StaggeredGrid::set_f() { return f_; }
FieldVariable &StaggeredGrid::set_g() { return g_; }
FieldVariable &StaggeredGrid::set_rhs() { return rhs_; }

//access the value at coordinate (i,j), declared not const, i.e. the value can be changed
double &StaggeredGrid::set_u(int i, int j) { return u_(i, j); }
double &StaggeredGrid::set_v(int i, int j) { return v_(i, j); }
double &StaggeredGrid::set_p(int i, int j) { return p_(i, j); }
double &StaggeredGrid::set_f(int i, int j) { return f_(i, j); }
double &StaggeredGrid::set_g(int i, int j) { return g_(i, j); }
double &StaggeredGrid::set_rhs(int i, int j) { return rhs_(i, j); }
