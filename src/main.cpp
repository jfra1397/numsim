#include <iostream>
#include <memory>

#include <mpi.h>

#include "../includes/settings.h"
#include "../includes/partitioning.h"
#include "../includes/discretization.h"
#include "../includes/solver.h"
#include "../includes/output_writer_paraview_parallel.h"



int main(int argc, char *argv[])

{
    //initialize MPI
    MPI_Init(&argc, &argv);

    //create instance of partitioning
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

    //run loop to solve for new velocities u,v
    solver->solve_uv(settings, *discretization, partitioning, writer);

    MPI_Finalize();
    return EXIT_SUCCESS;
}