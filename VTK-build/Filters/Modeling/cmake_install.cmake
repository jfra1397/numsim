# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Filters/Modeling

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
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkAdaptiveSubdivisionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkBandedPolyDataContourFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkButterflySubdivisionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkCollisionDetectionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkContourLoopExtraction.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkCookieCutter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkDijkstraGraphGeodesicPath.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkDijkstraImageGeodesicPath.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkFillHolesFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkFitToHeightMapFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkGeodesicPath.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkGraphGeodesicPath.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkHausdorffDistancePointSetFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkHyperTreeGridOutlineFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkImageDataOutlineFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkLinearCellExtrusionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkLinearExtrusionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkLinearSubdivisionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkLoopSubdivisionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkOutlineFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkPolyDataPointSampler.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkProjectedTexture.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkQuadRotationalExtrusionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkRibbonFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkRotationalExtrusionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkRuledSurfaceFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkSectorSource.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkSelectEnclosedPoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkSelectPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkSpherePuzzle.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkSpherePuzzleArrows.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkSubdivideTetra.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkTrimmedExtrusionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/Modeling/vtkVolumeOfRevolutionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Filters/Modeling/vtkFiltersModelingModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkFiltersModeling-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkFiltersModeling-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersModeling-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersModeling-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersModeling-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersModeling-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersModeling-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersModeling-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersModeling-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersModeling-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersModeling-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersModeling-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersModeling-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersModeling-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersModeling-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersModeling-9.0.so")
    endif()
  endif()
endif()

