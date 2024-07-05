#include <conio.h>
#include <graphics.h>// 引用图形库头文件
#include <iostream>
#include "Menu.h"
#include "Module/StorageModule.h"
#include "Module/OperationalModule.h"
#include "Module/NavigationModule.h"

using namespace std;

int main(){
    // 创建存储模块对象
    StorageModule storage;

    // 创建操作模块对象
    OperationalModule operations(storage);

    // 创建导航模块对象
    NavigationModule navigation(storage);

    // 插入测试数据
    // storage.generateTestData();

    // 测试导航功能
     std::string start = "A1";
     std::string end = "A2";
     double distance = navigation.findShortestPath(start, end);

    // 输出最短路径距离


    // 在这里可以编写主程序的逻辑
    Menu a(storage);

}
