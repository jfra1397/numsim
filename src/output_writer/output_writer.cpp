#include "../../includes/output_writer.h"

#include <iostream>

OutputWriter::OutputWriter(std::shared_ptr<Discretization> discretization, std::string outputPath)
 : discretization_(discretization), fileNo_(0)
{
  // create "out" subdirectory if it does not yet exist
  std::string temp = ("mkdir -p " + outputPath).c_str();
  int returnValue = system(("mkdir -p " + outputPath).c_str());
  if (returnValue != 0)
    std::cout << "Could not create subdirectory \"" << outputPath << "\"." << std::endl;
  outputPath_ = outputPath; 
}
