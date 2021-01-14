#pragma once

#include "array2d.h"
#include "field_variable.h"

class Mesh
{
    public:
    Mesh(const std::array<int, 2> nCells, const std::array<double, 2> physicalSize);
    void set_boundary_condition(std::vector<std::string> left, std::vector<std::string> right, std::vector<std::string> top, std::vector<std::string> bottom);
    void set_object_condition(std::vector<std::string> objects);
    
    protected:

    //number of cells in each direction
    std::array<int, 2> nCells_;

    //meshwidth in each direction
    std::array<double, 2> meshWidth_;

    //physical size of mesh in each direction
    std::array<double, 2> physicalSize_;

    Array2D<CELLTYPE> flag_;
    std::vector<btype> leftBoundVelFlag_;
    // u,v,p
    std::vector<std::array<double,3>> leftBoundValues_;
    std::vector<btype> rightBoundVelFlag_;
    std::vector<std::array<double,3>> rightBoundValues_;
    std::vector<btype> topBoundVelFlag_;
    std::vector<std::array<double,3>> topBoundValues_;
    std::vector<btype> bottomBoundVelFlag_;
    std::vector<std::array<double,3>> bottomBoundValues_;

    private:
    std::vector<std::string> cut (const std::string &str);
};