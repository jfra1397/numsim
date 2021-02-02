#pragma once

#include <iostream>
#include <array>
#include <memory>
#include <string>

#include "values.h"

//get rid of co-depending classes
class Solver;
class Discretization;

/** This class contains all parameter values and
 * loads them from a given *.txt file. Also it creates 
 * the discretization and solver object with given 
 * parameters */

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

    //return prandtl number
    double pr() const;

    //return volume expansion coefficient
    double beta() const;

    //return end time of the simulation
    double endTime() const;

    //return intervall length between written files in seconds
    double writeInterval() const;

    //return safety factor for time step width
    double tau() const;

    //return maximum time step width
    double maximumDt() const;

    //return external forces
    const std::array<double, 2> g() const;

    //return heat flux
    double q() const;

    //return initial temperature
    double tInit() const;

    //return if the donor cell scheme schould be used
    bool useDonorCell() const;

    //return factor for donor-cell scheme velocities
    double alpha() const;

    //return factor for donor-cell scheme temperature
    double gamma() const;

    //return which pressure solver to use, "GaussSeidel" or "SOR"
    const std::string pressureSolver() const;

    //return overrelaxation factor
    double omega() const;

    //return tolerance for the residual in the pressure solver
    double epsilon() const;

    //return maximum number of iterations in the solver
    int maximumNumberOfIterations() const;

    //private:

    //assign value to parameter named param and cast datatype
    int assign_param_(std::string param, std::string value);

    //number of cells in x and y direction
    std::array<int, 2> nCells_;

    //physical size of the domain
    std::array<double, 2> physicalSize_;

    //reynolds number
    double re_;

    //prandtl number
    double pr_;

    //volume expansion coefficient
    double beta_;

    //end time of the simulation
    double endTime_;

    //interval length between written files in seconds
    double writeInterval_;

    //safety factor for time step width
    double tau_;

    //maximum time step width
    double maximumDt_;

    //external forces
    std::array<double, 2> g_;

    //heat flux
    double q_;

    //initial temperature
    double tInit_;

    //if the donor cell scheme schould be used
    bool useDonorCell_;

    //factor for donor-cell scheme velocities
    double alpha_;

    //factor for donor-cell scheme temperature
    double gamma_;

    //save information given by boundaries and obstacles
    std::vector<Obstacle> objects_;

    //which pressure solver to use, "GaussSeidel" or "SOR"
    std::string pressureSolver_;

    //overrelaxation factor velocities
    double omega_;

    //tolerance for the residual in the pressure solver
    double epsilon_;

    //maximum number of iterations in the solver
    int maximumNumberOfIterations_;

    //handle dict input for boundary conditions and obstacles
    void handle_dict(std::ifstream &file, std::string line, int &lineNo);

    //split line by "="
    std::array<std::string, 2> extract(std::string line);

    //return list of strings by cutting a string at ";"
    std::vector<std::string> cut(const std::string &str);

    //convert datatype from string to enum shape
    SHAPE string2shape(std::string str, int &lineNo);

    //convert datatype from string to enum btype
    btype string2btype(std::string str, int &lineNo);

    //convert datatype from string to enum CELLTYPE
    CELLTYPE string2celltype(std::string str, int &lineNo);
};

//give feedback when error occurs
void assertion_feedback(bool assertion, std::string msg);
