
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++20)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(cpp-course)

include_directories(${CMAKE_SOURCE_DIR})

# Create target for each .cc file
FILE(GLOB sources *.cc)
foreach(source ${sources})
  get_filename_component(target ${source} NAME_WE)
  add_executable(${target} ${target}.cc)
endforeach()