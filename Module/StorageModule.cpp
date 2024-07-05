#include "StorageModule.h"
#include <cmath>

// 构造函数，初始化测试数据
StorageModule::StorageModule() {
    generateTestData();
}

// 插入节点
void StorageModule::insertNode(const std::string& name, double x, double y) {
    static int node_id_counter = 0;
    nodes[name] = {name, static_cast<short>(x), static_cast<short>(y)};
}

// 插入道路，计算并存储两节点间的距离
void StorageModule::insertRoad(const std::string& from, const std::string& to) {
    if (nodes.find(from) != nodes.end() && nodes.find(to) != nodes.end()) {
        double distance = sqrt(pow(nodes[from].x - nodes[to].x, 2) + pow(nodes[from].y - nodes[to].y, 2));
        adjMatrix[from][to] = distance;
        adjMatrix[to][from] = distance; // 无向图
    }
}

// 删除节点及其相关的道路信息
void StorageModule::deleteNode(const std::string& name) {
    nodes.erase(name);
    adjMatrix.erase(name);
    for (auto& pair : adjMatrix) {
        pair.second.erase(name);
    }
}

// 删除道路信息
void StorageModule::deleteRoad(const std::string& from, const std::string& to) {
    adjMatrix[from].erase(to);
    adjMatrix[to].erase(from);
}

// 修改节点名称
void StorageModule::modifyNodeName(const std::string& oldName, const std::string& newName) {
    if (nodes.find(oldName) != nodes.end()) {
        Node node = nodes[oldName];
        node.name = newName;
        nodes.erase(oldName);
        nodes[newName] = node;

        adjMatrix[newName] = adjMatrix[oldName];
        adjMatrix.erase(oldName);

        for (auto& pair : adjMatrix) {
            if (pair.second.find(oldName) != pair.second.end()) {
                pair.second[newName] = pair.second[oldName];
                pair.second.erase(oldName);
            }
        }
    }
}

// 获取节点列表
const std::unordered_map<std::string, Node>& StorageModule::getNodes() const {
    return nodes;
}

// 获取邻接矩阵
const std::unordered_map<std::string, std::unordered_map<std::string, double>>& StorageModule::getAdjMatrix() const {
    return adjMatrix;
}
// 初始化数据
void StorageModule::generateTestData() {
    insertNode("A1", 446, 553);
    insertNode("A2", 446, 460);
    insertNode("A3", 446, 402);
    insertNode("A4", 446, 296);
    insertRoad("A1", "A2");
    insertRoad("A2", "A3");
    insertRoad("A3", "A4");
}
