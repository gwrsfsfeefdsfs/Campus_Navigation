cmake_minimum_required(VERSION 3.28)
project(Campus_Navigation)

set(CMAKE_CXX_STANDARD 17)
link_libraries(libeasyx.a libgdi32.a libole32.a)
add_executable(Campus_Navigation main.cpp
        Menu.h)

# 添加可执行文件并链接模块
add_executable(CampusNavigation main.cpp)

# 添加子目录，包含各个模块的 CMakeLists.txt
add_subdirectory(Module)