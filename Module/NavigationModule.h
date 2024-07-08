//
// Created by Apollyon on 24-7-2.
//
#ifndef NAVIGATION_MODULE_H
#define NAVIGATION_MODULE_H


#include "StorageModule.h"
#include <string>
#include <vector>

class NavigationModule {
private:
    StorageModule& storage;                 // 引用存储模块
    std::vector<std::string> shortestPath;  // 存储最短路径的节点信息

public:
    // 构造函数
    NavigationModule(StorageModule& storage);

    // 查找最短路径
    double findShortestPath(const std::string& start, const std::string& end);

    // 获取最短路径的节点信息
    const std::vector<std::string>& getShortestPath() const;
};

#endif // NAVIGATION_MODULE_H