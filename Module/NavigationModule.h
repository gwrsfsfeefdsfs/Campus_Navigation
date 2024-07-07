#ifndef NAVIGATION_MODULE_H
#define NAVIGATION_MODULE_H

#include "StorageModule.h"
#include <string>
#include <vector>

class NavigationModule {
private:
    StorageModule& storage;

public:
    // 构造函数
    NavigationModule(StorageModule& storage);

    // 查找最短路径
    double findShortestPath(const std::string& start, const std::string& end,std::string LP[]);
};

#endif // NAVIGATION_MODULE_H
