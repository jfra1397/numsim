# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/IO/Legacy

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
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkCompositeDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkCompositeDataWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkDataObjectReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkDataObjectWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkDataSetReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkDataSetWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkDataWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkGenericDataObjectReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkGenericDataObjectWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkGraphReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkGraphWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkPixelExtentIO.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkPolyDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkPolyDataWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkRectilinearGridReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkRectilinearGridWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkSimplePointsReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkSimplePointsWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkStructuredGridReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkStructuredGridWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkStructuredPointsReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkStructuredPointsWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkTableReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkTableWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkTreeReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkTreeWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkUnstructuredGridReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/Legacy/vtkUnstructuredGridWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/IO/Legacy/vtkIOLegacyModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkIOLegacy-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkIOLegacy-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkIOLegacy-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkIOLegacy-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkIOLegacy-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.0.so")
    endif()
  endif()
endif()

