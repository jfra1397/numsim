#include "../includes/mesh.h"

#include <algorithm> //forstr to int,double
#include <math.h>



Mesh::Mesh(std::array<int,2> nCells, const std::array<double, 2> physicalSize): flag_({nCells[0]+2, nCells[1]+2}),objTemperatureValues_({nCells[0]+2, nCells[1]+2}),objTemperatureFlag_({nCells[0]+2, nCells[1]+2})

{
     physicalSize_ = physicalSize;

    //calculate meshwidth in each direction
    meshWidth_[0] = physicalSize[0] / (double)nCells[0];
    meshWidth_[1] = physicalSize[1] / (double)nCells[1];
    nCells_ = nCells;

    leftBoundVelFlag_.resize(nCells[1]+2, DIRICHLET);
    rightBoundVelFlag_.resize(nCells[1]+2, DIRICHLET);
    topBoundVelFlag_.resize(nCells[0]+2, DIRICHLET);
    bottomBoundVelFlag_.resize(nCells[0]+2, DIRICHLET);

    leftBoundValues_.resize(nCells[1]+2, {0,0,0});
    rightBoundValues_.resize(nCells[1]+2, {0,0,0});
    topBoundValues_.resize(nCells[0]+2, {0,0,0});
    bottomBoundValues_.resize(nCells[0]+2, {0,0,0});
    for (int i = 0; i < flag_.size()[0]; i++) flag_(i,0) = flag_(i, flag_.size()[1]-1) = BOUND;
    for (int j = 0; j < flag_.size()[1]; j++) flag_(0,j) = flag_(flag_.size()[0]-1, j) = BOUND;
}

