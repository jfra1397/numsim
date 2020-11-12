#include <math.h>

#include "../includes/central_differences.h"


CentralDifferences::CentralDifferences(std::array<int,2> nCells, std::array<double,2> physicalSize):
Discretization(nCells, physicalSize)
{}


//! compute the 1st derivative ∂ u^2 / ∂x
double CentralDifferences::computeDu2Dx(int i, int j) const
{
    double result = (pow(u(i+1,j) + u(i,j),2) - pow(u(i,j) + u(i-1,j),2))/(4*meshWidth_[0]);
    return result;
}

//! compute the 1st derivative ∂ v^2 / ∂y
double CentralDifferences::computeDv2Dy(int i, int j) const
{
    double result = (pow(v(i,j+1) + v(i,j),2) - pow(v(i,j) + v(i,j-1),2))/(4*meshWidth_[1]);
    return result;
}

//! compute the 1st derivative ∂ (uv) / ∂x
double CentralDifferences::computeDuvDx(int i, int j) const
{
    double result = ((v(i+1,j) + v(i,j)) * (u(i,j) + u(i,j+1)) - (v(i,j) + v(i-1,j)) * (u(i-1,j) + u(i-1,j+1)))/(4*meshWidth_[0]);
    return result;
}

//! compute the 1st derivative ∂ (uv) / ∂y
double CentralDifferences::computeDuvDy(int i, int j) const
{
    double result = ((u(i,j+1) + u(i,j)) * (v(i+1,j) + v(i,j)) - (u(i,j) + u(i,j-1)) * (v(i+1,j-1) + v(i,j-1)))/(4*meshWidth_[1]);
    return result;
}