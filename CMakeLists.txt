cmake_minimum_required(VERSION 3.28)
project(Campus_Navigation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(./EasyX/include)
link_directories(./EasyX/lib64)
link_libraries(libeasyx.a)
# 添加可执行文件并链接模块
add_executable(CampusNavigation main.cpp)
# 添加子目录，包含各个模块的 CMakeLists.txt
add_subdirectory(Module)