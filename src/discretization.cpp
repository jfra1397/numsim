#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#include "../includes/discretization.h"


Discretization::Discretization(const std::array<int,2> nCells, const std::array<double,2> physicalSize):
StaggeredGrid(nCells,physicalSize)
{
    physicalSize_ = physicalSize;
    meshWidth_[0] = physicalSize[0]/(double) nCells[0];
    meshWidth_[1] = physicalSize[1]/(double) nCells[1];
    nCells_ = nCells;
}


//! compute the 2nd derivative ∂^2 u / ∂x^2
double Discretization::computeD2uDx2(int i, int j) const
{
    double result = (u(i+1,j) - 2*u(i,j) + u(i-1,j))/(meshWidth()[0]*meshWidth()[0]);
    return result;
}

//! compute the 2nd derivative ∂^2 u / ∂y^2
double Discretization::computeD2uDy2(int i, int j) const
{
    double result = (u(i,j+1) - 2*u(i,j) + u(i,j-1))/(meshWidth()[1]*meshWidth()[1]);
    return result;
}

//! compute the 2nd derivative ∂^2 v / ∂x^2
double Discretization::computeD2vDx2(int i, int j) const
{
    double result = (v(i+1,j) - 2*v(i,j) + v(i-1,j))/(meshWidth()[0]*meshWidth()[0]);
    return result;
}

//! compute the 2nd derivative ∂^2 v / ∂y^2
double Discretization::computeD2vDy2(int i, int j) const
{
    double result = (v(i,j+1) - 2*v(i,j) + v(i,j-1))/(meshWidth()[1]*meshWidth()[1]);
    return result;
}

//! compute the 1st derivative ∂ F / ∂x
double Discretization::computeDFDx(int i, int j) const
{
    double result = (f(i,j)-f(i-1,j))/meshWidth()[0];
    return result;
}

//! compute the 1st derivative ∂ G / ∂y
double Discretization::computeDGDy(int i, int j) const
{
    double result = (g(i,j)-g(i,j-1))/meshWidth()[1];
    return result;
}

//! compute the 1st derivative ∂ p / ∂x
double Discretization::computeDpDx(int i, int j) const
{
    double result = (p(i+1,j)-p(i,j))/meshWidth()[0];
    return result;
}

//! compute the 1st derivative ∂ p / ∂y
double Discretization::computeDpDy(int i, int j) const
{
    double result = (p(i,j+1) - p(i,j))/meshWidth()[1];
    return result;
}

//! compute the 2nd derivative ∂^2 p / ∂x^2
double Discretization::computeD2pDx2(int i, int j) const
{
    double result = (p(i+1,j) - 2*p(i,j) + p(i-1,j))/(meshWidth()[0]*meshWidth()[0]);
    return result;
}

//! compute the 2nd derivative ∂^2 p / ∂y^2
double Discretization::computeD2pDy2(int i, int j) const
{
    double result = (p(i,j+1) - 2*p(i,j) + p(i,j-1))/(meshWidth()[1]*meshWidth()[1]);
    return result;
}

const std::array<double,2> Discretization::meshWidth() const
{
    return meshWidth_;
}

const std::array<int,2> Discretization::nCells() const
{
    return nCells_;
}


void Discretization::write_to_file(int fileNo, double time) const
{
    // create "out" subdirectory if it does not yet exist
    int returnValue = system("mkdir -p out");
    if (returnValue != 0) std::cout << "Could not create subdirectory \"out\"." << std::endl;

    // Assemble the filename
    std::stringstream fileName;
    fileName << "out/output_" << std::setw(4) << std::setfill('0') << fileNo << ".txt";

    //std::cout << "Write file \"" << fileName.str() << "\"." << std::endl;

    std::ofstream myfile;
    myfile.open(fileName.str());
    myfile << "t: " << time << std::endl;
    myfile << "nCells: " << nCells_[0] << "x" << nCells_[1] << ", dx: " << meshWidth()[0] << ", dx: " << meshWidth()[1] <<std::endl;
    myfile.close();
    
    u().wirte_to_file(fileName.str(), "u", true);
    v().wirte_to_file(fileName.str(), "v", true);
    p().wirte_to_file(fileName.str(), "p", true);
    f().wirte_to_file(fileName.str(), "f", true);
    g().wirte_to_file(fileName.str(), "g", true);
    rhs().wirte_to_file(fileName.str(), "rhs", true);

}