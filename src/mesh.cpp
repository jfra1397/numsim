#include "../includes/mesh.h"

#include <algorithm> //forstr to int,double
#include <math.h>

void assertion_feedback(bool assertion, std::string msg)
{
    if (!assertion)
    {
        std::cout << msg << std::endl;
        abort();
    }
}

Mesh::Mesh(std::array<int, 2> nCells, const std::array<double, 2> physicalSize) : flag_({nCells[0] + 2, nCells[1] + 2}), objTemperatureValues_({nCells[0] + 2, nCells[1] + 2}), objTemperatureFlag_({nCells[0] + 2, nCells[1] + 2})

{
    physicalSize_ = physicalSize;

    //calculate meshwidth in each direction
    meshWidth_[0] = physicalSize[0] / (double)nCells[0];
    meshWidth_[1] = physicalSize[1] / (double)nCells[1];
    nCells_ = nCells;

    leftBoundVelFlag_.resize(nCells[1] + 2, DIRICHLET);
    rightBoundVelFlag_.resize(nCells[1] + 2, DIRICHLET);
    topBoundVelFlag_.resize(nCells[0] + 2, DIRICHLET);
    bottomBoundVelFlag_.resize(nCells[0] + 2, DIRICHLET);

    leftBoundTempFlag_.resize(nCells[1] + 2, NEUMANN);
    rightBoundTempFlag_.resize(nCells[1] + 2, NEUMANN);
    topBoundTempFlag_.resize(nCells[0] + 2, NEUMANN);
    bottomBoundTempFlag_.resize(nCells[0] + 2, NEUMANN);

    leftBoundValues_.resize(nCells[1] + 2, {0, 0, 0, 0});
    rightBoundValues_.resize(nCells[1] + 2, {0, 0, 0, 0});
    topBoundValues_.resize(nCells[0] + 2, {0, 0, 0, 0});
    bottomBoundValues_.resize(nCells[0] + 2, {0, 0, 0, 0});
    for (int i = 0; i < flag_.size()[0]; i++)
    {
        flag_(i, 0) = BOTTOMBOUND;
        flag_(i, flag_.size()[1] - 1) = TOPBOUND;
    }
    for (int j = 0; j < flag_.size()[1]; j++)
    {
        flag_(0, j) = LEFTBOUND;
        flag_(flag_.size()[0] - 1, j) = RIGHTBOUND;
    }
}

