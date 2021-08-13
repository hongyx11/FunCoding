cmake_minimum_required(VERSION 3.10)

set (PROJECT_NAME Coding)
PROJECT(${PROJECT_NAME} CXX)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")   
set(CMAKE_CXX_STANDARD 11)

# directly make an error if in-source build
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
message(FATAL_ERROR "In-source builds are not allowed.\n")
endif()

include_directories(${CMAKE_SOURCE_DIR})

option(BUILD_CODEFORCE "build codeforces" ON)
option(BUILD_LEETCODE "build leetcode" ON)


set(LIBSRC template/BinaryIndexedTree.cpp)
add_library(algolib ${LIBSRC})
target_include_directories(algolib PUBLIC ${CMAKE_SOURCE_DIR}/template)

if(BUILD_CODEFORCE)

    add_subdirectory(codeforces)

endif()

if(BUILD_LEETCODE)

    set(LC_components
    MonotonicQueue
    MonotonicStack
    UnionFind 
    BinarySearch
    BinaryIndexedTree
    BitManipulation
    SegmentTree
    Greedy
    Trie)

    foreach(component ${LC_components})
        add_subdirectory(leetcode/${component})
    endforeach()

endif()

if(BUILD_TEST)
add_subdirectory(thirdparty/googletest)

set(TESTBIN BinaryIndexedTree_test)
add_executable(${TESTBIN} test/${TESTBIN}.cpp)
target_include_directories(${TESTBIN} PUBLIC ${CMAKE_SOURCE_DIR}/template)
target_link_libraries(${TESTBIN} gtest algolib)
endif()