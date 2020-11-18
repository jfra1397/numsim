# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Filters/General

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
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkAnnotationLink.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkAppendLocationAttributes.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkAppendPoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkApproximatingSubdivisionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkAreaContourSpectrumFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkAxes.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkBlankStructuredGrid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkBlankStructuredGridWithImage.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkBlockIdScalars.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkBooleanOperationPolyDataFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkBoxClipDataSet.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkBrownianPoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkCellDerivatives.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkCellTreeLocator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkCellValidator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkClipClosedSurface.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkClipConvexPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkClipDataSet.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkClipVolume.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkCoincidentPoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkContourTriangulator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkCountFaces.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkCountVertices.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkCursor2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkCursor3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkCurvatures.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDataSetGradient.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDataSetGradientPrecompute.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDataSetTriangleFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDateToNumeric.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDeflectNormals.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDeformPointSet.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDensifyPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDicer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDiscreteFlyingEdges2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDiscreteFlyingEdges3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDiscreteFlyingEdgesClipper2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDiscreteMarchingCubes.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkDistancePolyDataFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkEdgePoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkExtractArray.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkExtractSelectedFrustum.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkExtractSelectionBase.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkGradientFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkGraphLayoutFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkGraphToPoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkGraphWeightEuclideanDistanceFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkGraphWeightFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkHierarchicalDataLevelFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkHyperStreamline.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkIconGlyphFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkImageDataToPointSet.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkImageMarchingCubes.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkInterpolateDataSetAttributes.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkInterpolatingSubdivisionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkIntersectionPolyDataFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkLevelIdScalars.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkLinkEdgels.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkLoopBooleanPolyDataFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkMarchingContourFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkMatricizeArray.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkMergeArrays.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkMergeCells.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkMultiBlockDataGroupFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkMultiBlockFromTimeSeriesFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkMultiBlockMergeFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkMultiThreshold.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkNormalizeMatrixVectors.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkOBBDicer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkOBBTree.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkOverlappingAMRLevelIdScalars.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkPassArrays.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkPassSelectedArrays.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkPointConnectivityFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkPolyDataStreamer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkPolyDataToReebGraphFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkProbePolyhedron.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkQuadraturePointInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkQuadraturePointsGenerator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkQuadratureSchemeDictionaryGenerator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkQuantizePolyDataPoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkRandomAttributeGenerator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkRectilinearGridClip.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkRectilinearGridToPointSet.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkRectilinearGridToTetrahedra.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkRecursiveDividingCubes.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkReflectionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkRemovePolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkRotationFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkSampleImplicitFunctionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkShrinkFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkShrinkPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkSpatialRepresentationFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkSphericalHarmonics.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkSplineFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkSplitByCellScalarFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkSplitColumnComponents.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkSplitField.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkStructuredGridClip.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkSubPixelPositionEdgels.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkSubdivisionFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkSynchronizeTimeFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkTableBasedClipDataSet.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkTableToPolyData.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkTableToStructuredGrid.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkTemporalPathLineFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkTemporalStatistics.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkTessellatorFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkTimeSourceExample.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkTransformFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkTransformPolyDataFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkUncertaintyTubeFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkVertexGlyphFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkVolumeContourSpectrumFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkVoxelContoursToSurfaceFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkWarpLens.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkWarpScalar.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkWarpTo.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkWarpVector.h"
    "/home/jfra/projects/simtech/numsim/VTK/Filters/General/vtkYoungsMaterialInterface.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Filters/General/vtkFiltersGeneralModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkFiltersGeneral-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkFiltersGeneral-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersGeneral-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersGeneral-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersGeneral-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersGeneral-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersGeneral-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersGeneral-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersGeneral-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersGeneral-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersGeneral-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkFiltersGeneral-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersGeneral-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersGeneral-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersGeneral-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersGeneral-9.0.so")
    endif()
  endif()
endif()

