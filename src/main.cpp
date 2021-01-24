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

    for (int i = 1; i < argc; i++)
    {
        if (std::string(argv[i]) == "-m" || std::string(argv[i]) == "--mesh") meshOnly = true;
        else if (std::string(argv[i]) == "-o" || std::string(argv[i]) == "--output") outputPath = std::string(argv[i+1]);
        else if (std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help")
        {
            std::cout << "help" <<std::endl;
        }
        else if (std::string(argv[i]) == "-r" || std::string(argv[i]) == "--remove") remove = true;
        else if (std::string(argv[i]) == "-f" || std::string(argv[i]) == "--feedback") feedback = true;
        else
        {
            settings.loadFromFile(argv[i]);
            input = true;
        }
    }

    if (!input)
    {
        std::cout << "No input file given. Abborting!" << std::endl;
        return EXIT_FAILURE;
    }

    //else settings.loadFromFile(argv[1]);

    settings.printSettings();

    //create discretization depending on a settings value
    std::shared_ptr<Discretization> discretization = settings.get_discretization();

    //create discretization
    std::shared_ptr<Solver> solver = settings.get_solver();

    //create outputwriter class
    OutputWriterParaview writer(discretization, outputPath, remove);

    if (meshOnly)
    {
        writer.writeFile(0);
        return EXIT_SUCCESS;
    }

    // auto start = std::chrono::high_resolution_clock::now();

    //run loop to solve for new velocities u,v
    solver->solve_uv(settings, *discretization, writer, feedback);

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