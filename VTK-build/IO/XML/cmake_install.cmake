# Install script for directory: /home/jfra/projects/simtech/numsim/VTK/IO/XML

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
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkRTXMLPolyDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLCompositeDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLCompositeDataWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLDataObjectWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLDataSetWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLFileReadTester.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLGenericDataObjectReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLHierarchicalBoxDataFileConverter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLHierarchicalBoxDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLHierarchicalBoxDataWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLHierarchicalDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLHyperTreeGridReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLHyperTreeGridWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLImageDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLImageDataWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLMultiBlockDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLMultiBlockDataWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLMultiGroupDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPDataObjectReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPHyperTreeGridReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPImageDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPPolyDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPRectilinearGridReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPStructuredDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPStructuredGridReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPTableReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPUnstructuredDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPUnstructuredGridReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPartitionedDataSetCollectionReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPartitionedDataSetCollectionWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPartitionedDataSetReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPartitionedDataSetWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPolyDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLPolyDataWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLRectilinearGridReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLRectilinearGridWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLStructuredDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLStructuredDataWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLStructuredGridReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLStructuredGridWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLTableReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLTableWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLUniformGridAMRReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLUniformGridAMRWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLUnstructuredDataReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLUnstructuredDataWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLUnstructuredGridReader.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLUnstructuredGridWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLWriter.h"
    "/home/jfra/projects/simtech/numsim/VTK/IO/XML/vtkXMLWriterC.h"
    "/home/jfra/projects/simtech/numsim/VTK-build/IO/XML/vtkIOXMLModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk/hierarchy/VTK" TYPE FILE RENAME "vtkIOXML-hierarchy.txt" FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/vtk/hierarchy/VTK/vtkIOXML-hierarchy.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOXML-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOXML-9.0.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkIOXML-9.0.so.9.0.0"
    "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkIOXML-9.0.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOXML-9.0.so.9.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOXML-9.0.so.1"
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOXML-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOXML-9.0.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOXML-9.0.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jfra/projects/simtech/numsim/VTK-build/lib/libvtkIOXML-9.0.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOXML-9.0.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOXML-9.0.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOXML-9.0.so"
         OLD_RPATH "/home/jfra/projects/simtech/numsim/VTK-build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOXML-9.0.so")
    endif()
  endif()
endif()

