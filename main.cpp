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
    storage.generateTestData();

    // 测试导航功能
    std::string start = "A";
    std::string end = "D";
    double distance = navigation.findShortestPath(start, end);

    // 输出最短路径距离
    std::cout << "从 " << start << " 到 " << end << " 的最短路径距离是: " << distance << std::endl;


    // 在这里可以编写主程序的逻辑
    Menu a;

    return 0;
}
