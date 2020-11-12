#include <iostream>

#include "../includes/field_variable.h"

FieldVariable::FieldVariable(std::array<int,2> size, vposition pos):
Array2D({0,0})
{
    if (pos == VCENTRE)
    {
        size[0] += 2;
        size[1] += 2;
        // allocate data, initialize to 0
        resize(size);
        horizontalBoundInterpolate = true;
        verticalBoundInterpolate = true;

    }
    else if (pos == VRIGHT)
    {
        size[0] += 1;
        size[1] += 2;
        // allocate data, initialize to 0
        resize(size);
        horizontalBoundInterpolate = false;
        verticalBoundInterpolate = true;

    }
    else if (pos == VTOP)
    {
        size[0] += 2;
        size[1] += 1;
        // allocate data, initialize to 0
        resize(size);
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
            (*this)(i,j) = topBound*h - (*this)(i,j-1);
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
            (*this)(i,j) = bottomBound*h - (*this)(i,j+1);
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
            (*this)(i,j) = leftBound*h - (*this)(i+1,j);
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
            (*this)(i,j) = rightBound*h - (*this)(i-1,j);
        }

    }
    return 0;
}


void FieldVariable::print() const
{
    for(int j = size()[1] - 1; j>= 0 ;j--)
    {
        for (int i=0; i<size()[0]; i++)
        {
            std::cout << (*this)(i,j) << "  ";
        }
        std::cout << std::endl;
    }
}