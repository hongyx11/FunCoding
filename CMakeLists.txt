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

if(BUILD_CODEFORCE)

    add_subdirectory(codeforces)

endif()

if(BUILD_LEETCODE)

    set(LC_components
    MonotonicQueue
    UnionFind 
    Trie)

    foreach(component ${LC_components})
        add_subdirectory(leetcode/${component})
    endforeach()

endif()
