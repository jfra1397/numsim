#include <cassert>
#include <iomanip>


#include "../includes/field_variable.h"

FieldVariable::FieldVariable(const std::array<int,2> size, vposition pos):
Array2D({0,0})
{
    pos_ = pos;
    topBoundType = DIRICHLET;
    bottomBoundType = DIRICHLET;
    leftBoundType = DIRICHLET;
    rightBoundType = DIRICHLET;
    
    int sizex = size[0], sizey = size[1];
    if (pos == VCENTRE)
    {
        sizex += 2;
        sizey += 2;
        // allocate data, initialize to 0
        resize({sizex, sizey});
        horizontalBoundInterpolate = true;
        verticalBoundInterpolate = true;

    }
    else if (pos == VRIGHT)
    {
        sizex += 1;
        sizey += 2;
        // allocate data, initialize to 0
        resize({sizex, sizey});
        horizontalBoundInterpolate = false;
        verticalBoundInterpolate = true;

    }
    else if (pos == VTOP)
    {
        sizex += 2;
        sizey += 1;
        // allocate data, initialize to 0
        resize({sizex, sizey});
        horizontalBoundInterpolate = true;
        verticalBoundInterpolate = false;

    }
}



int FieldVariable::set_boundary_type(btype top, btype bottom, btype left, btype right)
{
    topBoundType = top;
    bottomBoundType = bottom;
    leftBoundType = left;
    rightBoundType = right;

    return 0;
}

int FieldVariable::set_boundary(double bottomBound, double rightBound, double topBound, double leftBound, double h)
{
    int i,j;
    j = size()[1] - 1;
    for (i = 1; i < size()[0]-1; i++)
    {
        if (topBoundType == DIRICHLET)
        {
            if (verticalBoundInterpolate)
            {
                (*this)(i,j) = 2*topBound - (*this)(i,j-1);
            }
            else
            {
                (*this)(i,j) = topBound;
            }
            

        }
        else if (topBoundType == NEUMANN)
        {
            (*this)(i,j) = topBound*h + (*this)(i,j-1);
        }

    }
    j = 0;
    for (i = 1; i < size()[0]-1; i++)
    {
        if (bottomBoundType == DIRICHLET)
        {
            if (verticalBoundInterpolate)
            {
                (*this)(i,j) = 2*bottomBound - (*this)(i,j+1);
            }
            else
            {
                (*this)(i,j) = bottomBound;
            }
            

        }
        else if (bottomBoundType == NEUMANN)
        {
            (*this)(i,j) = bottomBound*h + (*this)(i,j+1);
        }

    }
    i = 0;
    for (j = 0; j < size()[1]; j++)
    {
        if (leftBoundType == DIRICHLET)
        {
            if (horizontalBoundInterpolate)
            {
                (*this)(i,j) = 2*leftBound - (*this)(i+1,j);
            }
            else
            {
                (*this)(i,j) = leftBound;
            }
            

        }
        else if (leftBoundType == NEUMANN)
        {
            (*this)(i,j) = leftBound*h + (*this)(i+1,j);
        }

    }
    i = size()[0]-1;
    for (j = 0; j < size()[1]; j++)
    {
        if (rightBoundType == DIRICHLET)
        {
            if (horizontalBoundInterpolate)
            {
                (*this)(i,j) = 2*rightBound - (*this)(i-1,j);
            }
            else
            {
                (*this)(i,j) = rightBound;
            }
            

        }
        else if (rightBoundType == NEUMANN)
        {
            (*this)(i,j) = rightBound*h + (*this)(i-1,j);
        }

    }
    return 0;
}


void FieldVariable::operator= (const Array2D &result)
{
    set_data(result);
}


void FieldVariable::wirte_to_file(std::string fileName, std::string name, bool append) const
{
    std::ofstream myfile;

    if (append) myfile.open(fileName, std::ios::out | std::ios::app);
    else myfile.open(fileName, std::ios::out | std::ios::trunc);
    myfile << name <<" (" << size()[0]  << "x" << size()[1] << "):" << std::endl;

    myfile << std::right;
    myfile.precision(5);

    int setw = 14;
    int ii = -1;
    myfile << std::setw(setw+1) << "|";
    for (int i = 0; i < size()[0]; i++)
    {
        myfile << std::setw(setw) << ii;
        ii += 1; 
    }

    myfile << std::endl;

    for (int i = 0; i <= setw*(size()[0]+1); i++)
    {
        myfile << "-";
    }
    
    myfile << std::endl;



    ii = -1;
    for(int j = size()[1] - 1; j>= 0 ;j--)
    {
        myfile << std::setw(setw) << ii << "|";
        ii += 1;
        for (int i=0; i<size()[0]; i++)
        {
            myfile << std::setw(setw) << (*this)(i,j);
        }
        myfile << std::endl;
    }
    myfile << std::endl;
    myfile.close();

}


double FieldVariable::interpolateAt(double x, double y) const
{
    double meshX, meshY;

    double verticalOffset = 0, horizontalOffset = 0;

    if(pos_ == VCENTRE)
    {
        horizontalOffset = meshX/2;
        verticalOffset = meshY/2;
    }
    else if (pos_ == VRIGHT) verticalOffset = meshY/2;
    else if (pos_ == VTOP) horizontalOffset = meshX/2;

    int i = (x+horizontalOffset)/meshX;
    int j = (y+verticalOffset)/meshY;
    double xLeft = i*meshX - horizontalOffset;
    double xRight = (i+1)*meshX - horizontalOffset;
    double yUp = j*meshY - verticalOffset;
    double yDown = j*meshY - verticalOffset;

    double DownLeft = (*this)(i,j);
    double DownRight = (*this)(i+1,j);
    double UpLeft = (*this)(i,j+1);
    double UpRight = (*this)(i+1,j+1);

    double DownMid = DownLeft + (DownRight-DownLeft)/(xRight-xLeft) * (x-xLeft);
    double UpMid = UpLeft + (UpRight-UpLeft)/(xRight-xLeft) * (x-xLeft);

    double Mid = DownMid+ (UpMid - DownMid)/(yUp-yDown) * (y-yDown);

    return Mid;
}