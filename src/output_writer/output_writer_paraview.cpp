#include "../../includes/output_writer_paraview.h"

#include <vtkImageData.h>
#include <vtkDoubleArray.h>
#include <vtkPointData.h>
#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkMath.h>


OutputWriterParaview::OutputWriterParaview(std::shared_ptr<Discretization> discretization, std::string outputPath, bool remove) :
   OutputWriter(discretization, outputPath, remove)
{
  // Create a vtkWriter_
  vtkWriter_ = vtkSmartPointer<vtkXMLStructuredGridWriter>::New();

  //set spacing of mesh
 dx = discretization_->meshWidth()[0];
  dy = discretization_->meshWidth()[1];
  dz = 1;
  // initialize data set that will be output to the file
  dataSet = vtkSmartPointer<vtkStructuredGrid>::New();

  // set number of points in each dimension, 1 cell in z direction
 nCells = discretization_->nCells();
  vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
  for (int j = 0; j < nCells[1]+1; j++)
  {
    for (int i = 0; i < nCells[0]+1; i++)
    {
      const double x = i*dx;
      const double y = j*dy;
      points->InsertNextPoint(x, y, 0);
    }
  }
  dataSet->SetPoints(points);
  dataSet->SetDimensions(nCells[0]+1, nCells[1]+1, 1);  // we want to have points at each corner of each cell

  int index = 0;
  for (int j = 1; j < nCells[1]+1; j++)
  {

    for (int i = 1; i < nCells[0]+1; i++, index++)
    {
      if (discretization_->flag(i,j) != FLUID) dataSet->BlankCell(index);
    }
  }
      
}

void OutputWriterParaview::writeMesh()
{
    // Assemble the filename
  std::stringstream fileName;
  fileName << outputPath_ << "/generatedMesh" << "." << vtkWriter_->GetDefaultFileExtension();

  // assign the new file name to the output vtkWriter_
  vtkWriter_->SetFileName(fileName.str().c_str());
  // Write the data
  vtkWriter_->SetInputData(dataSet);
  
  //vtkWriter_->SetDataModeToAscii();     // comment this in to get ascii text files: those can be checked in an editor
  vtkWriter_->SetDataModeToBinary();      // set file mode to binary files: smaller file sizes

  // finally write out the data
  vtkWriter_->Write();

}

