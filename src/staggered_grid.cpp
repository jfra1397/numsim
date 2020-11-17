#include "../includes/staggered_grid.h"


StaggeredGrid::StaggeredGrid(const std::array<int,2> size,const std::array<int,2> physicalSize)):
u_(size, VRIGHT, physicalSize), v_(size, VTOP, physicalSize), p_(size, VCENTRE, physicalSize), f_(size, VRIGHT, physicalSize), g_(size, VTOP, physicalSize), rhs_(size, VCENTRE, physicalSize)
{}


void StaggeredGrid::set_boundary_uv(const std::array<double,2> bottomBound, const std::array<double,2> rightBound, const std::array<double,2> topBound, const std::array<double,2> leftBound)
{
    set_u().set_boundary(bottomBound[0], rightBound[0], topBound[0], leftBound[0]);
    set_v().set_boundary(bottomBound[1], rightBound[1], topBound[1], leftBound[1]);

}

void StaggeredGrid::set_boundary_fg(const std::array<double,2> bottomBound, const std::array<double,2> rightBound, const std::array<double,2> topBound, const std::array<double,2> leftBound)
{
    set_f().set_boundary(bottomBound[0], rightBound[0], topBound[0], leftBound[0]);
    set_g().set_boundary(bottomBound[1], rightBound[1], topBound[1], leftBound[1]);

}


const FieldVariable & StaggeredGrid::u() const {return u_;}
const FieldVariable & StaggeredGrid::v() const {return v_;}
const FieldVariable & StaggeredGrid::p() const {return p_;}
const FieldVariable & StaggeredGrid::f() const {return f_;}
const FieldVariable & StaggeredGrid::g() const {return g_;}
const FieldVariable & StaggeredGrid::rhs() const {return rhs_;}

double StaggeredGrid::u(int i, int j) const {return u_(i,j);}
double StaggeredGrid::v(int i, int j) const {return v_(i,j);}
double StaggeredGrid::p(int i, int j) const {return p_(i,j);}
double StaggeredGrid::f(int i, int j) const {return f_(i,j);}
double StaggeredGrid::g(int i, int j) const {return g_(i,j);}
double StaggeredGrid::rhs(int i, int j) const {return rhs_(i,j);}

FieldVariable & StaggeredGrid::set_u() {return u_;}
FieldVariable & StaggeredGrid::set_v() {return v_;}
FieldVariable & StaggeredGrid::set_p() {return p_;}
FieldVariable & StaggeredGrid::set_f() {return f_;}
FieldVariable & StaggeredGrid::set_g() {return g_;}
FieldVariable & StaggeredGrid::set_rhs() {return rhs_;}

double & StaggeredGrid::set_u(int i, int j) {return u_(i,j);}
double & StaggeredGrid::set_v(int i, int j) {return v_(i,j);}
double & StaggeredGrid::set_p(int i, int j) {return p_(i,j);}
double & StaggeredGrid::set_f(int i, int j) {return f_(i,j);}
double & StaggeredGrid::set_g(int i, int j) {return g_(i,j);}
double & StaggeredGrid::set_rhs(int i, int j) {return rhs_(i,j);}

