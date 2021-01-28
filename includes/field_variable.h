#pragma once

#include <fstream>

#include "array2d.h"

//describe position of corresponding variable on grid
enum vposition
{
    VCENTRE,
    VRIGHT,
    VTOP
};


/** This class represents a field variable of double values.
 * It inhertits from Array2D to access and store the values
 * and additionally it contains methods to set boundary conditions
 * and interpolated values.
 */
class FieldVariable : public Array2D<double>
{
public:
    //constructor
    FieldVariable(const std::array<int, 2> size, vposition pos, const std::array<double, 2> physicalSize, const std::array<double, 2> meshWidth, double value =0.0);

    //set field variable matrix to data matrix
    void operator=(const Array2D<double> &data);

    //write to .txt file
    void write_to_file(std::string fileName, std::string name, bool append = false) const;

    //interpolate matrix values at given physical location (x,y)
    double interpolateAt(double x, double y) const;

private:
    //disable default constructor
    FieldVariable();

    //activate interpolation at top and bottom boundary
    bool verticalBoundInterpolate_;

    //activate interpolation at left and right boundary
    bool horizontalBoundInterpolate_;

    double horizontalOffset_;
    double verticalOffset_;

    //position of corresponding variable on grid
    vposition pos_;

    //meshwidth in each direction
    std::array<double, 2> meshWidth_;

    //physical size in each direction
    std::array<double, 2> physicalSize_;
};
