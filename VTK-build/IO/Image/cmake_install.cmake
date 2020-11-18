# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/IO/Image

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
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkBMPReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkBMPWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkDEMReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkDICOMImageReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkGESignaReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkHDRReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkImageExport.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkImageImport.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkImageImportExecutive.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkImageReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkImageReader2.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkImageReader2Collection.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkImageReader2Factory.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkImageWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkJPEGReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkJPEGWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkJSONImageWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkMedicalImageProperties.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkMedicalImageReader2.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkMetaImageReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkMetaImageWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkMRCReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkNIFTIImageHeader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkNIFTIImageReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkNIFTIImageWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkNrrdReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkOMETIFFReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkPNGReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkPNGWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkPNMReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkPNMWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkPostScriptWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkSEPReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkSLCReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkTIFFReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkTIFFWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkVolume16Reader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Image/vtkVolumeReader.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/IO/Image/vtkIOImageModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkIOImage-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkIOImage-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOImage-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOImage-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkIOImage-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkIOImage-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOImage-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOImage-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOImage-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOImage-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOImage-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkIOImage-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOImage-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOImage-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOImage-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOImage-9.0.so")
    endif()
  endif()
endif()

