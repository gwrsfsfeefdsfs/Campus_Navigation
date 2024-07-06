#include "OperationalModule.h"

// 构造函数
OperationalModule::OperationalModule(StorageModule& storage) : storage(storage) {}

// 添加节点
void OperationalModule::addNode(const std::string& name, double x, double y, int type) {
    storage.insertNode(name, x, y, type);
}

// 添加道路
void OperationalModule::addRoad(const std::string& from, const std::string& to) {
    storage.insertRoad(from, to);
}

// 移除节点
void OperationalModule::removeNode(const std::string& name) {
    storage.deleteNode(name);
}

// 移除道路
void OperationalModule::removeRoad(const std::string& from, const std::string& to) {
    storage.deleteRoad(from, to);
}

// 修改节点名称
void OperationalModule::changeNodeName(const std::string& oldName, const std::string& newName) {
    storage.modifyNodeName(oldName, newName);
}
