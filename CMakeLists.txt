cmake_minimum_required(VERSION 3.28)
project(Campus_Navigation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(EasyX_ROOT D:/Visual Studio 2022) # 将路径替换成你电脑中VS的安装路径

include_directories(./EasyX/include)
link_directories(./EasyX/lib64)
link_libraries(libeasyx.a)
# 添加可执行文件并链接模块
add_executable(CampusNavigation main.cpp
        Menu.h
        TextBox.h)
# 添加子目录，包含各个模块的 CMakeLists.txt
add_subdirectory(Module)

# 添加可执行文件
#add_executable(Campus_Navigation main.cpp)

# 链接EasyX库
#target_link_libraries(Campus_Navigation easyx)