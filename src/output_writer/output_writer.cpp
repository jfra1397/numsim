#include "../../includes/output_writer.h"

#include <iostream>

OutputWriter::OutputWriter(std::shared_ptr<Discretization> discretization, const Partitioning &partitioning)
 : discretization_(discretization), partitioning_(partitioning), fileNo_(0)
{
  // create "out" subdirectory if it does not yet exist
  int returnValue = system("mkdir -p out");
  if (returnValue != 0)
    std::cout << "Could not create subdirectory \"out\"." << std::endl;
}
