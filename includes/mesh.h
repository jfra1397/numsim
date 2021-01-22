#pragma once

#include "array2d.h"
#include "field_variable.h"
#include "settings.h"
#include "values.h"

class Mesh
{
    public:
    Mesh(const std::array<int, 2> nCells, const std::array<double, 2> physicalSize);
    void set_boundary_condition(std::vector<Obstacle> objects);
    
    protected:

    //number of cells in each direction
    std::array<int, 2> nCells_;

    //meshwidth in each direction
    std::array<double, 2> meshWidth_;

    //physical size of mesh in each direction
    std::array<double, 2> physicalSize_;

    Array2D<CELLTYPE> flag_;
    Array2D<btype> objTemperatureFlag_;
    Array2D<double> objTemperatureValues_;

    std::vector<btype> leftBoundVelFlag_;
    std::vector<btype> leftBoundTempFlag_;
    std::vector<std::array<double,4>> leftBoundValues_;     // u,v,p,T
    std::vector<btype> rightBoundVelFlag_;
    std::vector<btype> rightBoundTempFlag_;    
    std::vector<std::array<double,4>> rightBoundValues_;
    std::vector<btype> topBoundVelFlag_;
    std::vector<btype> topBoundTempFlag_;
    std::vector<std::array<double,4>> topBoundValues_;
    std::vector<btype> bottomBoundVelFlag_;
    std::vector<btype> bottomBoundTempFlag_;
    std::vector<std::array<double,4>> bottomBoundValues_;
};