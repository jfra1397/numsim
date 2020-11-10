#include <iostream>
#include <algorithm>

#include "../includes/settings.h"
#include "../includes/field_variable.h"

int main(int argc, char *argv[])
{

    // Settings settings;
    // if(argc <= 1) std::cout << "No input file given. Using default parameters!" << std::endl;
    // else settings.loadFromFile(argv[1]);
    // settings.printSettings();

    std::array<int,2> size = {10,10};
    FieldVariable test(size);
    test.set_boundary_type(NEUMANN, NEUMANN, NEUMANN, NEUMANN);
    test.set_boundary(TOP, 10, true, 2.0);
    test.print();
    std::cout << test.get_max() << ", " << test.get_min() << std::endl; 



    return EXIT_SUCCESS;
}