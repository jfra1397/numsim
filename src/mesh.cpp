#include "../includes/mesh.h"

#include <algorithm> //forstr to int,double
#include <math.h>



Mesh::Mesh(std::array<int,2> nCells, const std::array<double, 2> physicalSize): flag_({nCells[0]+2, nCells[1]+2})

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

void Mesh::set_boundary_condition(std::vector<std::string> left, std::vector<std::string> right, std::vector<std::string> top, std::vector<std::string> bottom)
{
    for(auto it = std::begin(bottom); it != std::end(bottom); ++it)
    {
        std::vector<std::string> substr = cut(*it);

        for (int i = int(round(std::stod(substr[2])/physicalSize_[0]*nCells_[0])); i <= int(round(std::stod(substr[3])/physicalSize_[0]*nCells_[0])); i++)
        {
            if (substr[0] == "Velocity")
            {
                bottomBoundValues_[i][0] = std::stod(substr[4]);
                bottomBoundValues_[i][1] = std::stod(substr[5]);
                if (substr[1] == "Dirichlet") bottomBoundVelFlag_[i] = DIRICHLET;
                //else if(substr[1] == "Neumann") bottomBoundVelFlag_[i] = NEUMANN;
                else assert(false);
            }
            else if (substr[0] == "Pressure")
            {
                bottomBoundValues_[i][2] = std::stod(substr[4]);
                if (substr[1] == "Dirichlet") bottomBoundVelFlag_[i] = NEUMANN;
                //else if(substr[1] == "Neumann") bottomBoundVelFlag_[i] = DIRICHLET;
                else assert(false);
            }
            else assert(false);
        }
        

    }

    for(auto it = std::begin(top); it != std::end(top); ++it)
    {
        std::vector<std::string> substr = cut(*it);

        for (int i = int(round(std::stod(substr[2])/physicalSize_[0]*nCells_[0])); i <= int(round(std::stod(substr[3])/physicalSize_[0]*nCells_[0])); i++)
        {
            if (substr[0] == "Velocity")
            {
                topBoundValues_[i][0] = std::stod(substr[4]);
                topBoundValues_[i][1] = std::stod(substr[5]);
                if (substr[1] == "Dirichlet") topBoundVelFlag_[i] = DIRICHLET;
                //else if(substr[1] == "Neumann") topBoundVelFlag_[i] = NEUMANN;
                else assert(false);
            }
            else if (substr[0] == "Pressure")
            {
                bottomBoundValues_[i][2] = std::stod(substr[4]);
                if (substr[1] == "Dirichlet") topBoundVelFlag_[i] = NEUMANN;
                //else if(substr[1] == "Neumann") topBoundVelFlag_[i] = DIRICHLET;
                else assert(false);
            }
            else assert(false);
        }
        

    }

    for(auto it = std::begin(left); it != std::end(left); ++it)
    {
        std::vector<std::string> substr = cut(*it);

        for (int i = int(round(std::stod(substr[2])/physicalSize_[1]*nCells_[1])); i <= int(round(std::stod(substr[3])/physicalSize_[1]*nCells_[1])); i++)
        {
            if (substr[0] == "Velocity")
            {
                leftBoundValues_[i][0] = std::stod(substr[4]);
                leftBoundValues_[i][1] = std::stod(substr[5]);
                if (substr[1] == "Dirichlet") leftBoundVelFlag_[i] = DIRICHLET;
                //else if(substr[1] == "Neumann") leftBoundVelFlag_[i] = NEUMANN;
                else assert(false);
            }
            else if (substr[0] == "Pressure")
            {
                leftBoundValues_[i][2] = std::stod(substr[4]);
                if (substr[1] == "Dirichlet") leftBoundVelFlag_[i] = NEUMANN;
                //else if(substr[1] == "Neumann") leftBoundVelFlag_[i] = DIRICHLET;
                else assert(false);
            }
            else assert(false);
        }
        

    }
    for(auto it = std::begin(right); it != std::end(right); ++it)
    {
        std::vector<std::string> substr = cut(*it);

        for (int i = int(round(std::stod(substr[2])/physicalSize_[1]*nCells_[1])); i <= int(round(std::stod(substr[3])/physicalSize_[1]*nCells_[1])); i++)
        {
            if (substr[0] == "Velocity")
            {
                rightBoundValues_[i][0] = std::stod(substr[4]);
                rightBoundValues_[i][1] = std::stod(substr[5]);
                if (substr[1] == "Dirichlet") rightBoundVelFlag_[i] = DIRICHLET;
                //else if(substr[1] == "Neumann") rightBoundVelFlag_[i] = NEUMANN;
                else assert(false);
            }
            else if (substr[0] == "Pressure")
            {
                rightBoundValues_[i][2] = std::stod(substr[4]);
                if (substr[1] == "Dirichlet") rightBoundVelFlag_[i] = NEUMANN;
                //else if(substr[1] == "Neumann") rightBoundVelFlag_[i] = DIRICHLET;
                else assert(false);
            }
            else assert(false);
        }
        

    }
}


