#pragma once

#include "staggered_grid.h"


class Discretization : public StaggeredGrid
{
    public:
    //! construct the object with given number of cells in x and y direction
    Discretization(const std::array<int,2> nCells, const std::array<double,2> physicalSize);

    //! compute the 1st derivative ∂ u^2 / ∂x
    virtual double computeDu2Dx(int i, int j) const = 0;

    //! compute the 1st derivative ∂ v^2 / ∂y
    virtual double computeDv2Dy(int i, int j) const = 0;

    //! compute the 1st derivative ∂ (uv) / ∂x
    virtual double computeDuvDx(int i, int j) const = 0;

    //! compute the 1st derivative ∂ (uv) / ∂y
    virtual double computeDuvDy(int i, int j) const = 0;

    //! compute the 2nd derivative ∂^2 u / ∂x^2
    double computeD2uDx2(int i, int j) const;

    //! compute the 2nd derivative ∂^2 u / ∂y^2
    double computeD2uDy2(int i, int j) const;

    //! compute the 2nd derivative ∂^2 v / ∂x^2
    double computeD2vDx2(int i, int j) const;

    //! compute the 2nd derivative ∂^2 v / ∂y^2
    double computeD2vDy2(int i, int j) const;

    //! compute the 1st derivative ∂ F / ∂x
    double computeDFDx(int i, int j) const;

    //! compute the 1st derivative ∂ G / ∂y
    double computeDGDy(int i, int j) const;

    //! compute the 1st derivative ∂ p / ∂x
    double computeDpDx(int i, int j) const;

    //! compute the 1st derivative ∂ p / ∂y
    double computeDpDy(int i, int j) const;

    //! compute the 2nd derivative ∂^2 p / ∂x^2
    double computeD2pDx2(int i, int j) const;

    //! compute the 2nd derivative ∂^2 p / ∂y^2
    double computeD2pDy2(int i, int j) const;

    const std::array<double,2> meshWidth() const;
    

    private:
    std::array<int,2> nCells_;
    std::array<double,2> meshWidth_;
    std::array<double,2> physicalSize_;
};

