cmake_minimum_required (VERSION 2.6)

# Project NAme
project (numsim)


# Prefix paths
#set(PATH /home/jfra/projects/simtech/numsim)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)


# Debug?
set(CMAKE_BUILD_TYPE Debug)
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

# Sources
set(SOURCES ../src/main.cpp
            ../src/settings.cpp
            ../src/field_variable.cpp
            ../src/array2d.cpp
            ../src/staggered_grid.cpp
            ../src/discretization.cpp
            ../src/central_differences.cpp
            ../src/donor_cell.cpp
            ../src/solver.cpp
            ../src/gauss_seidel.cpp
            ../src/sor.cpp
            ../src/output_writer/output_writer.cpp
            #../src/output_writer/output_writer_text.cpp
            ../src/output_writer/output_writer_paraview.cpp

                        )


# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

# Search for the external package "VTK"
find_package(VTK)

# Output various cmake variables for demonstration purpose
message("If VTK was found on the system: VTK_FOUND: ${VTK_FOUND}")
message("The directory of VTK: VTK_DIR: ${VTK_DIR}")
message("The include directory of VTK: VTK_INCLUDE_DIRS: ${VTK_INCLUDE_DIRS}")

# If an installation of vtk was found on the system
if (VTK_FOUND)
  include_directories(${VTK_INCLUDE_DIRS})               # add the include directory where the header files are for the compiler
  target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES}) # add the libraries for the linker
endif(VTK_FOUND)

# install numsim executable in build directory
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/../build)

# Set the version of the C++ standard to use, we use C++14, published in 2014
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)