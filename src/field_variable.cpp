#include <iostream>

#include "../includes/field_variable.h"


int FieldVariable::set_boundary_type(btype top, btype bottom, btype left, btype right)
{
    topBound = top;
    bottomBound = bottom;
    leftBound = left;
    rightBound = right;

    return 0;
}

int FieldVariable::set_boundary(bposition pos, double bound, bool interpolate, double h)
{
    int i,j;
    if (pos == TOP)
    {
        j = size()[1] - 1;
        for (i = 1; i < size()[0]-1; i++)
        {
            if (topBound == DIRICHLET)
            {
                if (interpolate)
                {
                   (*this)(i,j) = 2*bound - (*this)(i,j-1);
                }
                else
                {
                    (*this)(i,j) = bound;
                }
                

            }
            else if (topBound == NEUMANN)
            {
                (*this)(i,j) = bound*h - (*this)(i,j-1);
            }

        }
    }
    else if (pos == BOTTOM)
    {
        j = 0;
        for (i = 1; i < size()[0]-1; i++)
        {
            if (bottomBound == DIRICHLET)
            {
                if (interpolate)
                {
                   (*this)(i,j) = 2*bound - (*this)(i,j+1);
                }
                else
                {
                    (*this)(i,j) = bound;
                }
                

            }
            else if (bottomBound == NEUMANN)
            {
                (*this)(i,j) = bound*h - (*this)(i,j+1);
            }

        }
    }
    else if (pos == LEFT)
    {
        i = 0;
        for (j = 1; j < size()[1]-1; j++)
        {
            if (leftBound == DIRICHLET)
            {
                if (interpolate)
                {
                   (*this)(i,j) = 2*bound - (*this)(i+1,j);
                }
                else
                {
                    (*this)(i,j) = bound;
                }
                

            }
            else if (leftBound == NEUMANN)
            {
                (*this)(i,j) = bound*h - (*this)(i+1,j);
            }

        }
    }
    else if (pos == RIGHT)
    {
        i = size()[0]-1;
        for (j = 1; j < size()[1]-1; j++)
        {
            if (rightBound == DIRICHLET)
            {
                if (interpolate)
                {
                   (*this)(i,j) = 2*bound - (*this)(i-1,j);
                }
                else
                {
                    (*this)(i,j) = bound;
                }
                

            }
            else if (rightBound == NEUMANN)
            {
                (*this)(i,j) = bound*h - (*this)(i-1,j);
            }

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