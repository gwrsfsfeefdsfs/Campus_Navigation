//
// Created by Apollyon on 24-7-2.
//
#ifndef STORAGE_MODULE_H
#define STORAGE_MODULE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <graphics.h>

// 节点结构体，包含节点名称、坐标和类型
struct Node {
    std::string name;   // 节点名称
    short x, y;         // 节点坐标
    int type;           // 节点类型:临时节点（0）、路口节点（1）、弯心节点（2）、建筑节点（3）
    std::string imagepath;//建筑节点图片
    std::string imagetext;//建筑节点文字
};

class StorageModule {
private:
    // 使用哈希表存储节点信息
    std::unordered_map<std::string, Node> nodes;
    // 使用邻接矩阵存储道路长度信息
    std::unordered_map<std::string, std::unordered_map<std::string, double>> adjMatrix;

public:
    // 构造函数
    StorageModule();

    // 插入节点
    void insertNode(const std::string& name, double x, double y,int type);
    //插入建筑节点图片信息
    void insertNode_building( const std::string& name,const std::string& imgepath2);
    // 插入道路
    void insertRoad(const std::string& from, const std::string& to);
    // 删除节点
    void deleteNode(const std::string& name);
    // 删除道路
    void deleteRoad(const std::string& from, const std::string& to);
    // 修改节点名称
    void modifyNodeName(const std::string& oldName, const std::string& newName);

    // 获取节点列表
    const std::unordered_map<std::string, Node>& getNodes() const;
    // 获取邻接矩阵
    const std::unordered_map<std::string, std::unordered_map<std::string, double>>& getAdjMatrix() const;
    void reClear();
    // 生成测试数据
    void generateTestData();
};

#endif // STORAGE_MODULE_H
