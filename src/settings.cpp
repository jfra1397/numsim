#include <fstream>   //for file operations
#include <iostream>  //for cout
#include <algorithm> //forstr to int,double

#include "../includes/settings.h"
#include "../includes/donor_cell.h"
#include "../includes/central_differences.h"
#include "../includes/sor.h"
#include "../includes/gauss_seidel.h"

Settings::Settings()
{
    //reynolds number
    re_ = 1000;

    //prandtl number
    pr_ = 1;

    //end time of the simulation
    endTime_ = 10.0;

    //safety factor for time step width
    tau_ = 0.5;

    //maximum time step width
    maximumDt_ = 0.1;

    //interval length between written files
    writeInterval_ = 0.0;

    //external forces
    g_ = {0., 0.};

    //heat flux
    q_ = 0.;

    //initial temperature
    tInit_ = 0.0;

    //if the donor cell scheme schould be used
    useDonorCell_ = false;

    //factors for donor-cell scheme
    alpha_ = 0.5;
    gamma_ = 0.5;

    //volume expansion coefficent
    beta_ = 0;

    //which pressure solver to use, "GaussSeidel" or "SOR"
    pressureSolver_ = "SOR";

    //overrelaxation factor
    omega_ = 1.0;

    //tolerance for the residual in the pressure solver
    epsilon_ = 1e-5;

    //maximum number of iterations in the solver
    maximumNumberOfIterations_ = 1e5;
}

//parse a text file with settings, each line contains "<parameterName> = <value>"
void Settings::loadFromFile(const std::string filename)
{
    //open file
    std::ifstream file(filename.c_str(), std::ios::in);

    //check if file is open
    if (!file.is_open())
    {
        std::cout << "Could not open parameter file \"" << filename << "\". Using default parameters!" << std::endl;
        return;
    }

    //helpers for string operations
    size_t found;
    std::string param;
    std::string value;

    //loop over lines of file
    for (int lineNo = 0;; lineNo++)
    {
        //at the end of the file break for loop
        if (file.eof())
            break;

        //read line
        std::string line;
        getline(file, line);

        //skip empty lines
        if (line == "")
            continue;

        //get rid of spaces
        std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
        line.erase(end_pos, line.end());

        //get rid of \r (shitty Windows stuff)
        end_pos = std::remove(line.begin(), line.end(), '\r');
        line.erase(end_pos, line.end());

        //skip comments
        if (line[0] == '#')
            continue;

        //get name of parameter
        found = line.find("=");
        //check for dict{} (boundary conditions and obstacles) if no "=" is found
        if (found == std::string::npos)
        {
            found = line.find("{");
            if (found == std::string::npos)
            {
                std::cout << "something went wrong in line " << lineNo << ": " << line << std::endl;
                continue;
            }
            line = line.substr(found + 1);
            //if dict is found read input
            handle_dict(file, line, lineNo);
        }
        else
        {
            param = line.substr(0, found);

            //get value of parameter
            value = line.substr(found + 1);
            found = value.find_first_of("#");
            if (found != std::string::npos)
                value = value.substr(0, found);

            if (0 != assign_param_(param, value))
                std::cout << "Couldn't assign " << param << std::endl;
        }
    }

    //close file
    file.close();
}

//output all settings to console
void Settings::printSettings() const
{
    std::cout << "Settings: " << std::endl
              << "  physicalSize: " << physicalSize()[0] << " x " << physicalSize()[1] << ", nCells: " << nCells()[0] << " x " << nCells()[1] << std::endl
              << "  endTime: " << endTime() << " s, re: " << re() << ", pr: " << pr() << ", g: (" << g()[0] << "," << g()[1] << "), q: " << q() << ", tInit: " << tInit() << ", tau: " << tau() << ", maximum dt: " << maximumDt() << std::endl
              << "  writeInterval:" << writeInterval() << " s" << std::endl
              << "  useDonorCell: " << std::boolalpha << useDonorCell() << ", alpha: " << alpha() << ", beta: " << beta() << ", gamma: " << gamma() << std::endl
              << "  pressureSolver: " << pressureSolver() << ", omega: " << omega() << ", epsilon: " << epsilon() << ", maximumNumberOfIterations: " << maximumNumberOfIterations() << std::endl;
}

