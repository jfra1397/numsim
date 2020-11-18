# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Views/Infovis

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
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkApplyColors.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkApplyIcons.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkDendrogramItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkGraphItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkGraphLayoutView.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkHeatmapItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkHierarchicalGraphPipeline.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkHierarchicalGraphView.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkIcicleView.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkInteractorStyleAreaSelectHover.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkInteractorStyleTreeMapHover.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkParallelCoordinatesHistogramRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkParallelCoordinatesRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkParallelCoordinatesView.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkRenderedGraphRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkRenderedHierarchyRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkRenderedRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkRenderedSurfaceRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkRenderedTreeAreaRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkRenderView.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkSCurveSpline.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkTanglegramItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkTreeAreaView.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkTreeHeatmapItem.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkTreeMapView.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkTreeRingView.h"
    "/home/jfra/projects/simtech/numsim/VTK/Views/Infovis/vtkViewUpdater.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Views/Infovis/vtkViewsInfovisModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkViewsInfovis-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkViewsInfovis-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkViewsInfovis-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkViewsInfovis-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkViewsInfovis-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.0.so")
    endif()
  endif()
endif()

