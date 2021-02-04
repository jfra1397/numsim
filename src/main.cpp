#include <iostream>
#include <memory>
#include <chrono>

#include "../includes/settings.h"
#include "../includes/discretization.h"
#include "../includes/solver.h"
#include "../includes/output_writer_paraview.h"

#include <vtkImageData.h>
#include <vtkDoubleArray.h>
#include <vtkPointData.h>
#include <vtkStructuredGrid.h>
#include <vtkXMLStructuredGridWriter.h>

int main(int argc, char *argv[])

{
    std::string outputPath = "out";

    //load settings
    bool meshOnly = false;
    bool input = false;
    bool remove = false;
    bool feedback = false;
    Settings settings;

    //check for and read given input flags
    for (int i = 1; i < argc; i++)
    {
        if (std::string(argv[i]) == "-m" || std::string(argv[i]) == "--mesh")
            meshOnly = true;
        else if (std::string(argv[i]) == "-o" || std::string(argv[i]) == "--output")
        {
            outputPath = std::string(argv[i + 1]);
            i++;
        }
        else if (std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help")
        {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "FANCY NUMERICAL SOLVER FOR LAMINAR FLUID PROBLEMES WITH ARBITRARY GEOMETRIES AND HEAT" << std::endl;
            std::cout << std::endl;
            std::cout << "Path of parameter file must be passed!" << std::endl;
            std::cout << std::endl;
            std::cout << "Optional flags:" << std::endl;
            std::cout << "-m or --mesh: generate single file only containing specified mesh" << std::endl;
            std::cout << "-o or --out: generate output in following folder" << std::endl;
            std::cout << "-r or --remove: remove output folder (coudld be given with -o)" << std::endl;
            std::cout << "-tf or --timefeedback: print time and residuum to console after every timestep" << std::endl;
            std::cout << std::endl;
            std::cout << "\u00a9 Stefania Scheurer, Marius Stach and Julian Franquinet " << std::endl;

            return EXIT_SUCCESS;
        }
        else if (std::string(argv[i]) == "-r" || std::string(argv[i]) == "--remove")
            remove = true;
        else if (std::string(argv[i]) == "-tf" || std::string(argv[i]) == "--timefeedback")
            feedback = true;
        else
        {
            settings.loadFromFile(argv[i]);
            input = true;
        }
    }

    //check for input file
    if (!input)
    {
        std::cout << "No input file given. Abborting!" << std::endl;
        return EXIT_FAILURE;
    }

    //print settings to console
    settings.printSettings();

    //create discretization depending on a settings value
    std::shared_ptr<Discretization> discretization = settings.get_discretization();

    //create discretization
    std::shared_ptr<Solver> solver = settings.get_solver();

    //create outputwriter class
    OutputWriterParaview writer(discretization, outputPath, remove);

    //write only vts file with constructed mesh if -m flag given
    if (meshOnly)
    {
        writer.writeMesh();
        return EXIT_SUCCESS;
    }

    //run loop to solve for new velocities u,v
    solver->solve_uv(settings, *discretization, writer, feedback,outputPath);

    return EXIT_SUCCESS;
}