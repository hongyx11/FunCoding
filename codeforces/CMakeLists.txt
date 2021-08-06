set(simple 
TheatreSquare
Watermelon)

foreach(bin ${simple})
    add_executable(${bin} ${CMAKE_CURRENT_LIST_DIR}/simple/${bin}.cpp)
endforeach()


install(FILES ${CMAKE_CURRENT_LIST_DIR}/Test/test.txt DESTINATION Test)