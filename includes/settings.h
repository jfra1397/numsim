#pragma once

#include <iostream>
#include <array>


class Settings
{

    
    public:
    
    Settings();
    
    //! parse a text file with settings, each line contains "<parameterName> = <value>"
    void loadFromFile(const std::string filename);

    //! output all settings to console
    void printSettings() const;

    const std::array<int,2> nCells() const;          //< return number of cells in x and y direction
    const std::array<double,2> physicalSize() const; //< return physical size of the domain
    double re() const;                  //< return reynolds number
    double endTime() const;             //< return end time of the simulation
    double tau() const;                  //< return safety factor for time step width
    double maximumDt() const;            //< return maximum time step width

    const std::array<double,2> g() const;    //< return external forces

    bool useDonorCell() const;         //< return if the donor cell scheme schould be used
    double alpha() const;                //< return factor for donor-cell scheme

    const std::array<double,2> dirichletBcBottom() const;  //< returnprescribed values of u,v at bottom of domain
    const std::array<double,2> dirichletBcTop() const;     //< return prescribed values of u,v at top of domain
    const std::array<double,2> dirichletBcLeft() const;    //< return prescribed values of u,v at left of domain
    const std::array<double,2> dirichletBcRight() const;   //< return prescribed values of u,v at right of domain

    const std::string pressureSolver() const;      //< return which pressure solver to use, "GaussSeidel" or "SOR"
    double omega() const;                //< return overrelaxation factor
    double epsilon() const;             //< return tolerance for the residual in the pressure solver
    int maximumNumberOfIterations() const;    //< return maximum number of iterations in the solver

    private:
    int assign_param_(std::string param, std::string value);

    std::array<int,2> nCells_;          //< number of cells in x and y direction
    std::array<double,2> physicalSize_; //< physical size of the domain
    double re_;                  //< reynolds number
    double endTime_;             //< end time of the simulation
    double tau_;                  //< safety factor for time step width
    double maximumDt_;            //< maximum time step width

    std::array<double,2> g_;    //< external forces

    bool useDonorCell_;         //< if the donor cell scheme schould be used
    double alpha_;                //< factor for donor-cell scheme

    std::array<double,2> dirichletBcBottom_;  //< prescribed values of u,v at bottom of domain
    std::array<double,2> dirichletBcTop_;     //< prescribed values of u,v at top of domain
    std::array<double,2> dirichletBcLeft_;    //< prescribed values of u,v at left of domain
    std::array<double,2> dirichletBcRight_;   //< prescribed values of u,v at right of domain

    std::string pressureSolver_;      //< which pressure solver to use, "GaussSeidel" or "SOR"
    double omega_;                //< overrelaxation factor
    double epsilon_;             //< tolerance for the residual in the pressure solver
    int maximumNumberOfIterations_;    //< maximum number of iterations in the solver
};