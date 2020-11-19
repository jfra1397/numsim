#include <math.h>

#include "../includes/donor_cell.h"


DonorCell::DonorCell(const std::array<int,2> nCells, const std::array<double,2> physicalSize, double alpha):
Discretization(nCells, physicalSize)
{alpha_ = alpha;}


//! compute the 1st derivative ∂ u^2 / ∂x
double DonorCell::computeDu2Dx(int i, int j) const
{
    double u_right = (u(i,j) + u(i+1,j))/2;
    double u_left = (u(i,j) + u(i-1,j))/2;
    
    double result = (u_right*u_right - u_left*u_left + alpha_*(fabs(u_right)*((u(i,j) - u(i+1,j)) / 2) - fabs(u_left)*(u(i-1,j) - u(i,j)) / 2)) / meshWidth()[0];
    return result;
}

//! compute the 1st derivative ∂ v^2 / ∂y
double DonorCell::computeDv2Dy(int i, int j) const
{   
    double v_up = (v(i,j) + v(i,j+1))/2;
    double v_down = (v(i,j-1) + v(i,j))/2;
    double result = (v_up*v_up - v_down*v_down + alpha_*(fabs(v_up)*((v(i,j) - v(i,j+1)) / 2) - fabs(v_down)*(v(i,j-1) - v(i,j)) / 2)) / meshWidth()[1];
    
    return result;
}

//! compute the 1st derivative ∂ (uv) / ∂x
double DonorCell::computeDuvDx(int i, int j) const
{
    double u_upright = (u(i,j) + u(i,j+1))/2;
    double u_upleft = (u(i-1,j) + u(i-1,j+1))/2;
    double result = (u_upright * (v(i,j) + v(i+1,j)) / 2 - u_upleft* (v(i-1,j) + v(i,j)) / 2 + alpha_* (fabs(u_upright) * (v(i,j) - v(i+1,j)) / 2 - fabs(u_upleft) * (v(i-1,j) - v(i,j)) /2)) / meshWidth()[0];
    
    return result;
}

//! compute the 1st derivative ∂ (uv) / ∂y
double DonorCell::computeDuvDy(int i, int j) const
{
    double v_rightup = (v(i,j) + v(i+1,j))/2;
    double v_rightdown = (v(i,j-1) + v(i+1,j-1))/2;

    double result = (v_rightup * (u(i,j+1) + u(i,j)) / 2 - v_rightdown* (u(i,j) + u(i,j-1)) / 2 + alpha_* (fabs(v_rightup) * (u(i,j) - u(i,j+1)) / 2 - fabs(v_rightdown) * (u(i,j-1) - u(i,j)) /2)) / meshWidth()[1];
    return result;
}