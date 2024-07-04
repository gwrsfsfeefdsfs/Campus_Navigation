//
// Created by Monster on 24-7-2.
//
// StorageModule.cpp

#include "StorageModule.h"

StorageModule::StorageModule() {
    // 初始化
    generateTestData(); // 调用生成测试数据的函数
}

void StorageModule::insertNode(const std::string& name, double x, double y) {
    // 实现插入节点的逻辑
}

void StorageModule::insertRoad(const std::string& from, const std::string& to) {
    // 实现插入道路的逻辑
}

void StorageModule::deleteNode(const std::string& name) {
    // 实现删除节点的逻辑
}

void StorageModule::deleteRoad(const std::string& from, const std::string& to) {
    // 实现删除道路的逻辑
}

void StorageModule::modifyNodeName(const std::string& oldName, const std::string& newName) {
    // 实现修改节点名称的逻辑
}

const std::vector<Node>& StorageModule::getNodes() const {
    return nodes;
}

const std::vector<Road>& StorageModule::getRoads() const {
    return roads;
}

void StorageModule::generateTestData() {
    // 添加一些节点信息
    insertNode("A", 0.0, 0.0);
    insertNode("B", 1.0, 1.0);
    insertNode("C", 2.0, 2.0);
    insertNode("D", 3.0, 3.0);

    // 添加一些道路信息（假设直线距离作为道路长度）
    insertRoad("A", "B");
    insertRoad("B", "C");
    insertRoad("C", "D");
    insertRoad("A", "C");
}
