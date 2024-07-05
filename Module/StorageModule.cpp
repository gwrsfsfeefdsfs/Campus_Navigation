#include "StorageModule.h"
#include <cmath>

// 构造函数，初始化测试数据
StorageModule::StorageModule() {
    generateTestData();
}

// 插入节点
void StorageModule::insertNode(const std::string& name, short x, short y, int type) {
    nodes[name] = {name, x, y, type};
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
const std::unordered_map<std::string, Node>& StorageModule::getNodes() {
    return nodes;
}

// 获取邻接矩阵
const std::unordered_map<std::string, std::unordered_map<std::string, double>>& StorageModule::getAdjMatrix() {
    return adjMatrix;
}

// 初始化数据
void StorageModule::generateTestData() {
    insertNode("彩虹大道起点", 153, 562, 1);
    insertNode("彩虹大道与研学路交点1", 136, 538, 1);
    insertNode("彩虹大道与研学路交点2", 121, 502, 1);
    insertNode("彩虹大道与善学路交点", 128, 481, 1);
    insertNode("彩虹大道与劝学路交点", 210, 431, 1);
    insertNode("彩虹大道与厚学路交点", 248, 390, 1);
    insertNode("彩虹大道与力港大道交点", 278, 323, 1);
    insertNode("彩虹大道与博学路交点", 287, 243, 1);
    insertNode("彩虹大道与笃行路交点", 350, 182, 1);
    insertNode("彩虹大道与乐学路和厚学路交点", 438, 154, 1);
    insertNode("彩虹大道拐点", 490, 134, 2);
    insertNode("彩虹大道与燕圆路交点", 513, 111, 1);
    insertNode("彩虹大道终点", 531, 77, 1);
}
