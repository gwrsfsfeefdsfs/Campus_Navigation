//
// Created by Monster on 24-7-2.
//
// StorageModule.h
#ifndef STORAGE_MODULE_H
#define STORAGE_MODULE_H

#include <vector>
#include <string>

// 定义节点结构
struct Node {
    std::string name;
    double x, y; // 节点坐标
};

// 定义道路结构
struct Road {
    std::string from;
    std::string to;
    double length; // 道路长度
};

class StorageModule {
private:
    std::vector<Node> nodes; // 存储节点信息
    std::vector<Road> roads; // 存储道路信息

public:
    // 构造函数
    StorageModule();

    // 插入节点
    void insertNode(const std::string& name, double x, double y);

    // 插入道路
    void insertRoad(const std::string& from, const std::string& to);

    // 删除节点
    void deleteNode(const std::string& name);

    // 删除道路
    void deleteRoad(const std::string& from, const std::string& to);

    // 修改节点名称
    void modifyNodeName(const std::string& oldName, const std::string& newName);

    // 获取节点列表
    const std::vector<Node>& getNodes() const;

    // 获取道路列表
    const std::vector<Road>& getRoads() const;

    // 生成测试数据
    void generateTestData();
};

#endif // STORAGE_MODULE_H
