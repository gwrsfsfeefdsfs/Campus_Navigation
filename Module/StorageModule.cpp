//
// Created by Monster on 24-7-2.
//

#include "StorageStructure.h"
#include <iostream>
#include <vector>

using namespace std;

// 结点的结构体，包括坐标信息
struct Node {
    int x, y;  // 坐标
    Node(int _x, int _y) : x(_x), y(_y) {}
};

// 无向图类
class Graph {
private:
    int V;  // 结点数
    vector<Node> nodes;  // 存储结点的坐标
    vector<vector<int>> adjList;  // 邻接表，存储边的信息

public:
    // 构造函数，初始化结点数和邻接表
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    // 添加边
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // 添加结点
    void addNode(int x, int y) {
        nodes.emplace_back(x, y);
    }

    // 打印图的邻接表表示
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            cout << "Node " << v << " (" << nodes[v].x << ", " << nodes[v].y << "): ";
            for (auto node : adjList[v]) {
                cout << "(" << nodes[node].x << ", " << nodes[node].y << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    // 创建一个包含 5 个结点的无向图
    Graph g(5);

    // 添加结点的坐标信息
    g.addNode(1, 1);  // Node 0
    g.addNode(2, 2);  // Node 1
    g.addNode(3, 3);  // Node 2
    g.addNode(4, 4);  // Node 3
    g.addNode(5, 5);  // Node 4

    // 添加边的信息
    g.addEdge(0, 1);  // Edge between Node 0 and Node 1
    g.addEdge(1, 2);  // Edge between Node 1 and Node 2
    g.addEdge(2, 3);  // Edge between Node 2 and Node 3
    g.addEdge(3, 4);  // Edge between Node 3 and Node 4
    g.addEdge(4, 0);  // Edge between Node 4 and Node 0

    // 打印图的邻接表表示
    g.printGraph();

    return 0;
}


