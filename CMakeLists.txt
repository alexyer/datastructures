cmake_minimum_required(VERSION 3.6)
project(datastructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp includes/bst.h includes/binary_node.h includes/avl.h includes/avl_node.h includes/algorithms/insertion_sort.h includes/btree_node.h includes/btree.h includes/algorithms/heap_sort.h includes/algorithms/merge_sort.h includes/algorithms/quick_sort.h)
add_executable(datastructures ${SOURCE_FILES})