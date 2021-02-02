#pragma once

#include "array2d.h"
#include "field_variable.h"
#include "settings.h"
#include "values.h"

/** This class describes (the shape of) the mesh and its boundary 
 * conditions at boundaries and obstacles
 */
class Mesh
{
    public:
    //constructor
    Mesh(const std::array<int, 2> nCells, const std::array<double, 2> physicalSize);
   
   //generate mesh
   void generate_mesh(std::vector<Obstacle> objects);
    
    protected:
    //number of cells in each direction
    std::array<int, 2> nCells_;

    //meshwidth in each direction
    std::array<double, 2> meshWidth_;

    //physical size of mesh in each direction
    std::array<double, 2> physicalSize_;

    //mesh describing celltype and boundary type at obstacles for velocity and pressure
    Array2D<CELLTYPE> flag_;

    //meshs describing boundary type and values at obstacles for temperature
    Array2D<btype> objTemperatureFlag_;
    Array2D<double> objTemperatureValues_;

    //vectors holding boundary type for velocity (& pressure) & temperature and values for each at each boundary
    std::vector<btype> leftBoundVelFlag_;
    std::vector<btype> leftBoundTempFlag_;
    std::vector<std::array<double,4>> leftBoundValues_;   //order u,v,p,T
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