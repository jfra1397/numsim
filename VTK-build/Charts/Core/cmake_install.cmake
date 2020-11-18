# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Charts/Core

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
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkAxis.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkAxisExtended.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkCategoryLegend.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkChartBox.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkChart.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkChartHistogram2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkChartLegend.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkChartMatrix.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkChartParallelCoordinates.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkChartPie.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkChartXY.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkChartXYZ.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkColorLegend.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkColorTransferControlPointsItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkColorTransferFunctionItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkCompositeControlPointsItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkCompositeTransferFunctionItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkContextArea.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkContextPolygon.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkControlPointsItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkInteractiveArea.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkLookupTableItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPiecewiseControlPointsItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPiecewiseFunctionItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPiecewisePointHandleItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlot3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotArea.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotBag.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotBar.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotBox.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlot.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotFunctionalBag.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotGrid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotHistogram2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotLine3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotLine.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotParallelCoordinates.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotPie.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotPoints3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotPoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotRangeHandlesItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotStacked.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkPlotSurface.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkRangeHandlesItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkScalarsToColorsItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Charts/Core/vtkScatterPlotMatrix.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Charts/Core/vtkChartsCoreModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkChartsCore-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkChartsCore-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkChartsCore-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkChartsCore-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkChartsCore-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.0.so")
    endif()
  endif()
endif()

