#include <math.h>

#include "../includes/central_differences.h"

CentralDifferences::CentralDifferences(const std::array<int, 2> nCells, const std::array<double, 2> physicalSize) : Discretization(nCells, physicalSize)
{
}

//compute the 1st derivative ∂ u^2 / ∂x
double CentralDifferences::computeDu2Dx(int i, int j) const
{
    //define u(i+1/2,j) and u(i-1/2,j)
    double uMidRight = u(i + 1, j) + u(i, j), uMidLeft = u(i, j) + u(i - 1, j);
    double denominator = 4 * dx();
    return (uMidRight * uMidRight - uMidLeft * uMidLeft) / denominator;
}

//compute the 1st derivative ∂ v^2 / ∂y
double CentralDifferences::computeDv2Dy(int i, int j) const
{
    //define v(i,j+1/2) and v(i,j-1/2)
    double vMidUp = v(i, j + 1) + v(i, j), vMidDown = v(i, j) + v(i, j - 1);
    double denominator = 4 * dy();
    return (vMidUp * vMidUp - vMidDown * vMidDown) / denominator;
}

//compute the 1st derivative ∂ (uv) / ∂x
double CentralDifferences::computeDuvDx(int i, int j) const
{
    //define multiple used values
    double vMid = v(i, j), uMid = u(i, j);
    double denominator = 4 * dx();
    return ((v(i + 1, j) + vMid) * (uMid + u(i, j + 1)) - (vMid + v(i - 1, j)) * (u(i - 1, j) + u(i - 1, j + 1))) / denominator;
}

//compute the 1st derivative ∂ (uv) / ∂y
double CentralDifferences::computeDuvDy(int i, int j) const
{
    //define multiple used values
    double vMid = v(i, j), uMid = u(i, j);
    double denominator = 4 * dy();
    return ((u(i, j + 1) + uMid) * (v(i + 1, j) + vMid) - (uMid + u(i, j - 1)) * (v(i + 1, j - 1) + v(i, j - 1))) / denominator;
}