#####################################################################
# Project level CMakeLists.txt file
#####################################################################

cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

project(LearnCppConcepts)

# Add sub directories to the project
add_subdirectory(threads)
add_subdirectory(vtable)
add_subdirectory(samples)

# Use the below cmake command to generate the cmake eclipse project
# cmake ../LearnCppConcepts \
#       -G"Eclipse CDT4 - Unix Makefiles" \
#       -DCMAKE_ECLIPSE_GENERATE_SOURCE_PROJECT=TRUE \
#       -DCMAKE_BUILD_TYPE=Debug \
#       -DCMAKE_CXX_FLAGS="-std=c++11" \
#       -DCMAKE_CXX_COMPILER_ARG1=-std=c++11
