# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Filters/Parallel

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
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkBlockDistribution.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkAdaptiveTemporalInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkAggregateDataSetFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkAngularPeriodicFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkCollectGraph.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkCollectPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkCollectTable.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkCutMaterial.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkDistributedDataFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkDuplicatePolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkExtractCTHPart.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkExtractPolyDataPiece.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkExtractUnstructuredGridPiece.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkExtractUserDefinedPiece.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkHyperTreeGridGhostCellsGenerator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkIntegrateAttributes.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPassThroughFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPCellDataToPointData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPExtractDataArraysOverTime.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPExtractExodusGlobalTemporalVariables.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPExtractSelectedArraysOverTime.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPeriodicFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPKdTree.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPLinearExtrusionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPMaskPoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPMergeArrays.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPOutlineCornerFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPOutlineFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPOutlineFilterInternals.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPPolyDataNormals.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPProbeFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPProjectSphereFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPReflectionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPResampleFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPSphereSource.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPYoungsMaterialInterface.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPieceRequestFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPieceScalars.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPipelineSize.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkProcessIdScalars.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkPTextureMapToSphere.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkRectilinearGridOutlineFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkRemoveGhosts.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkTransmitPolyDataPiece.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkTransmitStructuredDataPiece.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkTransmitRectilinearGridPiece.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkTransmitStructuredGridPiece.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkTransmitUnstructuredGridPiece.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Parallel/vtkUnstructuredGridGhostCellsGenerator.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Filters/Parallel/vtkFiltersParallelModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkFiltersParallel-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkFiltersParallel-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersParallel-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersParallel-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersParallel-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.0.so")
    endif()
  endif()
endif()

