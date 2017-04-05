cmake_minimum_required(VERSION 3.0)
project(csword)

# use standard library C 2011
# and use features supported by almost compilers
# to work on cross-platform
set(CMAKE_C_FLAGS "-std=c11")

# output directory
# dynamic and static libraries => lib
# exutables => bin
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

link_directories(dep/lib)
include_directories(dep/inc)
include_directories(src/inc)
add_subdirectory(src)
