#include <cassert>
#include <iomanip>
#include <iostream>

#include "../includes/field_variable.h"

FieldVariable::FieldVariable(const std::array<int, 2> size, vposition pos, const std::array<double, 2> physicalSize, std::array<edgetype, 4> edgestype) : Array2D({0, 0})
{
    //set position of corresponding variable on grid
    pos_ = pos;

    //set boundary condition at top/bottom/left/right boundary
    topBoundType_ = DIRICHLET;
    bottomBoundType_ = DIRICHLET;
    leftBoundType_ = DIRICHLET;
    rightBoundType_ = DIRICHLET;

    topEdgeType_ = edgestype[0];
    bottomEdgeType_ = edgestype[1];
    leftEdgeType_ = edgestype[2];
    rightEdgeType_ = edgestype[3];

    //calculate meshwidth in each direction
    meshWidth_ = {physicalSize[0] / (double)size[0], physicalSize[1] / (double)size[1]};

    //physical size in each direction
    physicalSize_ = physicalSize;

    //set size in each direction
    int sizex = size[0], sizey = size[1];


    //if value is at centre, extend matrix in both directions by two (variable types p and rhs)
    if (pos == VCENTRE)
    {
        sizex += 2;
        sizey += 2;
        horizontalBoundInterpolate_ = true;
        verticalBoundInterpolate_ = true;
    }
    //if value is at right, extend matrix in y-direction by two and x-direction by one (variable types u and F)
    else if (pos == VRIGHT)
    {
        if (rightEdgeType_  == GHOST) sizex += 1;
        sizex += 1;
        sizey += 2;
        horizontalBoundInterpolate_ = false;
        verticalBoundInterpolate_ = true;
    }
    //if value is at top, extend matrix in y-direction by one and x-direction by two (variable types v and G)
    else if (pos == VTOP)
    {
        if (topEdgeType_  == GHOST) sizey += 1;
        sizex += 2;
        sizey += 1;
        horizontalBoundInterpolate_ = true;
        verticalBoundInterpolate_ = false;
    }
    // allocate data, initialize to 0
    resize({sizex, sizey});
}

FieldVariable::FieldVariable(std::array<int,2> size, std::array<double,2> offset, std::array<double,2> meshWidth)
    :Array2D(size)
{
}

//set boundary condition type of each boundary
int FieldVariable::set_boundary_type(btype top, btype bottom, btype left, btype right)
{
    if (top == NEUMANN || bottom == NEUMANN || left == NEUMANN || right == NEUMANN)
    {
        assert(("Neumann boundary condition not implemented for variable positions at top and right!", pos_ == VCENTRE));
    }
    topBoundType_ = top;
    bottomBoundType_ = bottom;
    leftBoundType_ = left;
    rightBoundType_ = right;

    return 0;
}

//set boundary values at each boundary
int FieldVariable::set_boundary_dirichlet(orientation orient, double boundvalue)
{
    int i, j;
    //iterate over bottom boundary
    if (orient == TOP)
    {
        j = size()[1] - 1;
        //check if interpolation is necessary
        if (verticalBoundInterpolate_)
        {
            for (i = 1; i < size()[0] - 1; i++)
            {
                //average values to match "real" boundary conditon value in the middle
                (*this)(i, j) = 2 * boundvalue - (*this)(i, j - 1);
            }
        }
        else
        {
            for (i = 1; i < size()[0] - 1; i++)
            {
                //set value to boundary condition value
                (*this)(i, j) = boundvalue;
            }
        }
    }
    //iterate over top boundary
    else if (orient == TOP)
    {
        j = 0;
        //check if interpolation is necessary
        if (verticalBoundInterpolate_)
        {
            for (i = 1; i < size()[0] - 1; i++)
            {
                //average values to match "real" boundary conditon value in the middle
                (*this)(i, j) = 2 * boundvalue - (*this)(i, j + 1);
            }
        }
        else
        {
            for (i = 1; i < size()[0] - 1; i++)
            {
                //set value to boundary condition value
                (*this)(i, j) = boundvalue;
            }
        }
    }
    //iterate over left boundary
    else if (orient == LEFT)
    {
        i = 0;
        //check if interpolation is necessary
        if (horizontalBoundInterpolate_)
        {
            for (j = 0; j < size()[1]; j++)
            {
                    //average values to match "real" boundary conditon value in the middle
                    (*this)(i, j) = 2 * boundvalue - (*this)(i + 1, j);
            }
        }
        else
        {
            for (j = 0; j < size()[1]; j++)
            {
                    //set value to boundary condition value
                    (*this)(i, j) = boundvalue;
            }
        }
    }
    //iterate over right boundary
    else if (orient == RIGHT)
    {
        i = size()[0] - 1;
        //check if interpolation is necessary
        if (horizontalBoundInterpolate_)
        {
            for (j = 0; j < size()[1]; j++)
            {
                    //average values to match "real" boundary conditon value in the middle
                    (*this)(i, j) = 2 * boundvalue - (*this)(i - 1, j);

            }
        }
        else
        {
            for (j = 0; j < size()[1]; j++)
            {
                //set value to boundary condition value
                (*this)(i, j) = boundvalue;

            }
        }
    }
    return 0;
}


