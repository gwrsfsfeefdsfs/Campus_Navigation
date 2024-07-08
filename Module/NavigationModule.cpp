//
// Created by Apollyon on 24-7-2.
//
#include "NavigationModule.h"
#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

NavigationModule::NavigationModule(StorageModule& storage) : storage(storage) {}

// 使用 Dijkstra 算法查找最短路径
double NavigationModule::findShortestPath(const std::string& start, const std::string& end) {
    const auto& adjMatrix = storage.getAdjMatrix();
    if (adjMatrix.find(start) == adjMatrix.end() || adjMatrix.find(end) == adjMatrix.end()) {
        return std::numeric_limits<double>::infinity();
    }

    // 初始化距离
    std::unordered_map<std::string, double> distances;
    std::unordered_map<std::string, std::string> previous;
    for (const auto& pair : adjMatrix) {
        distances[pair.first] = std::numeric_limits<double>::infinity();
    }
    distances[start] = 0;

    // 优先队列存储节点和距离
    std::priority_queue<std::pair<double, std::string>, std::vector<std::pair<double, std::string>>, std::greater<>> pq;
    pq.push({0, start});

    // 处理队列中的节点
    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();

        if (node == end) {
            break;
        }

        for (const auto& neighbor : adjMatrix.at(node)) {
            double newDist = dist + neighbor.second;
            if (newDist < distances[neighbor.first]) {
                distances[neighbor.first] = newDist;
                previous[neighbor.first] = node;
                pq.push({newDist, neighbor.first});
            }
        }
    }

    // 记录最短路径
    shortestPath.clear();
    for (std::string at = end; at != ""; at = previous[at]) {
        shortestPath.push_back(at);
        if (at == start) break;
    }
    std::reverse(shortestPath.begin(), shortestPath.end());
    return distances[end];
}

// 获取最短路径的节点信息
const std::vector<std::string>& NavigationModule::getShortestPath() const {
    return shortestPath;
}