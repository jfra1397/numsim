#pragma once

#include "discretization.h"

class CentralDifferences : public Discretization
{
public:
    //use the constructor of the base class
    CentralDifferences(const std::array<int, 2> nCells, const std::array<double, 2> physicalSize);

    //compute the 1st derivative ∂ u^2 / ∂x
    virtual double computeDu2Dx(int i, int j) const;

    //compute the 1st derivative ∂ v^2 / ∂y
    virtual double computeDv2Dy(int i, int j) const;

    //compute the 1st derivative ∂ (uv) / ∂x
    virtual double computeDuvDx(int i, int j) const;

    //compute the 1st derivative ∂ (uv) / ∂y
    virtual double computeDuvDy(int i, int j) const;
};