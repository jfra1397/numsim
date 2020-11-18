# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Infovis/Core

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
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkAddMembershipArray.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkAdjacencyMatrixToEdgeTable.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkArrayNorm.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkArrayToTable.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkCollapseGraph.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkCollapseVerticesByArray.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkContinuousScatterplot.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkDataObjectToTable.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkDotProductSimilarity.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkEdgeCenters.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkExpandSelectedGraph.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkExtractSelectedGraph.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkExtractSelectedTree.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkGenerateIndexArray.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkGraphHierarchicalBundleEdges.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkGroupLeafVertices.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkKCoreDecomposition.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkMergeColumns.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkMergeGraphs.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkMergeTables.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkMutableGraphHelper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkNetworkHierarchy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkPipelineGraphSource.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkPruneTreeFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkRandomGraphSource.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkReduceTable.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkRemoveHiddenData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkRemoveIsolatedVertices.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkSparseArrayToTable.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkStreamGraph.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkStringToCategory.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkStringToNumeric.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkTableToArray.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkTableToGraph.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkTableToSparseArray.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkTableToTreeFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkThresholdGraph.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkThresholdTable.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkTransferAttributes.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkTransposeMatrix.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkTreeDifferenceFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkTreeFieldAggregator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkTreeLevelsFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkVertexDegree.h"
    "/home/jfra/projects/simtech/numsim/VTK/Infovis/Core/vtkWordCloud.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Infovis/Core/vtkInfovisCoreModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkInfovisCore-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkInfovisCore-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkInfovisCore-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkInfovisCore-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkInfovisCore-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.0.so")
    endif()
  endif()
endif()

