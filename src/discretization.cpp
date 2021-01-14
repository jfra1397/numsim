#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "../includes/discretization.h"

Discretization::Discretization(const std::array<int, 2> nCells, const std::array<double, 2> physicalSize) : StaggeredGrid(nCells, physicalSize)
{
}

//compute the 2nd derivative ∂^2 u / ∂x^2
double Discretization::computeD2uDx2(int i, int j) const
{
    double denominator = (dx() * dx());
    return (u(i + 1, j) - 2 * u(i, j) + u(i - 1, j)) / denominator;
}

//compute the 2nd derivative ∂^2 u / ∂y^2
double Discretization::computeD2uDy2(int i, int j) const
{
    double denominator = (dy() * dy());
    return (u(i, j + 1) - 2 * u(i, j) + u(i, j - 1)) / denominator;
}

//compute the 2nd derivative ∂^2 v / ∂x^2
double Discretization::computeD2vDx2(int i, int j) const
{
    double denominator = (dx() * dx());
    return (v(i + 1, j) - 2 * v(i, j) + v(i - 1, j)) / denominator;
}

//compute the 2nd derivative ∂^2 v / ∂y^2
double Discretization::computeD2vDy2(int i, int j) const
{
    double denominator = (dy() * dy());
    return (v(i, j + 1) - 2 * v(i, j) + v(i, j - 1)) / denominator;
}

//compute the 1st derivative ∂ F / ∂x
double Discretization::computeDFDx(int i, int j) const
{
    return (f(i, j) - f(i - 1, j)) / dx();
}

//compute the 1st derivative ∂ G / ∂y
double Discretization::computeDGDy(int i, int j) const
{
    return (g(i, j) - g(i, j - 1)) / dy();
}

//compute the 1st derivative ∂ p / ∂x
double Discretization::computeDpDx(int i, int j) const
{
    return (p(i + 1, j) - p(i, j)) / dx();
}

//compute the 1st derivative ∂ p / ∂y
double Discretization::computeDpDy(int i, int j) const
{
    return (p(i, j + 1) - p(i, j)) / dy();
}

//compute the 2nd derivative ∂^2 p / ∂x^2
double Discretization::computeD2pDx2(int i, int j) const
{
    double denominator = (dx() * dx());
    return (p(i + 1, j) - 2 * p(i, j) + p(i - 1, j)) / denominator;
}

//compute the 2nd derivative ∂^2 p / ∂y^2
double Discretization::computeD2pDy2(int i, int j) const
{
    double denominator = (dy() * dy());
    return (p(i, j + 1) - 2 * p(i, j) + p(i, j - 1)) / denominator;
}

//get meshwidth in each direction
const std::array<double, 2> Discretization::meshWidth() const
{
    return meshWidth_;
}

//get number of cells in each direction
const std::array<int, 2> Discretization::nCells() const
{
    return nCells_;
}

//write output to .txt file (self written)
void Discretization::write_to_file(int fileNo, double time) const
{
    // create "out" subdirectory if it does not yet exist
    int returnValue = system("mkdir -p out");
    if (returnValue != 0)
        std::cout << "Could not create subdirectory \"out\"." << std::endl;

    // Assemble the filename
    std::stringstream fileName;
    fileName << "out/output_" << std::setw(4) << std::setfill('0') << fileNo << ".txt";

    //header in .txt file
    std::ofstream myfile;
    myfile.open(fileName.str());
    myfile << "t: " << time << std::endl;
    myfile << "nCells: " << nCells_[0] << "x" << nCells_[1] << ", dx: " << dx() << ", dx: " << dy() << std::endl;
    myfile.close();

    // write each matrix in append mode
    u().write_to_file(fileName.str(), "u", true);
    v().write_to_file(fileName.str(), "v", true);
    p().write_to_file(fileName.str(), "p", true);
    f().write_to_file(fileName.str(), "f", true);
    g().write_to_file(fileName.str(), "g", true);
    rhs().write_to_file(fileName.str(), "rhs", true);
}

//get meshwidth in x-direction
double Discretization::dx() const {return meshWidth_[0];}
//get meshwidth in y-direction
double Discretization::dy() const {return meshWidth_[1];}