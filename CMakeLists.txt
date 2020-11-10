cmake_minimum_required (VERSION 2.6)

# Project NAme
project (numsim)

# Prefix paths
#set(PATH /home/jfra/projects/simtech/numsim)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

#find_package(VTK)

# # Output various cmake variables for demonstration purpose
# message("If VTK was found on the system: VTK_FOUND: ${VTK_FOUND}")
# message("The directory of VTK: VTK_DIR: ${VTK_DIR}")
# message("The include directory of VTK: VTK_INCLUDE_DIRS: ${VTK_INCLUDE_DIRS}")

# # If an installation of vtk was found on the system
# if (VTK_FOUND)
#   include_directories(${VTK_INCLUDE_DIRS})               # add the include directory where the header files are for the compiler
#   target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES}) # add the libraries for the linker
# endif(VTK_FOUND)

# Debug?
set(CMAKE_BUILD_TYPE Debug)
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

# Sources
set(SOURCES ../src/main.cpp
            ../src/settings.cpp
            ../src/field_variable.cpp
            ../src/array2d.cpp

                        )

# Libraries
#find_library(SEP_LIB
#        NAMES libsep.so
#        HINTS ${SEP_PATH}/src
#        REQUIRED
#)

#add_library(SEP_LIB SHARED IMPORTED)

# Create executable
add_executable(numsim.out ${SOURCES})
