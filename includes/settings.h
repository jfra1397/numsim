#pragma once

#include <iostream>
#include <array>
#include <memory>

#include "discretization.h"

//get rid of co-depending classes
class Solver;
class Discretization;

class Settings
{

public:
    Settings();

    //parse a text file with settings, each line contains "<parameterName> = <value>"
    void loadFromFile(const std::string filename);

    //output all settings to console
    void printSettings() const;

    //get discretization instance depending on settings
    std::shared_ptr<Discretization> get_discretization();

    //get solver instance depending on settings
    std::shared_ptr<Solver> get_solver();

    //return number of cells in x and y direction
    const std::array<int, 2> nCells() const;

    //return physical size of the domain
    const std::array<double, 2> physicalSize() const;

    //return reynolds number
    double re() const;

    //return end time of the simulation
    double endTime() const;

    //return safety factor for time step width
    double tau() const;

    //return maximum time step width
    double maximumDt() const;

    //return external forces
    const std::array<double, 2> g() const;

    //return if the donor cell scheme schould be used
    bool useDonorCell() const;

    //return factor for donor-cell scheme
    double alpha() const;


    //return prescribed values of u,v at bottom of domain
    const std::array<double, 2> dirichletBcBottom() const;

    //return prescribed values of u,v at top of domain
    const std::array<double, 2> dirichletBcTop() const;

    //return prescribed values of u,v at left of domain
    const std::array<double, 2> dirichletBcLeft() const;

    //return prescribed values of u,v at right of domain
    const std::array<double, 2> dirichletBcRight() const;


    //return which pressure solver to use, "GaussSeidel" or "SOR"
    const std::string pressureSolver() const;

    //return overrelaxation factor
    double omega() const;

    //return tolerance for the residual in the pressure solver
    double epsilon() const;

    //return maximum number of iterations in the solver
    int maximumNumberOfIterations() const;


private:

    //assign value to parameter named param and cast datatype
    int assign_param_(std::string param, std::string value);


    //number of cells in x and y direction
    std::array<int, 2> nCells_;

    //physical size of the domain
    std::array<double, 2> physicalSize_;

    //reynolds number
    double re_;

    //end time of the simulation
    double endTime_;

    //safety factor for time step width
    double tau_;

    //maximum time step width
    double maximumDt_; 

    //external forces
    std::array<double, 2> g_;

    //if the donor cell scheme schould be used
    bool useDonorCell_;

    //factor for donor-cell scheme
    double alpha_;


    //prescribed values of u,v at bottom of domain
    std::array<double, 2> dirichletBcBottom_;

    //prescribed values of u,v at top of domain
    std::array<double, 2> dirichletBcTop_;

    //prescribed values of u,v at left of domain
    std::array<double, 2> dirichletBcLeft_;

    //prescribed values of u,v at right of domain
    std::array<double, 2> dirichletBcRight_;


    //which pressure solver to use, "GaussSeidel" or "SOR"
    std::string pressureSolver_;

    //overrelaxation factor
    double omega_;

    //tolerance for the residual in the pressure solver
    double epsilon_;

    //maximum number of iterations in the solver
    int maximumNumberOfIterations_;
};