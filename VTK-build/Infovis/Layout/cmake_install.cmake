# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Infovis/Layout

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
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkArcParallelEdgeStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkAreaLayout.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkAreaLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkAssignCoordinates.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkAssignCoordinatesLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkAttributeClustering2DLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkBoxLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkCirclePackFrontChainLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkCirclePackLayout.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkCirclePackLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkCirclePackToPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkCircularLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkClustering2DLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkCommunity2DLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkConeLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkConstrained2DLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkCosmicTreeLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkEdgeLayout.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkEdgeLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkFast2DLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkForceDirectedLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkGeoEdgeStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkGeoMath.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkGraphLayout.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkGraphLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkIncrementalForceLayout.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkKCoreLayout.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkPassThroughEdgeStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkPassThroughLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkPerturbCoincidentVertices.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkRandomLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkSimple2DLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkSimple3DCirclesStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkSliceAndDiceLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkSpanTreeLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkSplineGraphEdges.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkSquarifyLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkStackedTreeLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkTreeLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkTreeMapLayout.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkTreeMapLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkTreeMapToPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkTreeOrbitLayoutStrategy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Layout/vtkTreeRingToPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Infovis/Layout/vtkInfovisLayoutModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkInfovisLayout-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkInfovisLayout-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkInfovisLayout-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkInfovisLayout-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkInfovisLayout-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.0.so")
    endif()
  endif()
endif()

