#include <cassert>
#include <iomanip>
#include <iostream>

#include "../includes/field_variable.h"

FieldVariable::FieldVariable(const std::array<int, 2> size, vposition pos, const std::array<double, 2> physicalSize, const std::array<double, 2> meshWidth, double value) : Array2D<double>(size, value)
{
    //set position of corresponding variable on grid
    pos_ = pos;

    //calculate meshwidth in each direction
    meshWidth_ = meshWidth;

    //physical size in each direction
    physicalSize_ = physicalSize;

    //adapt offset according to position of field variable in every cell
    if (pos == VCENTRE)
    {
        horizontalOffset_ = meshWidth_[0] / 2;
        verticalOffset_ = meshWidth_[1] / 2;
    }
    else if (pos == VRIGHT)
    {
        verticalOffset_ = meshWidth_[1] / 2;
        horizontalOffset_ = 0;
    }
    else if (pos == VTOP)
    {
        horizontalOffset_ = meshWidth_[0] / 2;
        verticalOffset_ = 0;
    }
}

//set field variable matrix to data matrix
void FieldVariable::operator=(const Array2D<double> &result)
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
        myfile << std::setw(setw) << j - 1 << "|";
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

    //calculate index of grid point left below or equal to physical point (x,y)
    int i = (x + horizontalOffset_) / meshWidth_[0];
    int j = (y + verticalOffset_) / meshWidth_[1];

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
    double xLeft = i * meshWidth_[0] - horizontalOffset_;
    double xRight = (i + 1) * meshWidth_[0] - horizontalOffset_;
    double yUp = (j + 1) * meshWidth_[1] - verticalOffset_;
    double yDown = j * meshWidth_[1] - verticalOffset_;

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