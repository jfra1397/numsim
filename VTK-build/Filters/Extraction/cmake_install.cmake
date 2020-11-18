# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Filters/Extraction

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
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkBlockSelector.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkConvertSelection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExpandMarkedElements.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractBlock.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractBlockUsingDataAssembly.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractCells.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractCellsByType.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractDataArraysOverTime.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractDataOverTime.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractDataSets.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractEdges.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractExodusGlobalTemporalVariables.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractGeometry.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractGrid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractLevel.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractPolyDataGeometry.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractRectilinearGrid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractSelectedArraysOverTime.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractSelectedBlock.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractSelectedIds.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractSelectedLocations.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractSelectedPolyDataIds.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractSelectedRows.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractSelectedThresholds.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractSelection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractTemporalFieldData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractTensorComponents.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractTimeSteps.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractUnstructuredGrid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkExtractVectorComponents.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkFrustumSelector.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkHierarchicalDataExtractDataSets.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkHierarchicalDataExtractLevel.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkLocationSelector.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkProbeSelectedLocations.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkSelector.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Extraction/vtkValueSelector.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Filters/Extraction/vtkFiltersExtractionModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkFiltersExtraction-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkFiltersExtraction-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersExtraction-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersExtraction-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersExtraction-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersExtraction-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersExtraction-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersExtraction-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersExtraction-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersExtraction-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersExtraction-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersExtraction-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersExtraction-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersExtraction-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersExtraction-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersExtraction-9.0.so")
    endif()
  endif()
endif()

