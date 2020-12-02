#pragma once

#include "staggered_grid.h"


/** This class contains functions to compute first and second 
 * derivatives of all needed values. This is a abstarct class!
 */
class Discretization : public StaggeredGrid
{
public:
    //construct the object with given number of cells in x and y direction
    Discretization(const std::array<int, 2> nCells, const std::array<double, 2> physicalSize);

    //compute the 1st derivative ∂ u^2 / ∂x
    virtual double computeDu2Dx(int i, int j) const = 0;

    //compute the 1st derivative ∂ v^2 / ∂y
    virtual double computeDv2Dy(int i, int j) const = 0;

    //compute the 1st derivative ∂ (uv) / ∂x
    virtual double computeDuvDx(int i, int j) const = 0;

    //compute the 1st derivative ∂ (uv) / ∂y
    virtual double computeDuvDy(int i, int j) const = 0;

    //compute the 2nd derivative ∂^2 u / ∂x^2
    double computeD2uDx2(int i, int j) const;

    //compute the 2nd derivative ∂^2 u / ∂y^2
    double computeD2uDy2(int i, int j) const;

    //compute the 2nd derivative ∂^2 v / ∂x^2
    double computeD2vDx2(int i, int j) const;

    //compute the 2nd derivative ∂^2 v / ∂y^2
    double computeD2vDy2(int i, int j) const;

    //compute the 1st derivative ∂ F / ∂x
    double computeDFDx(int i, int j) const;

    //compute the 1st derivative ∂ G / ∂y
    double computeDGDy(int i, int j) const;

    //compute the 1st derivative ∂ p / ∂x
    double computeDpDx(int i, int j) const;

    //compute the 1st derivative ∂ p / ∂y
    double computeDpDy(int i, int j) const;

    //compute the 2nd derivative ∂^2 p / ∂x^2
    double computeD2pDx2(int i, int j) const;

    //compute the 2nd derivative ∂^2 p / ∂y^2
    double computeD2pDy2(int i, int j) const;

    //get meshwidth in each direction
    const std::array<double, 2> meshWidth() const;
    //get meshwidth in x-direction
    double dx() const;
    //get meshwidth in y-direction
    double dy() const;

    //get number of cells in each direction
    const std::array<int, 2> nCells() const;

    //write output to .txt file (self written)
    void write_to_file(int fileNo, double time) const;


private:
    //number of cells in each direction
    std::array<int, 2> nCells_;

    //meshwidth in each direction
    std::array<double, 2> meshWidth_;

    //physical size of mesh in each direction
    std::array<double, 2> physicalSize_;
};
