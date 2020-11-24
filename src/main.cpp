#include <iostream>
#include <algorithm>
#include <memory>

#include "../includes/settings.h"
//#include "../includes/field_variable.h"
//#include "../includes/staggered_grid.h"
//#include "../includes/array2d.h"
#include "../includes/discretization.h"
#include "../includes/central_differences.h"
#include "../includes/donor_cell.h"
#include "../includes/solver.h"
#include "../includes/sor.h"
#include "../includes/gauss_seidel.h"
#include "../includes/output_writer_paraview.h"
//#include "../includes/output_writer.h"


bool comp(double a, double b) {return (a<b);}

int main(int argc, char *argv[])
{

    //load settings
    Settings settings;
    if(argc <= 1) std::cout << "No input file given. Using default parameters!" << std::endl;
    else settings.loadFromFile(argv[1]);
    settings.printSettings();

    //das muss raus

    // typedef std::conditional<type, DonorCell, CentralDifferences> discr;
    std::shared_ptr<Discretization> discretization;
    //create discretization depending on a settings value
    if (settings.useDonorCell())
    {
        //create donor cell discretization
        discretization = std::make_shared<DonorCell>(settings.nCells(), settings.physicalSize(), settings.alpha());
    }
    else
    {
        //create central differences
        discretization = std::make_shared<CentralDifferences>(settings.nCells(), settings.physicalSize());
    }
    std::shared_ptr<Solver> solver;
    //create discretization
    if (settings.pressureSolver() == "SOR")   // depending on a settings value
    {
        //create donor cell discretization
        solver = std::make_shared<SOR>(settings.maximumNumberOfIterations(), settings.epsilon(), settings.omega());
    }
    else
    {
        //create central differences
        solver = std::make_shared<GaussSeidel>(settings.maximumNumberOfIterations(), settings.epsilon());
    }

    //bis hierhin

    //solve for new velocities u,v
    solver->solve_uv(settings,discretization);   
    
    return EXIT_SUCCESS;
}