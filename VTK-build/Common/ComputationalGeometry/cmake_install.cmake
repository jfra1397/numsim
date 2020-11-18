# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry

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
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkBilinearQuadIntersection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkCardinalSpline.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkKochanekSpline.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricBohemianDome.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricBour.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricBoy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricCatalanMinimal.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricConicSpiral.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricCrossCap.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricDini.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricEllipsoid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricEnneper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricFigure8Klein.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricFunction.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricHenneberg.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricKlein.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricKuen.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricMobius.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricPluckerConoid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricPseudosphere.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricRandomHills.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricRoman.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricSpline.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricSuperEllipsoid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricSuperToroid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Common/ComputationalGeometry/vtkParametricTorus.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Common/ComputationalGeometry/vtkCommonComputationalGeometryModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkCommonComputationalGeometry-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkCommonComputationalGeometry-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkCommonComputationalGeometry-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkCommonComputationalGeometry-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkCommonComputationalGeometry-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.0.so")
    endif()
  endif()
endif()

