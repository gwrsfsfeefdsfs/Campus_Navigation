//
// Created by Monster on 24-7-2.
//
#include "StorageModule.h"

StorageModule::StorageModule() {
    // 初始化
}

void StorageModule::insertNode(const std::string& name, short x, short y) {
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