void Mesh::set_boundary_condition(std::vector<std::vector<double>> boundValues, std::vector<std::array<BOUNDARYTYPE,5>> boundTypes)
{
    for (int iter = 0; iter < boundTypes.size() && iter < boundValues.size(); iter++)
    {
        if (boundTypes[iter][TYPE] == BOTTOMBOUND)
        {
            for (int i = int(round(boundValues[iter][POSITION]/physicalSize_[0]*nCells_[0])); i <= int(round(boundValues[iter][POSITION+1]/physicalSize_[0]*nCells_[0])); i++)
            {

                bottomBoundValues_[i][0] = boundValues[iter][U];
                bottomBoundValues_[i][1] = boundValues[iter][V];
                bottomBoundValues_[i][2] = boundValues[iter][P];
                bottomBoundValues_[i][3] = boundValues[iter][T];
                if (boundTypes[iter][U] == NM) bottomBoundVelFlag_[i] = NEUMANN;
                else bottomBoundVelFlag_[i] = DIRICHLET;
                if (boundTypes[iter][T] == NM) bottomBoundTempFlag_[i] = NEUMANN;
                else bottomBoundTempFlag_[i] = DIRICHLET;
            }
        }
        else if (boundTypes[iter][TYPE] == TOPBOUND)
        {
            for (int i = int(round(boundValues[iter][POSITION]/physicalSize_[0]*nCells_[0])); i <= int(round(boundValues[iter][POSITION+1]/physicalSize_[0]*nCells_[0])); i++)
            {
                topBoundValues_[i][0] = boundValues[iter][U];
                topBoundValues_[i][1] = boundValues[iter][V];
                topBoundValues_[i][2] = boundValues[iter][P];
                topBoundValues_[i][3] = boundValues[iter][T];
                if (boundTypes[iter][U] == NM) topBoundVelFlag_[i] = NEUMANN;
                else topBoundVelFlag_[i] = DIRICHLET;
                if (boundTypes[iter][T] == NM) topBoundTempFlag_[i] = NEUMANN;
                else topBoundTempFlag_[i] = DIRICHLET;
            }
        }
        else if (boundTypes[iter][TYPE] == LEFTBOUND)
        {
            for (int i = int(round(boundValues[iter][POSITION]/physicalSize_[1]*nCells_[1])); i <= int(round(boundValues[iter][POSITION+1]/physicalSize_[1]*nCells_[1])); i++)
            {
                leftBoundValues_[i][0] = boundValues[iter][U];
                leftBoundValues_[i][1] = boundValues[iter][V];
                leftBoundValues_[i][2] = boundValues[iter][P];
                leftBoundValues_[i][3] = boundValues[iter][T];
                if (boundTypes[iter][U] == NM) leftBoundVelFlag_[i] = NEUMANN;
                else leftBoundVelFlag_[i] = DIRICHLET;
                if (boundTypes[iter][T] == NM) leftBoundTempFlag_[i] = NEUMANN;
                else leftBoundTempFlag_[i] = DIRICHLET;   
            }
        }
        else if (boundTypes[iter][TYPE] == RIGHTBOUND)
        {
            for (int i = int(round(boundValues[iter][POSITION]/physicalSize_[1]*nCells_[1])); i <= int(round(boundValues[iter][POSITION+1]/physicalSize_[1]*nCells_[1])); i++)
            {
                rightBoundValues_[i][0] = boundValues[iter][U];
                rightBoundValues_[i][1] = boundValues[iter][V];
                rightBoundValues_[i][2] = boundValues[iter][P];
                rightBoundValues_[i][3] = boundValues[iter][T];
                if (boundTypes[iter][U] == NM) rightBoundVelFlag_[i] = NEUMANN;
                else rightBoundVelFlag_[i] = DIRICHLET;
                if (boundTypes[iter][T] == NM) rightBoundVelFlag_[i] = NEUMANN;
                else rightBoundVelFlag_[i] = DIRICHLET; 
            }
        }
        else if (boundTypes[iter][TYPE] == RECTANGLE)
        {
            for (int j = int(ceil(boundValues[iter][POSITION]/physicalSize_[1]*nCells_[1]))+1; j <= int(boundValues[iter][POSITION+2]/physicalSize_[1]*nCells_[1]); j++)
            {
                for (int i = int(ceil(boundValues[iter][POSITION+1]/physicalSize_[0]*nCells_[0]))+1; i <= int(boundValues[iter][POSITION+3]/physicalSize_[0]*nCells_[0]); i++)
                {
                    flag_(i,j) = EMPTY;
                    if (boundTypes[iter][T] == NM) objTemperatureFlag_(i,j) = ;
                    else objTemperatureFlag_(i,j) = ;
                    objTemperatureValues_(i,j) = boundValues[iter][T];
                }
            }
        }
        else if (boundTypes[iter][TYPE] == TRIANGLE)
        {
            double x1 = boundValues[iter][POSITION]/physicalSize_[0]*nCells_[0], y1 = boundValues[iter][POSITION+1]/physicalSize_[1]*nCells_[1];
            double x2 = boundValues[iter][POSITION+2]/physicalSize_[0]*nCells_[0], y2 = boundValues[iter][POSITION+3]/physicalSize_[1]*nCells_[1];
            double x3 = boundValues[iter][POSITION+4]/physicalSize_[0]*nCells_[0], y3 = boundValues[iter][POSITION+5]/physicalSize_[1]*nCells_[1];
            for (int j = int(std::min(y1,std::min(y2,y3))); j <= int(ceil(std::max(y1,std::max(y2,y3)))); j++)
            {
                for (int i = int(std::min(x1,std::min(x2,x3))); i <= int(ceil(std::max(x1,std::max(x2,x3)))); i++)
                {
                    double d1,d2,d3;
                    d1 = (i-0.5 - x2) * (y1 - y2) - (x1 - x2) * (j-0.5 - y2);
                    d2 = (i-0.5 - x3) * (y2 - y3) - (x2 - x3) * (j-0.5 - y3);
                    d3 = (i-0.5 - x1) * (y3 - y1) - (x3 - x1) * (j-0.5 - y1);
                    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
                    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

                    if (!(has_neg && has_pos))
                    {
                        flag_(i,j) = EMPTY;
                        if (boundTypes[iter][T] == NM) objTemperatureFlag_(i,j) = ;
                        else objTemperatureFlag_(i,j) = ;
                        objTemperatureValues_(i,j) = boundValues[iter][T];
                    }
                }
            }
        }
        else if (boundTypes[iter][TYPE] == CIRLCE)
        {
            double x = boundValues[iter][POSITION]/physicalSize_[0]*nCells_[0], y = boundValues[iter][POSITION+1]/physicalSize_[1]*nCells_[1];
            double a = boundValues[iter][POSITION+2]/physicalSize_[0]*nCells_[0], b = boundValues[iter][POSITION+3]/physicalSize_[1]*nCells_[1];
            for (int j = int(ceil(y-b)); j <= int((y+b+0.5)); j++)
            {
                for (int i = int(ceil(x-a)); i <= int((x+a+0.5)); i++)
                {
                    if ((i-0.5-x)*(i-0.5-x)/(a*a) + (j-0.5-y)*(j-0.5-y)/(b*b) <= 1){
                        flag_(i,j) = EMPTY;
                        if (boundTypes[iter][T] == NM) objTemperatureFlag_(i,j) = ;
                        else objTemperatureFlag_(i,j) = ;
                        objTemperatureValues_(i,j) = boundValues[iter][T];
                    } 
                
                }
            }
        }
    }
    bool flatten = true;

    while (flatten)
    {
        flatten = false;
        for (int j = 1; j < flag_.size()[1]-1; j++)
        {
            for (int i = 1; i < flag_.size()[0]-1; i++)
            {
                if (flag_(i,j) != FLUID)
                {
                    if(flag_(i-1,j) == FLUID && flag_(i+1,j) == FLUID)
                    {
                        flag_(i,j) = FLUID;
                        flatten = true;
                    }
                    else if(flag_(i,j-1) == FLUID && flag_(i,j+1) == FLUID)
                    {
                        flag_(i,j) = FLUID;
                        flatten = true;
                    }
                    else if(flag_(i-1,j) == FLUID && flag_(i,j-1) == FLUID) flag_(i,j) = OBJBOTTOMLEFT;
                    else if(flag_(i+1,j) == FLUID && flag_(i,j-1) == FLUID) flag_(i,j) = OBJBOTTOMRIGHT;
                    else if(flag_(i+1,j) == FLUID && flag_(i,j+1) == FLUID) flag_(i,j) = OBJTOPRIGHT;
                    else if(flag_(i-1,j) == FLUID && flag_(i,j+1) == FLUID) flag_(i,j) = OBJTOPLEFT;
                    else if(flag_(i+1,j) == FLUID ) flag_(i,j) = OBJRIGHT;
                    else if(flag_(i-1,j) == FLUID ) flag_(i,j) = OBJLEFT;
                    else if(flag_(i,j+1) == FLUID ) flag_(i,j) = OBJTOP;
                    else if(flag_(i,j-1) == FLUID ) flag_(i,j) = OBJBOTTOM;
                }
            }
        }

    }
}