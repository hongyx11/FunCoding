cmake_minimum_required(VERSION 3.18)

set (PROJECT_NAME Coding)
PROJECT(${PROJECT_NAME} C CXX)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11 -O3")   

# directly make an error if in-source build
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
message(FATAL_ERROR "In-source builds are not allowed.\n"
"Please create a build directory first and "
"execute cmake configuration from "
"this directory. Example: mkdir build && cd build && cmake ..")
endif()

set(codeforcebin 
A_Watermelon)

foreach(bin ${codeforcebin})
    add_executable(${bin} codeforces/${bin}.cpp)
endforeach()




