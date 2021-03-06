project(Test)

include(CTest)
enable_testing()

include(DownloadProject.cmake)
download_project(
        PROJ    googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

add_executable(runUnitTests gtest.cpp algorithm_tests/quick_sort_test.cpp algorithm_tests/merge_sort_test.cpp algorithm_tests/insertion_sort_test.cpp algorithm_tests/sort_test.h container_tests/chaining_hashmap_test.cpp container_tests/lock_based_queue_test.cpp)
target_link_libraries(runUnitTests gtest gmock lib)
