# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Filters/Core

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-9.0" TYPE FILE FILES
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtk3DLinearGridPlaneCutter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkAppendArcLength.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkAppendCompositeDataLeaves.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkAppendDataSets.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkAppendFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkAppendPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkAppendSelection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkArrayCalculator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkAssignAttribute.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkAttributeDataToFieldDataFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkBinCellDataFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkBinnedDecimation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkCellDataToPointData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkCellCenters.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkCenterOfMass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkCleanPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkClipPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkCompositeCutter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkCompositeDataProbeFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkConnectivityFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkContour3DLinearGrid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkContourFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkContourGrid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkContourHelper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtk3DLinearGridCrinkleExtractor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkCutter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkDataObjectGenerator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkDataObjectToDataSetFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkDataSetEdgeSubdivisionCriterion.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkDataSetToDataObjectFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkDecimatePolylineFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkDecimatePro.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkDelaunay2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkDelaunay3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkEdgeSubdivisionCriterion.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkElevationFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkExecutionTimer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkExplicitStructuredGridCrop.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkExplicitStructuredGridToUnstructuredGrid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkFeatureEdges.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkFieldDataToAttributeDataFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkFlyingEdges2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkFlyingEdges3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkFlyingEdgesPlaneCutter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkGlyph2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkGlyph3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkGridSynchronizedTemplates3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkHedgeHog.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkHull.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkIdFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkImageDataToExplicitStructuredGrid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkImageAppend.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkImplicitPolyDataDistance.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkImplicitProjectOnPlaneDistance.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkMarchingCubes.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkMarchingSquares.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkMaskFields.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkMaskPoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkMaskPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkMassProperties.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkMergeDataObjectFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkMergeFields.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkMergeFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkMoleculeAppend.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkMultiObjectMassProperties.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkPassThrough.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkPlaneCutter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkPointDataToCellData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkPolyDataConnectivityFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkPolyDataEdgeConnectivityFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkPolyDataNormals.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkPolyDataTangents.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkProbeFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkQuadricClustering.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkQuadricDecimation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkRearrangeFields.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkRectilinearSynchronizedTemplates.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkRemoveDuplicatePolys.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkRemoveUnusedPoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkResampleToImage.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkResampleWithDataSet.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkReverseSense.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkSimpleElevationFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkSmoothPolyDataFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkSphereTreeFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkStaticCleanPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkStreamerBase.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkStreamingTessellator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkStripper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkStructuredGridAppend.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkStructuredGridOutlineFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkSynchronizedTemplates2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkSynchronizedTemplates3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkSynchronizedTemplatesCutter3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkTensorGlyph.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkThreshold.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkThresholdPoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkTransposeTable.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkTriangleFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkTriangleMeshPointNormals.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkTubeBender.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkTubeFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkUnstructuredGridQuadricDecimation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkUnstructuredGridToExplicitStructuredGrid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkVectorDot.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkVectorNorm.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkVoronoi2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Core/vtkWindowedSincPolyDataFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Filters/Core/vtkFiltersCoreModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkFiltersCore-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkFiltersCore-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersCore-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersCore-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersCore-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersCore-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersCore-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersCore-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersCore-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersCore-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersCore-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersCore-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersCore-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersCore-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersCore-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersCore-9.0.so")
    endif()
  endif()
endif()

