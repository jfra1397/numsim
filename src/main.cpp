#include <iostream>
#include <algorithm>

#include "../includes/settings.h"

int main(int argc, char *argv[])
{
    Settings settings;
    if(argc <= 1) std::cout << "No input file given. Using default parameters!" << std::endl;
    else settings.loadFromFile(argv[1]);
    settings.printSettings();


    return EXIT_SUCCESS;
}