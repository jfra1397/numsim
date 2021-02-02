#include <math.h>

#include "../includes/donor_cell.h"

DonorCell::DonorCell(const std::array<int, 2> nCells, const std::array<double, 2> physicalSize, double tInit, double alpha, double gamma) : Discretization(nCells, physicalSize, tInit)
{
    //weighting factor
    alpha_ = alpha;
    gamma_ = gamma;
}

//compute the 1st derivative ∂ u^2 / ∂x
double DonorCell::computeDu2Dx(int i, int j) const
{
    //define u(i+1/2,j) and u(i-1/2,j)
    double uMidRight = (u(i, j) + u(i + 1, j)) / 2, uMidLeft = (u(i, j) + u(i - 1, j)) / 2;
    return (uMidRight * uMidRight - uMidLeft * uMidLeft + alpha_ * (fabs(uMidRight) * ((u(i, j) - u(i + 1, j)) / 2) - fabs(uMidLeft) * (u(i - 1, j) - u(i, j)) / 2)) / dx();
}

//compute the 1st derivative ∂ v^2 / ∂y
double DonorCell::computeDv2Dy(int i, int j) const
{
    //define v(i,j+1/2) and v(i,j-1/2)
    double vMidUp = (v(i, j) + v(i, j + 1)) / 2, vMidDown = (v(i, j - 1) + v(i, j)) / 2;
    return (vMidUp * vMidUp - vMidDown * vMidDown + alpha_ * (fabs(vMidUp) * ((v(i, j) - v(i, j + 1)) / 2) - fabs(vMidDown) * (v(i, j - 1) - v(i, j)) / 2)) / dy();
}

//compute the 1st derivative ∂ (uv) / ∂x
double DonorCell::computeDuvDx(int i, int j) const
{
    //define u(i,j+1/2) and u(i-1,j+1/2)
    double uMidUp = (u(i, j) + u(i, j + 1)) / 2, uLeftUp = (u(i - 1, j) + u(i - 1, j + 1)) / 2;
    return (uMidUp * (v(i, j) + v(i + 1, j)) / 2 - uLeftUp * (v(i - 1, j) + v(i, j)) / 2 + alpha_ * (fabs(uMidUp) * (v(i, j) - v(i + 1, j)) / 2 - fabs(uLeftUp) * (v(i - 1, j) - v(i, j)) / 2)) / dx();
}

//compute the 1st derivative ∂ (uv) / ∂y
double DonorCell::computeDuvDy(int i, int j) const
{
    //define v(i+1/2,j) and v(i+1/2,j-1)
    double vMidRight = (v(i, j) + v(i + 1, j)) / 2, vDownRight = (v(i, j - 1) + v(i + 1, j - 1)) / 2;
    return (vMidRight * (u(i, j + 1) + u(i, j)) / 2 - vDownRight * (u(i, j) + u(i, j - 1)) / 2 + alpha_ * (fabs(vMidRight) * (u(i, j) - u(i, j + 1)) / 2 - fabs(vDownRight) * (u(i, j - 1) - u(i, j)) / 2)) / dy();
}

//compute the 1st derivative ∂ uT / ∂x
double DonorCell::computeDuTDx(int i, int j) const
{
    double TLeft = (T(i - 1, j) + T(i, j)) / 2;
    double TRight = (T(i + 1, j) + T(i, j)) / 2;
    return (u(i, j) * TRight - u(i - 1, j) * TLeft + gamma_ * (fabs(u(i, j)) * (T(i, j) - T(i + 1, j)) / 2 - fabs(u(i - 1, j)) * (T(i - 1, j) - T(i, j)) / 2)) / dx();
}

//compute the 1st derivative ∂ vT / ∂y
double DonorCell::computeDvTDy(int i, int j) const
{
    double TTop = (T(i, j + 1) + T(i, j)) / 2;
    double TBottom = (T(i, j - 1) + T(i, j)) / 2;
    return (v(i, j) * TTop - v(i, j - 1) * TBottom + gamma_ * (fabs(v(i, j)) * (T(i, j) - T(i, j + 1)) / 2 - fabs(v(i, j - 1)) * (T(i, j - 1) - T(i, j)) / 2)) / dy();
}