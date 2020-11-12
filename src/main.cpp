#include <iostream>
#include <algorithm>

#include "../includes/settings.h"
#include "../includes/field_variable.h"
#include "../includes/staggered_grid.h"
#include "../includes/array2d.h"

int main(int argc, char *argv[])
{
    //Pay attention corner interpolation!!!!


    //Timesstamp!!!!
    Settings settings;
    if(argc <= 1) std::cout << "No input file given. Using default parameters!" << std::endl;
    else settings.loadFromFile(argv[1]);
    settings.printSettings();

    // std::array<int,2> size = {3,3};
    // FieldVariable test(size, VTOP);
    // test.set_boundary_type(NEUMANN, NEUMANN, NEUMANN, NEUMANN);
    // test.set_boundary(LEFT, 10, true, 2.0);
    // test.print();
    // std::cout << test.get_max() << ", " << test.get_min() << std::endl; 

    StaggeredGrid values(settings.nCells());
    // values.set_boundery_uv(settings.dirichletBcBottom, settings.dirichletBcRight, settings.dirichletBcTop, settings.dirichletBcLeft);
    // values.set_boundery_fg(settings.dirichletBcBottom, settings.dirichletBcRight, settings.dirichletBcTop, settings.dirichletBcLeft);
    // values.p.set_boundary_type(NEUMANN, NEUMANN, NEUMANN, NEUMANN);
    // values.p.set_boundary(0,0,0,0);

    // values.u.print();
    // values.u().print();
    // values.set_u(1,2) = 5;
    // std::cout << values.u(1,2) << std::endl;
    // values.u().print();

    std::array<int,2> size = {3,3};
    Array2D test(size);
    Array2D test2(size);
    test.print();
    test2(1,1) = 5;
    test2.print();
    test = test2;
    test.print();
    test(0,0) = 10;
    test.print();
    test2.print();



    return EXIT_SUCCESS;
}


/* compute
{
    for i ....
        for j ....
         f(i,j) = 1/re*dicret.central(u,i,j,1) + .......
}

*/