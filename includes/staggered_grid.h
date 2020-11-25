
#pragma once

#include "field_variable.h"


/** This class stores all field variables and 
 * is able to set boundary conditions and values
 */
class StaggeredGrid
{
public:
    //constructor
    StaggeredGrid(const std::array<int, 2> size, const std::array<double, 2> physicalSize);

    //set boundary values corresponding to variable
    void set_boundary_uv(const std::array<double, 2> &bottomBound, const std::array<double, 2> &rightBound, const std::array<double, 2> &topBound, const std::array<double, 2> &leftBound);
    void set_boundary_fg(const FieldVariable &u, const FieldVariable &v);

    //get the whole field variable, declared const, i.e. it is not possible to change it
    const FieldVariable &u() const;
    const FieldVariable &v() const;
    const FieldVariable &p() const;
    const FieldVariable &f() const;
    const FieldVariable &g() const;
    const FieldVariable &rhs() const;

    //get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
    double u(int i, int j) const;
    double v(int i, int j) const;
    double p(int i, int j) const;
    double f(int i, int j) const;
    double g(int i, int j) const;
    double rhs(int i, int j) const;

    //access the field variable, declared not const, i.e. the values can be changed
    FieldVariable &set_u();
    FieldVariable &set_v();
    FieldVariable &set_p();
    FieldVariable &set_f();
    FieldVariable &set_g();
    FieldVariable &set_rhs();

    //access the value at coordinate (i,j), declared not const, i.e. the value can be changed
    double &set_u(int i, int j);
    double &set_v(int i, int j);
    double &set_p(int i, int j);
    double &set_f(int i, int j);
    double &set_g(int i, int j);
    double &set_rhs(int i, int j);

private:
    //field variables
    FieldVariable u_;
    FieldVariable v_;
    FieldVariable p_;
    FieldVariable f_;
    FieldVariable g_;
    FieldVariable rhs_;
};