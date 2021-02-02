#pragma once

#include "output_writer.h"

#include <vtkSmartPointer.h>
#include <vtkXMLStructuredGridWriter.h>
#include <vtkStructuredGrid.h>

#include <memory>

/** Write *.vti files that can be viewed with ParaView.
 *  The mesh that can be visualized in ParaView corresponds to the mesh of the computational domain.
 *  All values are given for the nodes of the mesh, i.e., the corners of each cell.
 *  This means, values will be interpolated because the values are stored at positions given by the staggered grid.
 */
class OutputWriterParaview : 
  public OutputWriter
{
public:
  //! constructor
  //! @param discretization shared pointer to the discretization object that will contain all the data to be written to the file
  OutputWriterParaview(std::shared_ptr<Discretization> discretization, std::string outputPath, bool remove);

  //! write current velocities, pressure and temperature to file, filename is output_<count>.vti
  void writeFile(double currentTime);
  //write only mesh to vtk file
  void writeMesh();

private:

  vtkSmartPointer<vtkXMLStructuredGridWriter> vtkWriter_;   //< vtk writer to write structured grid
  //spacing of mesh
  double dx;
  double dy;
  double dz;
  //number of cells in x and y direction
  std::array<int,2> nCells;
  vtkSmartPointer<vtkStructuredGrid> dataSet; // vtk data set to create structured grid
};
