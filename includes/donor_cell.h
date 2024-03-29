#pragma once

#include "discretization.h"

/** This class contains functions to compute first derivatives
 * of squared u,v corresponding to the donor cell scheme  and all other derivates inherited from 
 * discretization.
 */
class DonorCell : public Discretization
{
    public:
    //use the constructor of the base class
    DonorCell(const std::array<int,2> &nCells, const std::array<double,2> &physicalSize, double alpha, std::array<edgetype, 4> &edgestype);

    //compute the 1st derivative ∂ u^2 / ∂x
    virtual double computeDu2Dx(int i, int j) const;

    //compute the 1st derivative ∂ v^2 / ∂y
    virtual double computeDv2Dy(int i, int j) const;

    //compute the 1st derivative ∂ (uv) / ∂x
    virtual double computeDuvDx(int i, int j) const;

    //compute the 1st derivative ∂ (uv) / ∂y
    virtual double computeDuvDy(int i, int j) const;

    private:
    //weighting factor
    double alpha_;
};