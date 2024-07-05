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
    insertNode("彩虹大道起点", 153, 562);
    insertNode("彩虹大道与研学路交点1", 136, 538);
    insertNode("彩虹大道与研学路交点2", 121, 502);
    insertNode("彩虹大道与善学路交点", 128, 481);
    insertNode("彩虹大道与劝学路交点", 210, 431);
    insertNode("彩虹大道与厚学路交点", 248, 390);
    insertNode("彩虹大道与力港大道交点", 279, 319);
    insertNode("彩虹大道与博学路交点", 282, 249);
    insertNode("彩虹大道与笃行路交点", 350, 182);
    insertNode("彩虹大道与乐学路和厚学路交点", 438, 154);
    insertNode("彩虹大道拐点1", 269, 361);
    insertNode("彩虹大道拐点2", 279, 281);
    insertNode("彩虹大道拐点3", 313, 209);
    insertNode("彩虹大道拐点4", 395, 168);
    insertNode("彩虹大道拐点5", 490, 134);
    insertNode("彩虹大道与燕圆路交点", 513, 111);
    insertNode("彩虹大道终点", 531, 77);

    insertNode("花江慧谷中上",73,520);
    insertNode("花江慧谷中中",92,560);
    insertNode("花江慧谷中下",106,580);
    insertNode("花江慧谷左下",68,597);
    insertNode("花江慧谷左上",38,542);
    insertNode("花江慧谷右上",97,508);

    insertNode("研学路拐点",75,444);
    insertNode("研学路与善学路交点",79,423);
    insertNode("善学路拐点1",70,398);
    insertNode("善学路与劝学路交点",142,356);
    insertNode("劝学路与力港大道交点",138,339);
    insertNode("紫荆路与力港大道交点",98,339);
    insertNode("紫荆路拐点1",126,268);
    insertNode("紫荆路拐点2",171,236);
    insertNode("紫荆路拐点3",212,206);
    insertNode("紫荆路与求学路交点",235,204);
    insertNode("求学路与博学路交点",232,222);
    insertNode("求学路拐点1",207,254);
    insertNode("求学路拐点2",186,284);
    insertNode("求学路拐点3",249,177);
    insertNode("求学路拐点4",276,159);
    insertNode("求学路与力港大道交点",184,334);
    insertNode("求学路与笃行路和乐学路交点",312,153);

    insertNode("乐学路拐点1",323,132);
    insertNode("乐学路拐点2",320,100);
    insertNode("乐学路拐点3",327,78);
    insertNode("乐学路拐点4",340,68);
    insertNode("乐学路拐点5",370,64);
    insertNode("乐学路拐点6",396,73);
    insertNode("乐学路拐点7",404,91);
    insertNode("乐学路拐点8",408,120);
    insertNode("乐学路青年教工楼",463,112);
    insertNode("淑苑",408,65);
    insertNode("北门",338,59);

    insertNode("燕圆路与致新路交点",548,175);
    insertNode("燕圆路拐点1",568,215);
    insertNode("燕圆路与力港大道交点",574,244);
    insertNode("燕圆路拐点2",576,285);
    insertNode("燕圆路拐点3",572,326);
    insertNode("燕圆路拐点4",561,364);
    insertNode("燕圆路拐点5",539,398);
    insertNode("燕圆路拐点6",498,435);
    insertNode("燕圆路与正德路交点",445,461);
    insertNode("南1门",443,542);

    insertNode("厚学路与正德路交点",443,403);
    insertNode("厚学路拐点1",480,375);
    insertNode("厚学路拐点2",504,337);
    insertNode("厚学路拐点3",513,309);
    insertNode("厚学路与力港大道交点",516,279);
    insertNode("厚学路拐点4",510,247);
    insertNode("厚学路与致新路交点",490,210);
    insertNode("厚学路拐点5",470,181);
    insertNode("厚学路拐点左1",405,414);
    insertNode("厚学路拐点左2",336,401);
    insertNode("厚学路拐点左3",301,405);

    insertNode("致新路与力港大道交点",370,298);
    insertNode("致新路拐点1",367,280);
    insertNode("致新路拐点2",372,256);
    insertNode("致新路拐点3",390,235);
    insertNode("致新路与笃学路拐点",407,220);
    insertNode("致新路拐点4",445,213);
    insertNode("致新路拐点5",472,214);
    insertNode("致新路拐点6",526,197);

    insertNode("力港大道拐点2",485,296);
    insertNode("力港大道与正德路交点",445,299);
    insertNode("力港大道拐点1",394,293);
    insertNode("力港大道拐点3",550,263);
    insertNode("力港大道与潜学路交点",423,294);

    insertNode("潜学路与厚学路交点",361,403);
    insertNode("潜学路拐点2",394,341);
    insertNode("潜学路拐点3",385,369);
    insertNode("潜学路与厚学路交点",361,403);

    insertNode("明学路与恒学路交点",345,434);
    insertNode("明学路与勤学路交点",327,467);
    insertNode("南2门",345,526);

    insertNode("恒学路拐点1",397,462);
    insertNode("恒学路拐点2",363,456);
    insertNode("恒学路拐点3",305,443);
    insertNode("恒学路与勤学路交点",278,453);
    insertNode("勤学路岔口",263,444);
    insertNode("勤学北路",235,446);
    insertNode("勤学西路",250,424);
    insertNode("勤学西路与彩虹大道交点",233,412);
    


}
