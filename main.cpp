#include <conio.h>
#include <graphics.h>// 引用图形库头文件
#include <iostream>
#include "Menu.h"
#include "StorageModule.h"
#include "OperationalModule.h"
#include "NavigationModule.h"

using namespace std;

int main(){
    // 创建存储模块对象
    StorageModule storage;

    // 创建操作模块对象
    OperationalModule operations(storage);

    // 创建导航模块对象
    NavigationModule navigation(storage);

    // 在这里可以编写主程序的逻辑
    Menu a;

    return 0;
}
