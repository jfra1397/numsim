#include <iostream>
#include <memory>

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

    //create discretization depending on a settings value
    std::shared_ptr<Discretization> discretization = settings.get_discretization();

    //create discretization
    std::shared_ptr<Solver> solver = settings.get_solver();

    //create outputwriter class
    OutputWriterParaview writer(discretization);

    //run loop to solve for new velocities u,v
    solver->solve_uv(settings, *discretization, writer);
    
    return EXIT_SUCCESS;
}