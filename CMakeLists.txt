cmake_minimum_required(VERSION 3.6)
project(datastructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall")

set(SOURCE_FILES main.cpp includes/container/bst.h includes/container/binary_node.h includes/container/avl.h includes/container/avl_node.h includes/algorithm/insertion_sort.h includes/container/btree_node.h includes/container/btree.h includes/algorithm/heap_sort.h includes/algorithm/merge_sort.h includes/algorithm/quick_sort.h impl/disj_sets.cpp includes/container/disj_sets.h includes/container/chaining_hashmap.h)
add_library(lib includes/container/bst.h includes/container/binary_node.h includes/container/avl.h includes/container/avl_node.h includes/algorithm/insertion_sort.h includes/container/btree_node.h includes/container/btree.h includes/algorithm/heap_sort.h includes/algorithm/merge_sort.h includes/algorithm/quick_sort.h impl/disj_sets.cpp includes/container/disj_sets.h includes/container/chaining_hashmap.h)
add_executable(datastructures ${SOURCE_FILES})

add_subdirectory(tests)