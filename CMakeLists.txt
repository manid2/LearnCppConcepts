#####################################################################
# Project level CMakeLists.txt file
#####################################################################

cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

project(LearnCppConcepts)

# Get the list of sub directories in the project
macro(LIST_SUBDIRS result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/[^.]*)
  message(STATUS "curdir: " ${curdir})
  message(STATUS "========== Finding modules to build ==========")
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      list(APPEND dirlist ${child})
      message( STATUS "Found subdir: " ${child} )
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()

# List the sub directories in the project
message(STATUS "CMAKE_SOURCE_DIR:         " ${CMAKE_SOURCE_DIR})
LIST_SUBDIRS(SUBDIRS ${CMAKE_SOURCE_DIR})

# Add sub directories to the project
message(STATUS "========== Adding modules to build ==========")
foreach(subdir ${SUBDIRS})
  add_subdirectory(${subdir})
  message(STATUS "Added subdir: " ${subdir})
endforeach()
message(STATUS "========== All modules are added ==========")

# Add gtest and gmock at configure time if tests are requested
# TODO integrate googletest with ctest with conditional test build
if(BUILD_TESTING)
  message("BUILD_TESTING is enabled")
  # get latest googletest code
  configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
  execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
      WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
  execute_process(COMMAND "${CMAKE_COMMAND}" --build .
      WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

  # add googletest to the project build
  add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                   "${CMAKE_BINARY_DIR}/googletest-build")
else()
  message("BUILD_TESTING is disabled")
endif()

# Use the below cmake command to generate the cmake eclipse project
# cmake ../LearnCppConcepts \
#       -G"Eclipse CDT4 - Unix Makefiles" \
#       -DCMAKE_ECLIPSE_GENERATE_SOURCE_PROJECT=TRUE \
#       -DCMAKE_BUILD_TYPE=Debug \
#       -DCMAKE_CXX_FLAGS="-std=c++11" \
#       -DCMAKE_CXX_COMPILER_ARG1=-std=c++11