//assign value to parameter named param and cast datatype
int Settings::assign_param_(std::string param, std::string value)
{
    try
    {
        if (param == "physicalSizeX")
            physicalSize_[0] = std::stod(value);
        else if (param == "physicalSizeY")
            physicalSize_[1] = std::stod(value);
        else if (param == "endTime")
            endTime_ = std::stod(value);
        else if (param == "writeTimeInterval")
            writeInterval_ = std::stod(value);
        else if (param == "re")
            re_ = std::stod(value);
        else if (param == "gX")
            g_[0] = std::stod(value);
        else if (param == "gY")
            g_[1] = std::stod(value);
        else if (param == "nCellsX")
            nCells_[0] = std::stoi(value);
        else if (param == "nCellsY")
            nCells_[1] = std::stoi(value);
        else if (param == "useDonorCell")
            useDonorCell_ = value.compare("true") == 0 || value.compare("True") == 0;
        else if (param == "alpha")
            alpha_ = std::stod(value);
        else if (param == "tau")
            tau_ = std::stod(value);
        else if (param == "maximumDt")
            maximumDt_ = std::stod(value);
        else if (param == "pressureSolver")
            pressureSolver_ = value;
        else if (param == "omega")
            omega_ = std::stod(value);
        else if (param == "epsilon")
            epsilon_ = std::stod(value);
        else if (param == "beta")
            beta_ = std::stod(value);
        else if (param == "pr")
            pr_ = std::stod(value);
        else if (param == "q")
            q_ = std::stod(value);
        else if (param == "tInit")
            tInit_ = std::stod(value);
        else if (param == "gamma")
            gamma_ = std::stod(value);
        else if (param == "maximumNumberOfIterations")
            maximumNumberOfIterations_ = (int)std::stod(value);
        else
            return 1;
    }
    //catch error if casting failed
    catch (const std::invalid_argument &)
    {
        std::cout << "Couldn't parse " << value << ". Using default value for parameter " << param << std::endl;
        return 1;
    }
    return 0;
}

//return number of cells in x and y direction
const std::array<int, 2> Settings::nCells() const { return nCells_; }

//return physical size of the domain
const std::array<double, 2> Settings::physicalSize() const { return physicalSize_; }

//return reynolds number
double Settings::re() const { return re_; }

//return prandtl number
double Settings::pr() const { return pr_; }

//return volume expansion coefficient
double Settings::beta() const { return beta_; }

//return end time of the simulation
double Settings::endTime() const { return endTime_; }

//return safety factor for time step width
double Settings::tau() const { return tau_; }

//return maximum time step width
double Settings::maximumDt() const { return maximumDt_; }

//return interval length between written files
double Settings::writeInterval() const { return writeInterval_; }

//return external forces
const std::array<double, 2> Settings::g() const { return g_; }

//return heat flux
double Settings::q() const { return q_; }

//return initial temperature
double Settings::tInit() const { return tInit_; }

//return if the donor cell scheme schould be used
bool Settings::useDonorCell() const { return useDonorCell_; }

//return factor for donor-cell scheme velocities
double Settings::alpha() const { return alpha_; }

//return factor for donor-cell scheme temperature
double Settings::gamma() const { return gamma_; }

//return which pressure solver to use, "GaussSeidel" or "SOR"
const std::string Settings::pressureSolver() const { return pressureSolver_; }

//return overrelaxation factor
double Settings::omega() const { return omega_; }

//return tolerance for the residual in the pressure solver
double Settings::epsilon() const { return epsilon_; }

//return maximum number of iterations in the solver
int Settings::maximumNumberOfIterations() const { return maximumNumberOfIterations_; }

//get discretization instance depending on settings
std::shared_ptr<Discretization> Settings::get_discretization()
{
    std::shared_ptr<Discretization> discr;
    //create discretization depending on a settings value
    if (useDonorCell())
    {
        //create donor cell discretization
        discr = std::make_shared<DonorCell>(nCells(), physicalSize(), tInit(), alpha(), gamma());
    }
    else
    {
        //create central differences
        discr = std::make_shared<CentralDifferences>(nCells(), physicalSize(), tInit());
    }
    discr->generate_mesh(objects_);
    return discr;
}

//get solver instance depending on settings
std::shared_ptr<Solver> Settings::get_solver()
{
    if (pressureSolver() == "SOR") // depending on a settings value
    {
        //create donor cell discretization
        return std::make_shared<SOR>(maximumNumberOfIterations(), epsilon(), omega());
    }
    else
    {
        //create central differences
        return std::make_shared<GaussSeidel>(maximumNumberOfIterations(), epsilon());
    }
}