void Mesh::set_boundary_condition(std::vector<Obstacle> objects)
{
    for (auto it = std::begin(objects); it != std::end(objects); ++it)
    {
        if (it->type == BOTTOMBOUND)
        {
            int i_start = int(round(it->position[0] / physicalSize_[0] * nCells_[0]));
            int i_stop = int(round(it->position[1] / physicalSize_[0] * nCells_[0]));
            assertion_feedback(i_start >= 0, "Start position of bottom bound too small!");
            assertion_feedback(i_stop < nCells_[0] + 2, "End position of bottom bound too big!");


            for (int i = i_start; i <= int(round(it->position[1] / physicalSize_[0] * nCells_[0])); i++)
            {
                bottomBoundValues_[i][0] = it->velValue[0];
                bottomBoundValues_[i][1] = it->velValue[1];
                bottomBoundValues_[i][2] = it->pValue;
                bottomBoundValues_[i][3] = it->tValue;
                bottomBoundVelFlag_[i] = it->velType;
                bottomBoundTempFlag_[i] = it->tType;
            }
        }
        else if (it->type == TOPBOUND)
        {
            int i_start = int(round(it->position[0] / physicalSize_[0] * nCells_[0]));
            int i_stop = int(round(it->position[1] / physicalSize_[0] * nCells_[0]));
            assertion_feedback(i_start >= 0, "Start position of top bound too small!");
            assertion_feedback(i_stop < nCells_[0] + 2, "End position of top bound too big!");

            for (int i = i_start; i <= i_stop; i++)
            {
                topBoundValues_[i][0] = it->velValue[0];
                topBoundValues_[i][1] = it->velValue[1];
                topBoundValues_[i][2] = it->pValue;
                topBoundValues_[i][3] = it->tValue;
                topBoundVelFlag_[i] = it->velType;
                topBoundTempFlag_[i] = it->tType;
            }
        }
        else if (it->type == LEFTBOUND)
        {
            int i_start = int(round(it->position[0] / physicalSize_[1] * nCells_[1]));
            int i_stop = int(round(it->position[1] / physicalSize_[1] * nCells_[1]));
            assertion_feedback(i_start >= 0, "Start position of left bound too small!");
            assertion_feedback(i_stop < nCells_[0] + 2, "End position of left bound too big!");

            for (int i = i_start; i <= i_stop; i++)
            {
                leftBoundValues_[i][0] = it->velValue[0];
                leftBoundValues_[i][1] = it->velValue[1];
                leftBoundValues_[i][2] = it->pValue;
                leftBoundValues_[i][3] = it->tValue;
                leftBoundVelFlag_[i] = it->velType;
                leftBoundTempFlag_[i] = it->tType;
            }
        }
        else if (it->type == RIGHTBOUND)
        {
            int i_start = int(round(it->position[0] / physicalSize_[1] * nCells_[1]));
            int i_stop = int(round(it->position[1] / physicalSize_[1] * nCells_[1]));
            assertion_feedback(i_start >= 0, "Start position of right bound too small!");
            assertion_feedback(i_stop < nCells_[0] + 2, "End position of right bound too big!");

            for (int i = i_start; i <= i_stop; i++)
            {
                rightBoundValues_[i][0] = it->velValue[0];
                rightBoundValues_[i][1] = it->velValue[1];
                rightBoundValues_[i][2] = it->pValue;
                rightBoundValues_[i][3] = it->tValue;
                rightBoundVelFlag_[i] = it->velType;
                rightBoundTempFlag_[i] = it->tType;
            }
        }
        else if (it->type == EMPTY || it->type == FLUID)
        {
            if (it->shape == RECTANGLE)
            {
                for (int j = int(ceil(it->position[1] / physicalSize_[1] * nCells_[1])) + 1; j <= int(it->position[3] / physicalSize_[1] * nCells_[1]); j++)
                {
                    if (j < 1 || j > nCells_[1])
                        continue;

                    for (int i = int(ceil(it->position[0] / physicalSize_[0] * nCells_[0])) + 1; i <= int(it->position[2] / physicalSize_[0] * nCells_[0]); i++)
                    {
                        if (i < 1 || i > nCells_[0])
                            continue;
                        flag_(i, j) = it->type;
                        objTemperatureFlag_(i, j) = it->tType;
                        objTemperatureValues_(i, j) = it->tValue;
                    }
                }
            }
            else if (it->shape == TRIANGLE)
            {
                double x1 = it->position[0] / physicalSize_[0] * nCells_[0], y1 = it->position[1] / physicalSize_[1] * nCells_[1];
                double x2 = it->position[2] / physicalSize_[0] * nCells_[0], y2 = it->position[3] / physicalSize_[1] * nCells_[1];
                double x3 = it->position[4] / physicalSize_[0] * nCells_[0], y3 = it->position[5] / physicalSize_[1] * nCells_[1];
                for (int j = int(std::min(y1, std::min(y2, y3))); j <= int(ceil(std::max(y1, std::max(y2, y3)))); j++)
                {
                    if (j < 1 || j > nCells_[1])
                        continue;

                    for (int i = int(std::min(x1, std::min(x2, x3))); i <= int(ceil(std::max(x1, std::max(x2, x3)))); i++)
                    {
                        if (i < 1 || i > nCells_[0])
                            continue;
                        double d1, d2, d3;
                        d1 = (i - 0.5 - x2) * (y1 - y2) - (x1 - x2) * (j - 0.5 - y2);
                        d2 = (i - 0.5 - x3) * (y2 - y3) - (x2 - x3) * (j - 0.5 - y3);
                        d3 = (i - 0.5 - x1) * (y3 - y1) - (x3 - x1) * (j - 0.5 - y1);
                        bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
                        bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

                        if (!(has_neg && has_pos))
                        {
                            flag_(i, j) = it->type;
                            objTemperatureFlag_(i, j) = it->tType;
                            objTemperatureValues_(i, j) = it->tValue;
                        }
                    }
                }
            }
            else if (it->shape == ELLIPSE)
            {
                double x = it->position[0] / physicalSize_[0] * nCells_[0], y = it->position[1] / physicalSize_[1] * nCells_[1];
                double a = it->position[2] / physicalSize_[0] * nCells_[0], b = it->position[3] / physicalSize_[1] * nCells_[1];
                for (int j = int(ceil(y - b)); j <= int((y + b + 0.5)); j++)
                {
                    if (j < 1 || j > nCells_[1])
                        continue;

                    for (int i = int(ceil(x - a)); i <= int((x + a + 0.5)); i++)
                    {
                        if (i < 1 || i > nCells_[0])
                            continue;

                        if ((i - 0.5 - x) * (i - 0.5 - x) / (a * a) + (j - 0.5 - y) * (j - 0.5 - y) / (b * b) <= 1)
                        {
                            flag_(i, j) = it->type;
                            objTemperatureFlag_(i, j) = it->tType;
                            objTemperatureValues_(i, j) = it->tValue;
                        }
                    }
                }
            }
        }
    }
    bool flatten = true;

    while (flatten)
    {
        flatten = false;
        for (int j = 1; j < flag_.size()[1] - 1; j++)
        {
            for (int i = 1; i < flag_.size()[0] - 1; i++)
            {
                if (flag_(i, j) != FLUID)
                {
                    if (flag_(i - 1, j) == FLUID && flag_(i + 1, j) == FLUID)
                    {
                        flag_(i, j) = FLUID;
                        flatten = true;
                    }
                    else if (flag_(i, j - 1) == FLUID && flag_(i, j + 1) == FLUID)
                    {
                        flag_(i, j) = FLUID;
                        flatten = true;
                    }
                    else if (flag_(i - 1, j) == FLUID && flag_(i, j - 1) == FLUID)
                        flag_(i, j) = OBJBOTTOMLEFT;
                    else if (flag_(i + 1, j) == FLUID && flag_(i, j - 1) == FLUID)
                        flag_(i, j) = OBJBOTTOMRIGHT;
                    else if (flag_(i + 1, j) == FLUID && flag_(i, j + 1) == FLUID)
                        flag_(i, j) = OBJTOPRIGHT;
                    else if (flag_(i - 1, j) == FLUID && flag_(i, j + 1) == FLUID)
                        flag_(i, j) = OBJTOPLEFT;
                    else if (flag_(i + 1, j) == FLUID)
                        flag_(i, j) = OBJRIGHT;
                    else if (flag_(i - 1, j) == FLUID)
                        flag_(i, j) = OBJLEFT;
                    else if (flag_(i, j + 1) == FLUID)
                        flag_(i, j) = OBJTOP;
                    else if (flag_(i, j - 1) == FLUID)
                        flag_(i, j) = OBJBOTTOM;
                }
            }
        }
    }
}