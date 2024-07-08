//
// Created by Apollyon on 24-7-2.
//
#ifndef OPERATIONAL_MODULE_H
#define OPERATIONAL_MODULE_H

#include "StorageModule.h"

class OperationalModule {
private:
    StorageModule& storage;

public:
    // 构造函数
    OperationalModule(StorageModule& storage);
    // 添加节点
    void addNode(const std::string& name, double x, double y, const int type);
    // 添加道路
    void addRoad(const std::string& from, const std::string& to);
    // 移除节点
    void removeNode(const std::string& name);
    // 移除道路
    void removeRoad(const std::string& from, const std::string& to);
    // 修改节点名称
    void changeNodeName(const std::string& oldName, const std::string& newName);
};

#endif // OPERATIONAL_MODULE_H
