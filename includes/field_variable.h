#pragma once

#include <fstream>

#include "array2d.h"

//describe edge type
enum edgetype
{
    //actual boundary edge
    HALO,
    //edge for communication between processes
    GHOST
};

//describe orientation of the corresponding edge
enum orientation
{
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
};

//describe position of corresponding variable on grid
enum vposition
{
    VCENTRE,
    VRIGHT,
    VTOP
};

//describe boundary condition type
enum btype
{
    DIRICHLET,
    NEUMANN
};

/** This class represents a field variable of double values.
 * It inherits from Array2D to access and store the values
 * and additionally it contains methods to set boundary conditions
 * and interpolated values.
 */
class FieldVariable : public Array2D
{
public:
    //constructor
    FieldVariable(const std::array<int, 2> &size, vposition pos, const std::array<double, 2> &physicalSize, const std::array<edgetype, 4> &edgestype);
    //constructor to make things suitable for output_writer
    FieldVariable(const std::array<int, 2> &size, const std::array<double, 2> &offset, const std::array<double, 2> &meshWidth);

    //set boundary condition type of each boundary
    void set_boundary_type(btype top = DIRICHLET, btype bottom = DIRICHLET, btype left = DIRICHLET, btype right = DIRICHLET);

    //set boundary values at each boundary
    void set_boundary_dirichlet(orientation orient, double boundvalue);
    void set_boundary_neumann(orientation orient, double boundvalue);

    //set field variable matrix to data matrix
    void operator=(const Array2D &data);

    //write to .txt file
    void write_to_file(const std::string &fileName, const std::string &name, bool append = false) const;

    //interpolate matrix values at given physical location (x,y)
    double interpolateAt(double x, double y) const;

private:
    //disable default constructor
    FieldVariable();

    //activate interpolation at top and bottom boundary
    bool verticalBoundInterpolate_;

    //activate interpolation at left and right boundary
    bool horizontalBoundInterpolate_;

    //boundary condition at top/bottom/left/right boundary
    btype topBoundType_;
    btype bottomBoundType_;
    btype leftBoundType_;
    btype rightBoundType_;

    //edge type at top/bottom/left/right boundary
    edgetype topEdgeType_;
    edgetype bottomEdgeType_;
    edgetype leftEdgeType_;
    edgetype rightEdgeType_;

    //position of corresponding variable on grid
    vposition pos_;

    //meshwidth in each direction
    std::array<double, 2> meshWidth_;

    //physical size in each direction
    std::array<double, 2> physicalSize_;
};
