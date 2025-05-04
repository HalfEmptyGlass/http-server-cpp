cmake_minimum_required(VERSION 3.10)
project(httpservercpp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the compilers (Clang is set through tasks.json, but also a fallback)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# Define include directories
include_directories(include)

# Collect all source files in the src folder
file(GLOB SOURCES "src/*.cpp")

# Create the executable for the project
add_executable(httpservercpp ${SOURCES})