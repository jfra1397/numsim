# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Rendering/Core

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
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkGPUInfoListArray.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkNoise200x200.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkPythagoreanQuadruples.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRayCastStructures.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRenderingCoreEnums.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkStateStorage.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Rendering/Core/vtkTDxConfigure.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTDxMotionEventInfo.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAbstractHyperTreeGridMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAbstractMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAbstractMapper3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAbstractPicker.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAbstractVolumeMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkActor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkActor2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkActor2DCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkActorCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAssembly.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAvatar.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkBackgroundColorMonitor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkBillboardTextActor3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCIEDE2000.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCamera.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCameraActor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCameraInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCellCenterDepthSort.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkColorTransferFunction.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCompositeDataDisplayAttributes.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCompositeDataDisplayAttributesLegacy.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCompositePolyDataMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCoordinate.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCuller.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCullerCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkDataSetMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkDiscretizableColorTransferFunction.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkDistanceToCamera.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkFXAAOptions.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkFlagpoleLabel.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkFollower.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkFrameBufferObjectBase.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkFrustumCoverageCuller.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkGPUInfo.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkGPUInfoList.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkGenericVertexAttributeMapping.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkGlyph3DMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkGraphMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkGraphToGlyphs.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkGraphicsFactory.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkHardwareSelector.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkHardwareWindow.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkHierarchicalPolyDataMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkImageActor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkImageMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkImageMapper3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkImageProperty.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkImageSlice.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkImageSliceMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkInteractorEventRecorder.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkInteractorObserver.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkLabeledContourMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkLight.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkLightActor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkLightCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkLightKit.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkLogLookupTable.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkLookupTableWithEnabling.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkMapArrayValues.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkMapper2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkMapperCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkObserverMediator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkPointGaussianMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkPolyDataMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkPolyDataMapper2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkProp.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkProp3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkProp3DCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkProp3DFollower.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkPropAssembly.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkPropCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkProperty.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkProperty2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRenderPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRenderState.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRenderTimerLog.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRenderWindow.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRenderWindowCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRenderWindowInteractor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRenderWindowInteractor3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRenderer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRendererCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRendererDelegate.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRendererSource.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkSelectVisiblePoints.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkShaderProperty.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkSkybox.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkStereoCompositor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTextActor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTextActor3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTexture.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTexturedActor2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTransformCoordinateSystems.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTransformInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTupleInterpolator.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkUniforms.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkViewDependentErrorMetric.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkViewport.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkVisibilitySort.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkVolume.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkVolumeCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkVolumeProperty.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkWindowLevelLookupTable.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkWindowToImageFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkResizingWindowToImageFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAssemblyNode.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAssemblyPath.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAssemblyPaths.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAreaPicker.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkPicker.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAbstractPropPicker.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkLODProp3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkPropPicker.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkPickingManager.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkWorldPointPicker.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkCellPicker.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkPointPicker.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRenderedAreaPicker.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkScenePicker.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkInteractorStyle.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkInteractorStyle3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkInteractorStyleSwitchBase.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTDxInteractorStyle.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTDxInteractorStyleCamera.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTDxInteractorStyleSettings.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkStringToImage.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTextMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTextProperty.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTextPropertyCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkTextRenderer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAbstractInteractionDevice.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkAbstractRenderDevice.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/Core/vtkRenderWidget.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Rendering/Core/vtkRenderingCoreModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkRenderingCore-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkRenderingCore-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkRenderingCore-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkRenderingCore-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkRenderingCore-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.0.so")
    endif()
  endif()
endif()