void Mesh::set_object_condition(std::vector<std::string> objects)
{
    for(auto it = std::begin(objects); it != std::end(objects); ++it)
    {
        std::vector<std::string> substr = cut(*it);
        CELLTYPE temp = EMPTY;
        if (substr[0] == "Rectangle")
        {
            if (substr.size() == 6)
            {
                if (substr[5] == "FLUID") temp = FLUID;
            }
            for (int j = int(ceil(std::stod(substr[2])/physicalSize_[1]*nCells_[1]))+1; j <= int(std::stod(substr[4])/physicalSize_[1]*nCells_[1]); j++)
            {
                for (int i = int(ceil(std::stod(substr[1])/physicalSize_[0]*nCells_[0]))+1; i <= int(std::stod(substr[3])/physicalSize_[0]*nCells_[0]); i++)
                {
                    flag_(i,j) = temp;

                }
            }
        }
        else if (substr[0] == "Triangle")
        {
            if (substr.size() == 6)
            {
                if (substr[5] == "FLUID") temp = FLUID;
            }
            double x1 = std::stod(substr[1])/physicalSize_[0]*nCells_[0], y1 = std::stod(substr[2])/physicalSize_[1]*nCells_[1];
            double x2 = std::stod(substr[3])/physicalSize_[0]*nCells_[0], y2 = std::stod(substr[4])/physicalSize_[1]*nCells_[1];
            double x3 = std::stod(substr[5])/physicalSize_[0]*nCells_[0], y3 = std::stod(substr[6])/physicalSize_[1]*nCells_[1];
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

                    if (!(has_neg && has_pos)){
                        flag_(i,j) = temp;
                    } 
                }
            }
        }
        else if (substr[0] == "Ellipse")
        {
            if (substr.size() == 6)
            {
                if (substr[5] == "FLUID") temp = FLUID;
            }
            double x = std::stod(substr[1])/physicalSize_[0]*nCells_[0], y = std::stod(substr[2])/physicalSize_[1]*nCells_[1];
            double a = std::stod(substr[3])/physicalSize_[0]*nCells_[0], b = std::stod(substr[4])/physicalSize_[1]*nCells_[1];
            for (int j = int(ceil(y-b)); j <= int((y+b+0.5)); j++)
            {
                for (int i = int(ceil(x-a)); i <= int((x+a+0.5)); i++)
                {
                    if ((i-0.5-x)*(i-0.5-x)/(a*a) + (j-0.5-y)*(j-0.5-y)/(b*b) <= 1){
                        flag_(i,j) = temp;
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








std::vector<std::string> Mesh::cut (const std::string &str)
{
    std::vector<std::string> substr;
        std::string temp = str;
        size_t found;
        while (true) 
        {
            found = temp.find(";");
            if (found == std::string::npos)
            {
                substr.push_back(temp);
                break;
            }
            substr.push_back(temp.substr(0,found));
            temp = temp.substr(found+1);

        }

        return substr;
}