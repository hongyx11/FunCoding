cmake_minimum_required(VERSION 3.10)

set (PROJECT_NAME Trie)
PROJECT(${PROJECT_NAME} C CXX)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")   
set(CMAKE_C_STANDARD 11)
# directly make an error if in-source build
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
message(FATAL_ERROR "In-source builds are not allowed.\n"
"Please create a build directory first and "
"execute cmake configuration from "
"this directory. Example: mkdir build && cd build && cmake ..")
endif()



set(BINS 
Kthsmall_lexorder_440)
foreach(bin ${BINS})
    add_executable(${bin} ${bin}.cpp)
endforeach()
