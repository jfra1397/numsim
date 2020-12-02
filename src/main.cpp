#include <iostream>
#include <memory>
#include <chrono>

#include "../includes/settings.h"
#include "../includes/discretization.h"
#include "../includes/solver.h"
#include "../includes/output_writer_paraview.h"



int main(int argc, char *argv[])

{

    //load settings
    Settings settings;
    if(argc <= 1) std::cout << "No input file given. Using default parameters!" << std::endl;
    else settings.loadFromFile(argv[1]);
    settings.printSettings();

    double timeStep;
    if (argc>=3) 
    {
        std::cout<< "Using always time step: " << argv[2] << std::endl;
        timeStep = std::stod(argv[2]);
    } 
    else timeStep = 0; 

    //create discretization depending on a settings value
    std::shared_ptr<Discretization> discretization = settings.get_discretization();

    //create discretization
    std::shared_ptr<Solver> solver = settings.get_solver();

    //create outputwriter class
    OutputWriterParaview writer(discretization);


    auto start = std::chrono::high_resolution_clock::now();

    //run loop to solve for new velocities u,v
    solver->solve_uv(settings, *discretization, writer, timeStep);

    /**
    auto stop = std::chrono::high_resolution_clock::now();

    //nanoseconds, microseconds, milliseconds, seconds, minutes, hours possible
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::ofstream myfile;
    
    //open file in append mode
    myfile.open("run-times.csv", std::ios::out | std::ios::app);
    myfile << settings.nCells()[0] << ";" << settings.nCells()[1] << ";" << duration.count() << std::endl;
    myfile.close();
    */
    
    return EXIT_SUCCESS;
}