//handle dict input for boundary conditions and obstacles
void Settings::handle_dict(std::ifstream &file, std::string line, int &lineNo)
{
    //go through dict until "}" is found and save linr by line in string array
    std::vector<std::array<std::string, 2>> str;
    bool loop = true;
    while (loop)
    {
        size_t found = line.find("}");
        if (found != std::string::npos)
        {
            line = line.substr(0, found);
            loop = false;
        }
        str.push_back(extract(line));
        if (loop)
        {
            getline(file, line);
            lineNo++;
        }
    }
    Obstacle obj;
    //go through string and handle input, save given values to corresponding parameters
    for (auto it = std::begin(str); it != std::end(str); ++it)
    {
        if ((*it)[0] == "Velocity")
        {
            std::vector<std::string> valuesString = cut((*it)[1]);
            obj.velType = string2btype(valuesString[0], lineNo);
            obj.velValue = {std::stod(valuesString[1]), std::stod(valuesString[2])};
        }
        else if ((*it)[0] == "Pressure")
        {
            std::vector<std::string> valuesString = cut((*it)[1]);
            obj.pType = string2btype(valuesString[0], lineNo);
            obj.pValue = std::stod(valuesString[1]);
        }
        else if ((*it)[0] == "Temperature")
        {
            std::vector<std::string> valuesString = cut((*it)[1]);
            obj.tType = string2btype(valuesString[0], lineNo);
            obj.tValue = std::stod(valuesString[1]);
        }
        else if ((*it)[0] == "Shape")
            obj.shape = string2shape(cut((*it)[1])[0], lineNo);
        else if ((*it)[0] == "Type")
            obj.type = string2celltype(cut((*it)[1])[0], lineNo);
        else if ((*it)[0] == "Position")
        {
            std::vector<std::string> valuesString = cut((*it)[1]);
            for (auto it2 = std::begin(valuesString); it2 != std::end(valuesString); ++it2)
                obj.position.push_back(std::stod(*it2));
        }
        else if ((*it)[0] == "")
            continue;
        else
            assertion_feedback(false, "unknown keyword in line " + std::to_string(lineNo));
    }
    //append object vector
    objects_.push_back(obj);
}

//split line by "="
std::array<std::string, 2> Settings::extract(std::string line)
{
    std::array<std::string, 2> str = {"", ""};
    size_t found;
    //get rid of spaces
    std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
    line.erase(end_pos, line.end());
    //get rid of \r
    end_pos = std::remove(line.begin(), line.end(), '\r');
    line.erase(end_pos, line.end());
    found = line.find("#");
    if (found != std::string::npos)
        line = line.substr(0, found);
    found = line.find("=");
    if (found != std::string::npos)
    {
        str[0] = line.substr(0, found);
        str[1] = line.substr(found + 1);
    }
    return str;
}

//return list of strings by cutting a string at ";"
std::vector<std::string> Settings::cut(const std::string &str)
{
    std::vector<std::string> substr;
    std::string temp = str;
    size_t found;
    while (true)
    {
        found = temp.find(";");
        if (found == std::string::npos)
        {
            substr.push_back(temp);
            break;
        }
        substr.push_back(temp.substr(0, found));
        temp = temp.substr(found + 1);
    }
    while (substr.back() == "")
    {
        substr.pop_back();
    }
    return substr;
}

//convert datatype from string to enum shape
SHAPE Settings::string2shape(std::string str, int &lineNo)
{
    if (str == "Rectangle")
        return RECTANGLE;
    else if (str == "Triangle")
        return TRIANGLE;
    else if (str == "Ellipse")
        return ELLIPSE;
    else
        assertion_feedback(false, "Unknown shape in line " + std::to_string(lineNo));
}

//convert datatype from string to enum btype
btype Settings::string2btype(std::string str, int &lineNo)
{
    if (str == "Neumann")
        return NEUMANN;
    else if (str == "Dirichlet")
        return DIRICHLET;
    else if (str == "Heated")
        return DIRICHLET;
    else if (str == "Isolated")
        return NEUMANN;
    else
        assertion_feedback(false, "Unknown boundtype in line " + std::to_string(lineNo));
}

//convert datatype from string to enum CELLTYPE
CELLTYPE Settings::string2celltype(std::string str, int &lineNo)
{
    if (str == "Leftbound")
        return LEFTBOUND;
    else if (str == "Rightbound")
        return RIGHTBOUND;
    else if (str == "Topbound")
        return TOPBOUND;
    else if (str == "Bottombound")
        return BOTTOMBOUND;
    else if (str == "Fluid")
        return FLUID;
    else if (str == "Object")
        return EMPTY;
    else
        assertion_feedback(false, "Unknown celltype in line " + std::to_string(lineNo));
}

//give feedback when error occurs
void assertion_feedback(bool assertion, std::string msg)
{
    if (!assertion)
    {
        std::cout << msg << std::endl;
        abort();
    }
}