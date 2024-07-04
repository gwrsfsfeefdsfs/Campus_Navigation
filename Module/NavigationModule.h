//
// Created by Monster on 24-7-4.
//
#ifndef NAVIGATION_MODULE_H
#define NAVIGATION_MODULE_H

#include "StorageModule.h"

class NavigationModule {
private:
    StorageModule& storage;

public:
    // 构造函数
    NavigationModule(StorageModule& storage);

    // 导航函数，如求解最短路径等
};

#endif // NAVIGATION_MODULE_H
