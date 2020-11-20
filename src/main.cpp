#include <iostream>
#include <algorithm>
#include <memory>

#include "../includes/settings.h"
#include "../includes/field_variable.h"
#include "../includes/staggered_grid.h"
#include "../includes/array2d.h"
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

    Settings settings;
    if(argc <= 1) std::cout << "No input file given. Using default parameters!" << std::endl;
    else settings.loadFromFile(argv[1]);
    settings.printSettings();

    std::shared_ptr<Discretization> discretization;
    //create discretization depending on a settings value
    if (settings.useDonorCell())
    {
        // create donor cell discretization
        discretization = std::make_shared<DonorCell>(settings.nCells(), settings.physicalSize(), settings.alpha());
    }
    else
    {
        // create central differences
        discretization = std::make_shared<CentralDifferences>(settings.nCells(), settings.physicalSize());
    }
    discretization->set_p().set_boundary_type(NEUMANN, NEUMANN, NEUMANN, NEUMANN);
    std::shared_ptr<Solver> solver;
    // create discretization
    if (settings.pressureSolver() == "SOR")   // depending on a settings value
    {
        // create donor cell discretization
        solver = std::make_shared<SOR>(settings.maximumNumberOfIterations(), settings.epsilon(), settings.omega());
    }
    else
    {
        // create central differences
        solver = std::make_shared<GaussSeidel>(settings.maximumNumberOfIterations(), settings.epsilon());
    }    
    
    OutputWriterParaview writer(discretization);
    
    double t = 0;
    int fileNo = 0;

    discretization->set_boundary_uv(settings.dirichletBcBottom(), settings.dirichletBcRight(), settings.dirichletBcTop(), settings.dirichletBcLeft());
    while (t < settings.endTime())
    {

        double dt = solver->compute_dt(settings.tau(), settings.re(), settings.maximumDt(), discretization->meshWidth(), discretization->u(), discretization->v());
        if (t + dt > settings.endTime()) dt = settings.endTime()-t;

        solver->compute_f(settings.re(), settings.g()[0], dt, discretization);
        solver->compute_g(settings.re(), settings.g()[1], dt, discretization);

        discretization->set_boundary_fg(discretization->u(), discretization->v());

        solver->compute_rhs(dt, discretization);
        
        solver->compute_p(discretization);

        solver->compute_u(dt, discretization);
        solver->compute_v(dt, discretization);

        discretization->set_boundary_uv(settings.dirichletBcBottom(), settings.dirichletBcRight(), settings.dirichletBcTop(), settings.dirichletBcLeft());
        
        t += dt;
        discretization->write_to_file(fileNo++, t);
        writer.writeFile(t);

    }

    return EXIT_SUCCESS;
}