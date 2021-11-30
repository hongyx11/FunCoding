set(src appletree10153)

foreach(bin ${src})
    add_executable(${bin} ${CMAKE_CURRENT_LIST_DIR}/${bin}.cpp)
endforeach()
