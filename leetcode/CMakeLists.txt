set(monotonicqueuebin 
239
862)

foreach(bin ${monotonicqueuebin})
    add_executable(${bin} ${CMAKE_CURRENT_LIST_DIR}/MonotonicQueue/${bin}.cpp)
endforeach()
