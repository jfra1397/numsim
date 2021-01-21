
#pragma once

#include "field_variable.h"
#include "mesh.h"



/** This class stores all field variables and 
 * is able to set boundary conditions and values
 */
class StaggeredGrid: public Mesh
{
public:
    //constructor
    StaggeredGrid(const std::array<int, 2> size, const std::array<double, 2> physicalSize);

    //set boundary values corresponding to variable
    void set_boundary_uvfg();
    void set_boundary_fg();
    void set_boundary_p(FieldVariable &p) const;
    void set_boundary_T(FieldVariable &T) const;

    //get the whole field variable, declared const, i.e. it is not possible to change it
    const FieldVariable &u() const;
    const FieldVariable &v() const;
    const FieldVariable &p() const;
    const FieldVariable &f() const;
    const FieldVariable &g() const;
    const FieldVariable &rhs() const;
    const FieldVariable &T() const;


    //get the value at coordinate (i,j), declared const, i.e. it is not possible to change the value
    double u(int i, int j) const;
    double v(int i, int j) const;
    double p(int i, int j) const;
    double f(int i, int j) const;
    double g(int i, int j) const;
    double rhs(int i, int j) const;
    double T(int i, int j) const;

    CELLTYPE flag(int i, int j) const;

    //access the field variable, declared not const, i.e. the values can be changed
    FieldVariable &set_u();
    FieldVariable &set_v();
    FieldVariable &set_p();
    FieldVariable &set_f();
    FieldVariable &set_g();
    FieldVariable &set_rhs();
    FieldVariable &set_T();

    //access the value at coordinate (i,j), declared not const, i.e. the value can be changed
    double &set_u(int i, int j);
    double &set_v(int i, int j);
    double &set_p(int i, int j);
    double &set_f(int i, int j);
    double &set_g(int i, int j);
    double &set_rhs(int i, int j);
    double &set_T(int i, int j);

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
    FieldVariable T_;
    
    
};