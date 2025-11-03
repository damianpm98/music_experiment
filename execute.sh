#!/bin/bash
# This script builds and runs the C++ project using CMake.
# It assumes that CMakeLists.txt is properly configured.

# Change the directory to the location of this script
cd "$(dirname "$0")"

# Create a build directory
mkdir -p build
cd build
# Run CMake to configure the project
cmake ..
# Build the project
make
# Run the executable
./music_experiment
