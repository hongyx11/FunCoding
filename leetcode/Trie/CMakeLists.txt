cmake_minimum_required(VERSION 3.10)

set (PROJECT_NAME Trie)
PROJECT(${PROJECT_NAME} CXX)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")   
set(CMAKE_CXX_STANDARD 11)

# directly make an error if in-source build
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
message(FATAL_ERROR "In-source builds are not allowed.\n")
endif()


set(BINS 
ImplementTrie_208
Kthsmall_lexorder_440
SearchSuggestSystem_1268)
foreach(bin ${BINS})
    add_executable(${bin} ${bin}.cpp)
endforeach()
