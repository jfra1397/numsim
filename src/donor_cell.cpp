#include <math.h>

#include "../includes/donor_cell.h"


DonorCell::DonorCell(const std::array<int,2> nCells, const std::array<double,2> physicalSize, double alpha):
Discretization(nCells, physicalSize)
{alpha_ = alpha;}


//! compute the 1st derivative ∂ u^2 / ∂x
double DonorCell::computeDu2Dx(int i, int j) const
{
    double u_1 = (u(i,j) + u(i+1,j))/2;
    double u_2 = (u(i,j) + u(i-1,j))/2;
    
    double result = (u_1*u_1 - u_2*u_2 + alpha_*(abs(u_1)*(u(i,j) - u(i+1,j) / 2) - abs(u_2)*(u(i-1,j) - u(i,j)) / 2)) / meshWidth()[0];
    return result;
}

//! compute the 1st derivative ∂ v^2 / ∂y
double DonorCell::computeDv2Dy(int i, int j) const
{   
    double v_1 = (v(i,j) + v(i,j+1))/2;
    double v_2 = (v(i,j-1) + v(i,j))/2;
    double result = (v_1*v_1 - v_2*v_2 + alpha_*(abs(v_1)*(v(i,j) - v(i,j+1) / 2) - abs(v_2)*(v(i,j-1) - v(i,j)) / 2)) / meshWidth()[1];
    
    return result;
}

//! compute the 1st derivative ∂ (uv) / ∂x
double DonorCell::computeDuvDx(int i, int j) const
{
    double u_1 = (u(i,j) + u(i,j+1))/2;
    double u_2 = (u(i-1,j) + u(i-1,j+1))/2;
    double result = (u_1 * (v(i,j) + v(i+1,j)) / 2 - u_2* v(i-1,j) + v(i,j)) / 2 + alpha_* (abs(u_1) * (v(i,j) - v(i+1,j)) / 2 - abs(u_2) * (v(i-1,j) - v(i,j)) /2)/meshWidth()[0];
    
    return result;
}

//! compute the 1st derivative ∂ (uv) / ∂y
double DonorCell::computeDuvDy(int i, int j) const
{
    double v_1 = (v(i,j) + v(i+1,j))/2;
    double v_2 = (v(i,j-1) + v(i+1,j-1))/2;

    double result = (v_1 * (u(i,j+1) + u(i,j)) / 2 - v_2* (u(i,j) + u(i,j-1)) / 2 + alpha_* (abs(v_1) * (u(i,j) - u(i,j+1)) / 2 - abs(v_2) * (u(i,j-1) - u(i,j)) /2))/meshWidth()[1];
    return result;
}