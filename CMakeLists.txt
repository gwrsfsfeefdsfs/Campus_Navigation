cmake_minimum_required(VERSION 3.28)
project(Campus_Navigation)

set(CMAKE_CXX_STANDARD 17)
link_libraries(libeasyx.a libgdi32.a libole32.a)
add_executable(Campus_Navigation main.cpp)
