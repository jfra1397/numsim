# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets

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
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtk3DWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkAbstractPolygonalHandleRepresentation3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkAbstractWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkAffineRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkAffineRepresentation2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkAffineWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkAngleRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkAngleRepresentation2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkAngleRepresentation3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkAngleWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkAxesTransformRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkAxesTransformWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBalloonRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBalloonWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBezierContourLineInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBiDimensionalRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBiDimensionalRepresentation2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBiDimensionalWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBorderRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBorderWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBoundedPlanePointPlacer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBoxRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBoxWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBoxWidget2.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkBrokenLineWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkButtonRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkButtonWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkCameraRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkCameraWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkCaptionRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkCaptionWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkCellCentersPointPlacer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkCenteredSliderRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkCenteredSliderWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkCheckerboardRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkCheckerboardWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkClosedSurfacePointPlacer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkConstrainedPointHandleRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkContinuousValueWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkContinuousValueWidgetRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkContourLineInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkContourRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkContourWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkCurveRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkDijkstraImageContourLineInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkDistanceRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkDistanceRepresentation2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkDistanceRepresentation3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkDistanceWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkEllipsoidTensorProbeRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkEvent.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkFinitePlaneRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkFinitePlaneWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkFixedSizeHandleRepresentation3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkFocalPlaneContourRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkFocalPlanePointPlacer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkHandleRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkHandleWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkHoverWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkImageActorPointPlacer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkImageCroppingRegionsWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkImageOrthoPlanes.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkImagePlaneWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkImageTracerWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkImplicitCylinderRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkImplicitCylinderWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkImplicitImageRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkImplicitPlaneRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkImplicitPlaneWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkImplicitPlaneWidget2.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkLightRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkLightWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkLinearContourLineInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkLineRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkLineWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkLineWidget2.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkLogoRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkLogoWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkMagnifierRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkMagnifierWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkMeasurementCubeHandleRepresentation3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkOrientationMarkerWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkOrientedGlyphContourRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkOrientedGlyphFocalPlaneContourRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkOrientedPolygonalHandleRepresentation3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkParallelopipedRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkParallelopipedWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPlaneWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPlaybackRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPlaybackWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPointCloudRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPointCloudWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPointHandleRepresentation2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPointHandleRepresentation3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPointPlacer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPointWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPolyDataContourLineInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPolyDataPointPlacer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPolyDataSourceWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPolygonalHandleRepresentation3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPolygonalSurfaceContourLineInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPolygonalSurfacePointPlacer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPolyLineRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkPolyLineWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkProgressBarRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkProgressBarWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkProp3DButtonRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkRectilinearWipeRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkRectilinearWipeWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkResliceCursor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkResliceCursorActor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkResliceCursorLineRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkResliceCursorPicker.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkResliceCursorPolyDataAlgorithm.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkResliceCursorRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkResliceCursorThickLineRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkResliceCursorWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkScalarBarRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkScalarBarWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSeedRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSeedWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSliderRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSliderRepresentation2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSliderRepresentation3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSliderWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSphereHandleRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSphereRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSphereWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSphereWidget2.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSplineRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSplineWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkSplineWidget2.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkTensorRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkTensorWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkTensorProbeRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkTensorProbeWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkTerrainContourLineInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkTerrainDataPointPlacer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkTextRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkTexturedButtonRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkTexturedButtonRepresentation2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkTextWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkWidgetCallbackMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkWidgetEvent.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkWidgetEventTranslator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkWidgetRepresentation.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkWidgetSet.h"
    "/home/jfra/projects/simtech/numsim/VTK/Interaction/Widgets/vtkXYPlotWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Interaction/Widgets/vtkInteractionWidgetsModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkInteractionWidgets-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkInteractionWidgets-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInteractionWidgets-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInteractionWidgets-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkInteractionWidgets-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkInteractionWidgets-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInteractionWidgets-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInteractionWidgets-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInteractionWidgets-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInteractionWidgets-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInteractionWidgets-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkInteractionWidgets-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInteractionWidgets-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInteractionWidgets-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInteractionWidgets-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInteractionWidgets-9.0.so")
    endif()
  endif()
endif()