void OutputWriterParaview::writeFile(double currentTime)
{
  // Assemble the filename
  std::stringstream fileName;
  fileName << outputPath_ << "/output_" << std::setw(4) << setfill('0') << fileNo_ << "." << vtkWriter_->GetDefaultFileExtension();
  
  // increment file no.
  fileNo_++;

  // assign the new file name to the output vtkWriter_
  vtkWriter_->SetFileName(fileName.str().c_str());
  
  
  //dataSet->SetOrigin(0, 0, 0);

  //
  
  // add pressure field variable
  // ---------------------------
  vtkSmartPointer<vtkDoubleArray> arrayPressure = vtkDoubleArray::New();

  // the pressure is a scalar which means the number of components is 1
  arrayPressure->SetNumberOfComponents(1);

  // Set the number of pressure values and allocate memory for it. We already know the number, it has to be the same as there are nodes in the mesh.
  arrayPressure->SetNumberOfTuples(dataSet->GetNumberOfPoints());
  
  arrayPressure->SetName("pressure");

  // loop over the nodes of the mesh and assign the interpolated p values in the vtk data structure
  // we only consider the cells that are the actual computational domain, not the helper values in the "halo"

  int index = 0;   // index for the vtk data structure, will be incremented in the inner loop
  for (int j = 0; j < nCells[1]+1; j++)
  {
    for (int i = 0; i < nCells[0]+1; i++, index++)
    {
      const double x = i*dx;
      const double y = j*dy;

      arrayPressure->SetValue(index, discretization_->p().interpolateAt(x,y));
    }
  }

  // now, we should have added as many values as there are points in the vtk data structure
  assert(index == dataSet->GetNumberOfPoints());

  // add the field variable to the data set
  dataSet->GetPointData()->AddArray(arrayPressure);
  
  // add velocity field variable
  // ---------------------------
  vtkSmartPointer<vtkDoubleArray> arrayVelocity = vtkDoubleArray::New();

  // here we have two components (u,v), but ParaView will only allow vector glyphs if we have an ℝ^3 vector, 
  // therefore we use a 3-dimensional vector and set the 3rd component to zero
  arrayVelocity->SetNumberOfComponents(3);

  // set the number of values
  arrayVelocity->SetNumberOfTuples(dataSet->GetNumberOfPoints());
  
  arrayVelocity->SetName("velocity");

  // loop over the mesh where p is defined and assign the values in the vtk data structure
  index = 0;   // index for the vtk data structure
  for (int j = 0; j < nCells[1]+1; j++)
  {
    const double y = j*dy;

    for (int i = 0; i < nCells[0]+1; i++, index++)
    {
      const double x = i*dx;

      std::array<double,3> velocityVector;
        velocityVector[0] = discretization_->u().interpolateAt(x,y);
        velocityVector[1] = discretization_->v().interpolateAt(x,y);
      
      velocityVector[2] = 0.0;    // z-direction is 0

      arrayVelocity->SetTuple(index, velocityVector.data());
    }
  }
  // now, we should have added as many values as there are points in the vtk data structure
  assert(index == dataSet->GetNumberOfPoints());

  // add the field variable to the data set
  dataSet->GetPointData()->AddArray(arrayVelocity);

  // add temperature field variable
  // ---------------------------
  vtkSmartPointer<vtkDoubleArray> arrayTemperature = vtkDoubleArray::New();

  // the temperature is a scalar which means the number of components is 1
  arrayTemperature->SetNumberOfComponents(1);

  // Set the number of temperature values and allocate memory for it. We already know the number, it has to be the same as there are nodes in the mesh.
  arrayTemperature->SetNumberOfTuples(dataSet->GetNumberOfPoints());
  
  arrayTemperature->SetName("temperature");

  // loop over the nodes of the mesh and assign the interpolated t values in the vtk data structure
  // we only consider the cells that are the actual computational domain, not the helper values in the "halo"

  index = 0;   // index for the vtk data structure, will be incremented in the inner loop
  for (int j = 0; j < nCells[1]+1; j++)
  {
    for (int i = 0; i < nCells[0]+1; i++, index++)
    {
      const double x = i*dx;
      const double y = j*dy;

      arrayTemperature->SetValue(index, discretization_->T().interpolateAt(x,y));
    }
  }

  // now, we should have added as many values as there are points in the vtk data structure
  assert(index == dataSet->GetNumberOfPoints());

  // add the field variable to the data set
  dataSet->GetPointData()->AddArray(arrayTemperature);

  
  // add current time 
  vtkSmartPointer<vtkDoubleArray> arrayTime = vtkDoubleArray::New();
  arrayTime->SetName("TIME");
  arrayTime->SetNumberOfTuples(1);
  arrayTime->SetTuple1(0, currentTime);
  dataSet->GetFieldData()->AddArray(arrayTime);

  // Remove unused memory
  dataSet->Squeeze();
  
  // Write the data
  vtkWriter_->SetInputData(dataSet);
  
  //vtkWriter_->SetDataModeToAscii();     // comment this in to get ascii text files: those can be checked in an editor
  vtkWriter_->SetDataModeToBinary();      // set file mode to binary files: smaller file sizes

  // finally write out the data
  vtkWriter_->Write();

  dataSet->GetPointData()->RemoveArray("TIME");
  dataSet->GetPointData()->RemoveArray("velocity");
  dataSet->GetPointData()->RemoveArray("pressure");
  dataSet->GetPointData()->RemoveArray("temperature");
  return;


  
    // Create a mapper and actor
  vtkSmartPointer<vtkDataSetMapper> mapper = 
    vtkSmartPointer<vtkDataSetMapper>::New();
  mapper->SetInputData(dataSet);
  vtkSmartPointer<vtkActor> actor = 
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
 
  // Create a renderer, render window, and interactor
  vtkSmartPointer<vtkRenderer> renderer = 
    vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = 
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
 
  // Add the actor to the scene
  renderer->AddActor(actor);
  renderer->SetBackground(.2, .3, .4);
 
  // Render and interact
  renderWindow->Render();
  renderWindowInteractor->Start();
}