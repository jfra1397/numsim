#include <fstream>   // for file operations
#include <iostream>  // for cout
#include <algorithm>

#include "../includes/settings.h"


void Settings::loadFromFile(std::string filename)
{
    // open file
    std::ifstream file(filename.c_str(), std::ios::in);

    // check if file is open
    if (!file.is_open())
    {
        std::cout << "Could not open parameter file \"" << filename << "\". Using default parameters!" << std::endl;
        return;
    }

    size_t found;
    std::string param;
    std::string value;

    // loop over lines of file
    for (int lineNo = 0;; lineNo++)
    {
        // at the end of the file break for loop
        if (file.eof())
        break;
        
        // read line
        std::string line;
        getline(file, line);

        //skip empty lines
        if (line == "") continue;
        
        // get rid of spaces
        std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
        line.erase(end_pos, line.end());

        //skip comments
        if (line[0] == '#') continue;

        // get name of parameter
        found = line.find("="); 
        if (found == std::string::npos)
        {
            std::cout << "somhting went wrong in line " << lineNo << ": " << line << std::endl;
            continue;
        }
        else param = line.substr(0,found);

        //get value of parameter
        value = line.substr(found+1);
        found = value.find_first_not_of("123456789.,");
        value = value.substr(0, found);

        if (0 == assign_param(param, value)) std::cout << "assigned " << param << std::endl;
        else std::cout << "Couldn't assign " << param << std::endl;
        
    }


}


void Settings::printSettings()
{
    std::cout << "Settings: " << std::endl
    //<< "  physicalSize: " << physicalSize[0] << " x " << physicalSize[1] << ", nCells: " << nCells[0] << " x " << nCells[1] << std::endl
    << "  endTime: " << endTime << " s, re: " << re << /* ", g: (" << g[0] << "," << g[1] << "), tau: " << tau << ", maximum dt: " << maximumDt << std::endl
    << "  dirichletBC: bottom: (" << dirichletBcBottom[0] << "," << dirichletBcBottom[1]  << ")"
    << ", top: ("  << dirichletBcTop[0] << "," << dirichletBcTop[1]  << ")"
    << ", left: ("  << dirichletBcLeft[0] << "," << dirichletBcLeft[1] << ")"
    << ", right: ("  << dirichletBcRight[0] << "," << dirichletBcRight[1] << ")" << std::endl
    << "  useDonorCell: " << std::boolalpha << useDonorCell << ", alpha: " << alpha << std::endl
    << "  pressureSolver: " << pressureSolver << ", omega: " << omega << ", epsilon: " << epsilon << ", maximumNumberOfIterations: " << maximumNumberOfIterations <<  */ std::endl;
}




int Settings::assign_param(std::string param, std::string value)
{
    try
    {
        if (param == "re") re = std::stod(value);
        else if (param == "endTime") endTime = std::stod(value);

        else return 1;
    }
    catch(const std::invalid_argument&)
    {
        std::cout << "Couldn't parse " << value << ". Using default value for parameter " << param << std::endl;
        return 1;
    }

    return 0;
}