
#pragma once

#include "field_variable.h"


class StaggeredGrid
{
    public:
    StaggeredGrid(const std::array<int,2> size);
    

    int set_boundery_uv(const std::array<double,2> bottomBound, const std::array<double,2> rightBound, const std::array<double,2> topBound, const std::array<double,2> leftBound);
    int set_boundery_fg(const std::array<double,2> bottomBound, const std::array<double,2> rightBound, const std::array<double,2> topBound, const std::array<double,2> leftBound);
    
    const FieldVariable & u() const;
    const FieldVariable & v() const;
    const FieldVariable & p() const;
    const FieldVariable & f() const;
    const FieldVariable & g() const;
    const FieldVariable & rhs() const;

    double u(int i, int j) const;
    double v(int i, int j) const;
    double p(int i, int j) const;
    double f(int i, int j) const;
    double g(int i, int j) const;
    double rhs(int i, int j) const;

    FieldVariable & set_u();
    FieldVariable & set_v();
    FieldVariable & set_p();
    FieldVariable & set_f();
    FieldVariable & set_g();
    FieldVariable & set_rhs();

    double & set_u(int i, int j);
    double & set_v(int i, int j);
    double & set_p(int i, int j);
    double & set_f(int i, int j);
    double & set_g(int i, int j);
    double & set_rhs(int i, int j);

    private:
    FieldVariable u_;
    FieldVariable v_;
    FieldVariable p_;
    FieldVariable f_;
    FieldVariable g_;
    FieldVariable rhs_;

};