int FieldVariable::set_boundary_neumann(orientation orient, double boundvalue)
{
    int i, j;
    //iterate over bottom boundary
    if (orient == TOP)
    {
        j = size()[1] - 1;
        for (i = 1; i < size()[0] - 1; i++)
        { 
            //set value such that derivation at boundary matches boundary condition
            (*this)(i, j) = boundvalue * meshWidth_[1] + (*this)(i, j - 1);
            
        }
    }
    //iterate over top boundary
    else if (orient == TOP)
    {
        j = 0;
        for (i = 1; i < size()[0] - 1; i++)
        {
            //set value such that derivation at boundary matches boundary condition
            (*this)(i, j) = boundvalue * meshWidth_[1] + (*this)(i, j + 1);
        }
    }
    //iterate over left boundary
    else if (orient == LEFT)
    {
        i = 0;
        for (j = 0; j < size()[1]; j++)
        {
            //set value such that derivation at boundary matches boundary condition
            (*this)(i, j) = boundvalue * meshWidth_[0] + (*this)(i + 1, j);
        }
    }
    //iterate over right boundary
    else if (orient == RIGHT)
    {
        i = size()[0] - 1;
        for (j = 0; j < size()[1]; j++)
        {
            //set value such that derivation at boundary matches boundary condition
            (*this)(i, j) = boundvalue * meshWidth_[0] + (*this)(i - 1, j);
        }
    }
    return 0;
}

//set field variable matrix to data matrix
void FieldVariable::operator=(const Array2D &result)
{
    set_data(result);
}

//write to .txt file
void FieldVariable::write_to_file(std::string fileName, std::string name, bool append) const
{
    //declare file instance
    std::ofstream myfile;
    
    //open file either in append mode or overwritte mode
    if (append)
        myfile.open(fileName, std::ios::out | std::ios::app);
    else
        myfile.open(fileName, std::ios::out | std::ios::trunc);

    //write name and size of field variable to file
    myfile << name << " (" << size()[0] << "x" << size()[1] << "):" << std::endl;

    //settings for printing values
    myfile << std::right;
    myfile.precision(4);
    int setw = 14;
    
    //write header of table
    int ii = -1;
    myfile << std::setw(setw + 1) << "|";
    for (int i = 0; i < size()[0]; i++)
    {
        myfile << std::setw(setw) << ii;
        ii += 1;
    }

    myfile << std::endl;

    //underline header
    for (int i = 0; i <= setw * (size()[0] + 1); i++)
    {
        myfile << "-";
    }

    myfile << std::endl;

    //loop through rows
    for (int j = size()[1] - 1; j >= 0; j--)
    {
        //write row header
        myfile << std::setw(setw) << j-1 << "|";
        //loop throug columns
        for (int i = 0; i < size()[0]; i++)
        {
            //write value to file
            myfile << std::setw(setw) << (*this)(i, j);
        }
        myfile << std::endl;
    }
    myfile << std::endl;
    //close file
    myfile.close();
}

//interpolate matrix values at given physical location (x,y)
double FieldVariable::interpolateAt(double x, double y) const
{

    //check if x and y are legal values
    assert(("Position in x-direction is out of bound!", 0 <= x && x <= physicalSize_[0]));
    assert(("Position in y-direction is out of bound!", 0 <= y && y <= physicalSize_[1]));

    double verticalOffset = 0, horizontalOffset = 0;

    //check position to calculate offset
    if (pos_ == VCENTRE)
    {
        horizontalOffset = meshWidth_[0] / 2;
        verticalOffset = meshWidth_[1] / 2;
    }
    else if (pos_ == VRIGHT)
    {
        verticalOffset = meshWidth_[1] / 2;
    }
    else if (pos_ == VTOP)
    {
        horizontalOffset = meshWidth_[0] / 2;
    }

    //calculate index of grid point left below or equal to physical point (x,y)
    int i = (x + horizontalOffset) / meshWidth_[0];
    int j = (y + verticalOffset) / meshWidth_[1];

    //deal with right boundary and top (sketch it!)
    if (pos_ == VRIGHT && i == size()[0] - 1)
    {
        i = i - 1;
    }
    if (pos_ == VTOP && j == size()[1] - 1)
    {
        j = j - 1;
    }

    //calculate missing grid points that frame the physical position point (x,y) and get corresponding values
    double xLeft = i * meshWidth_[0] - horizontalOffset;
    double xRight = (i + 1) * meshWidth_[0] - horizontalOffset;
    double yUp = (j + 1) * meshWidth_[1] - verticalOffset;
    double yDown = j * meshWidth_[1] - verticalOffset;

    double downLeft = (*this)(i, j);
    double downRight = (*this)(i + 1, j);
    double upLeft = (*this)(i, j + 1);
    double upRight = (*this)(i + 1, j + 1);

    //interpolate in x direction
    double downMid = downLeft + (downRight - downLeft) / (xRight - xLeft) * (x - xLeft);
    double upMid = upLeft + (upRight - upLeft) / (xRight - xLeft) * (x - xLeft);

    //interpolate in y direction
    double mid = downMid + (upMid - downMid) / (yUp - yDown) * (y - yDown);

    return mid;
}