cmake_minimum_required(VERSION 3.6)
project(datastructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp includes/bst.h)
add_executable(datastructures ${SOURCE_FILES})