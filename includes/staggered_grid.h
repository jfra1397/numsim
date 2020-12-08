
#pragma once

#include "field_variable.h"

/** This class stores all field variables and 
 * is able to set boundary conditions and values
 */
class StaggeredGrid
{
public:
    //constructor
    StaggeredGrid(const std::array<int, 2> &size, const std::array<double, 2> &physicalSize, std::array<edgetype, 4> &edgestype);

    // //set boundary values corresponding to variable
    // void set_boundary_uv(const std::array<double, 2> &bottomBound, const std::array<double, 2> &rightBound, const std::array<double, 2> &topBound, const std::array<double, 2> &leftBound);
    // void set_boundary_fg(const FieldVariable &u, const FieldVariable &v);

    //get the whole field variable, declared const, i.e. it is not possible to change it
    inline const FieldVariable &u() const { return u_; };
    inline const FieldVariable &v() const { return v_; };
    inline const FieldVariable &p() const { return p_; };
    inline const FieldVariable &f() const { return f_; };
    inline const FieldVariable &g() const { return g_; };
    inline const FieldVariable &rhs() const { return rhs_; };

    //get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
    inline double u(int i, int j) const { return u_(i, j); };
    inline double v(int i, int j) const { return v_(i, j); };
    inline double p(int i, int j) const { return p_(i, j); };
    inline double f(int i, int j) const { return f_(i, j); };
    inline double g(int i, int j) const { return g_(i, j); };
    inline double rhs(int i, int j) const { return rhs_(i, j); }

    //access the field variable, declared not const, i.e. the values can be changed
    inline FieldVariable &set_u() { return u_; };
    inline FieldVariable &set_v() { return v_; };
    inline FieldVariable &set_p() { return p_; };
    inline FieldVariable &set_f() { return f_; };
    inline FieldVariable &set_g() { return g_; };
    inline FieldVariable &set_rhs() { return rhs_; };

    //access the value at coordinate (i,j), declared not const, i.e. the value can be changed
    inline double &set_u(int i, int j) { return u_(i, j); };
    inline double &set_v(int i, int j) { return v_(i, j); };
    inline double &set_p(int i, int j) { return p_(i, j); };
    inline double &set_f(int i, int j) { return f_(i, j); };
    inline double &set_g(int i, int j) { return g_(i, j); };
    inline double &set_rhs(int i, int j) { return rhs_(i, j); };

    int uIBegin() const;
    int uIEnd() const;
    int uJBegin() const;
    int uJEnd() const;
    int vIBegin() const;
    int vIEnd() const;
    int vJBegin() const;
    int vJEnd() const;
    int pIBegin() const;
    int pIEnd() const;
    int pJBegin() const;
    int pJEnd() const;

private:
    //field variables
    FieldVariable u_;
    FieldVariable v_;
    FieldVariable p_;
    FieldVariable f_;
    FieldVariable g_;
    FieldVariable rhs_;
};