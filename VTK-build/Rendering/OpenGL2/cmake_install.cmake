# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2

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
    "/home/jfra/projects/simtech/numsim/VTK-build/Rendering/OpenGL2/vtkOpenGLError.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Rendering/OpenGL2/vtkRenderingOpenGLConfigure.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkCameraPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkClearRGBPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkClearZPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkCompositePolyDataMapper2.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkDataTransferHelper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkDefaultPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkDepthImageProcessingPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkDepthOfFieldPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkDepthPeelingPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkDualDepthPeelingPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkEDLShading.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkEquirectangularToCubeMapTexture.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkFramebufferPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkGaussianBlurPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkGenericOpenGLRenderWindow.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkHiddenLineRemovalPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkImageProcessingPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkLightingMapPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkLightsPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpaquePass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLActor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLBillboardTextActor3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLBufferObject.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLCamera.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLCellToVTKCellMap.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLFXAAFilter.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLFXAAPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLFluidMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLFramebufferObject.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLGL2PSHelper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLGlyph3DHelper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLGlyph3DMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLHardwareSelector.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLHelper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLImageAlgorithmHelper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLImageMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLImageSliceMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLIndexBufferObject.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLInstanceCulling.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLLabeledContourMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLLight.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLPointGaussianMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLPolyDataMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLPolyDataMapper2D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLProperty.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLQuadHelper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLRenderPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLRenderTimer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLRenderTimerLog.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLRenderUtilities.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLRenderWindow.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLRenderer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLShaderCache.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLShaderProperty.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLSkybox.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLSphereMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLState.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLStickMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLTextActor.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLTextActor3D.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLTextMapper.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLTexture.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLUniforms.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLVertexArrayObject.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLVertexBufferObject.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLVertexBufferObjectCache.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGLVertexBufferObjectGroup.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOrderIndependentTranslucentPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOutlineGlowPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOverlayPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkPanoramicProjectionPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkPixelBufferObject.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkPointFillPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkPBRIrradianceTexture.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkPBRLUTTexture.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkPBRPrefilterTexture.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkRenderPassCollection.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkRenderStepsPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkRenderbuffer.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkSSAAPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkSSAOPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkSequencePass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkShader.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkShaderProgram.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkShadowMapBakerPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkShadowMapPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkSimpleMotionBlurPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkSobelGradientMagnitudePass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkTextureObject.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkTextureUnitManager.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkToneMappingPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkTransformFeedback.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkTranslucentPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkValuePass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkVolumetricPass.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkDummyGPUInfoList.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkXOpenGLRenderWindow.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/Rendering/OpenGL2/vtkRenderingOpenGL2Module.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkCompositePolyDataMapper2Internal.h"
    "/home/jfra/projects/simtech/numsim/VTK/Rendering/OpenGL2/vtkOpenGL.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkRenderingOpenGL2-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkRenderingOpenGL2-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkRenderingOpenGL2-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkRenderingOpenGL2-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkRenderingOpenGL2-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.0.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vtkProbeOpenGLVersion-9.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vtkProbeOpenGLVersion-9.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vtkProbeOpenGLVersion-9.0"
         RPATH "\$ORIGIN/../lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/jfra/projects/simtech/numsim/VTK-build/bin/vtkProbeOpenGLVersion-9.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vtkProbeOpenGLVersion-9.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vtkProbeOpenGLVersion-9.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vtkProbeOpenGLVersion-9.0"
         OLD_RPATH "\$ORIGIN/../lib:"
         NEW_RPATH "\$ORIGIN/../lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vtkProbeOpenGLVersion-9.0")
    endif()
  endif()
endif()

