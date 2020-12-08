#include <iostream>
#include <memory>
#include <chrono>

#include <mpi.h>

#include "../includes/settings.h"
#include "../includes/partitioning.h"
#include "../includes/discretization.h"
#include "../includes/solver.h"
#include "../includes/output_writer_paraview_parallel.h"



int main(int argc, char *argv[])

{
    MPI_Init(&argc, &argv);


    Partitioning partitioning;

    //load settings
    Settings settings;
    if(argc <= 1) std::cout << "No input file given. Using default parameters!" << std::endl;
    settings.loadFromFile(argv[1]);
    //settings.printSettings();

    //create discretization depending on a settings value
    std::shared_ptr<Discretization> discretization = partitioning.get_discretization(settings);
    //create discretization
    std::shared_ptr<Solver> solver = settings.get_solver();
    //create outputwriter class
    OutputWriterParaviewParallel writer(discretization, partitioning);


    auto start = std::chrono::high_resolution_clock::now();

    //run loop to solve for new velocities u,v
    solver->solve_uv(settings, *discretization, partitioning, writer);

    //auto stop = std::chrono::high_resolution_clock::now();

    //nanoseconds, microseconds, milliseconds, seconds, minutes, hours possible
    //auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    //std::cout << duration.count() << std::endl;
    
    /** //open file in append mode
    myfile.open("run-times.csv", std::ios::out | std::ios::app);
    myfile << settings.nCells()[0] << ";" << settings.nCells()[1] << ";" << duration.count() << std::endl;
    myfile.close();
    **/
    MPI_Finalize();
    return EXIT_SUCCESS;
}