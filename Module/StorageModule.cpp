//
// Created by Apollyon on 24-7-2.
//
#include "StorageModule.h"
#include <cmath>
#include <iostream>

// 构造函数，初始化测试数据
StorageModule::StorageModule() {
    generateTestData();
}

// 插入节点
void StorageModule::insertNode(const std::string& name, double x, double y, int type) {
    nodes[name] = {name, static_cast<short>(x), static_cast<short>(y), type};
}
void StorageModule::insertNode2( const std::string& name,const std::string& imgepath2, const std::string& imagetext2){
    nodes[name].imagepath = imgepath2;
    nodes[name].imagetext = imagetext2;
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
void StorageModule::reClear(){
  nodes.clear();
    adjMatrix.clear();


};
// 初始化数据
void StorageModule::generateTestData() {
//彩虹大道路段
    insertNode("彩虹大道起点", 153, 562, 1);
    insertNode("彩虹大道与研学路交点1", 136, 538,1);
    insertNode("彩虹大道与研学路交点2", 121, 502,1);
    insertNode("彩虹大道与善学路交点", 128, 481,1);
    insertNode("彩虹大道拐点1", 168, 456,1);
    insertNode("彩虹大道与劝学路交点", 210, 431,1);
    insertNode("彩虹大道与厚学路交点", 248, 390,1);
    insertNode("彩虹大道与力港大道交点", 279, 319,1);
    insertNode("彩虹大道与博学路交点", 282, 249,1);
    insertNode("彩虹大道与笃行路交点（中央食堂）", 350, 182,1);
    insertNode("彩虹大道与乐学路和厚学路交点", 438, 154,1);
    insertNode("彩虹大道拐点2（思进湖）", 269, 361,1);
    insertNode("彩虹大道拐点3（足球场）", 276, 284,1);
    insertNode("彩虹大道拐点4（四创中心）", 313, 209,1);
    insertNode("彩虹大道拐点5（二三教学楼）", 395, 168,1);
    insertNode("彩虹大道拐点6（燕园）", 490, 134,1);
    insertNode("彩虹大道与燕园路交点", 513, 111,1);
    insertNode("彩虹大道终点（花江桥）", 531, 77,1);
//------

    //花江慧谷区域
    insertNode("花江慧谷中上",73,520,1);
    insertNode("花江慧谷中中（花江慧谷区域）",92,560,1);
    insertNode("花江慧谷中下",106,580,1);
    insertNode("花江慧谷左下",68,597,1);
    insertNode("花江慧谷左上",38,542,1);
    insertNode("花江慧谷右上",97,508,1);
//------

    //研学、善学、劝学路区域
    insertNode("研学路拐点1（汀苑）",75,444,2);
    insertNode("研学路与善学路交点",79,423,1);
    insertNode("善学路拐点1",70,398,2);
    insertNode("善学路与劝学路交点",142,356,1);
    insertNode("劝学路与力港大道交点（仲园餐厅）",138,339,1);
    insertNode("劝学路拐点1（溶苑）",171,394,2);
//--------

//紫荆路区域
    insertNode("紫荆路与力港大道交点（润苑）",98,339,1);
    insertNode("紫荆路拐点1",126,268,2);
    insertNode("紫荆路拐点2",171,236,2);
    insertNode("紫荆路拐点3",212,206,2);
    insertNode("紫荆路与求学路交点",235,204,1);
    //-----

//求学路区域
    insertNode("求学路与博学路交点",232,222,1);
    insertNode("求学路拐点下2",207,254,2);
    insertNode("求学路拐点下1",186,284,2);
    insertNode("求学路拐点上1",249,177,2);
    insertNode("求学路拐点上2",276,159,2);
    insertNode("求学路与力港大道交点",184,334,1);
    insertNode("求学路与笃行路和乐学路交点",312,153,1);
//-----

    //乐学路区域
    insertNode("乐学路拐点1（汀苑）",323,132,2);
    insertNode("乐学路拐点2",320,100,2);
    insertNode("乐学路拐点3（清苑）",327,78,2);
    insertNode("乐学路拐点4",340,68,2);
    insertNode("乐学路拐点5",370,64,2);
    insertNode("乐学路拐点6",396,73,2);
    insertNode("乐学路拐点7（花江运动区）",404,91,2);
    insertNode("乐学路拐点8",408,120,2);
    insertNode("乐学路青年教工楼",463,112,3);
    insertNode("淑苑",408,65,3);
    insertNode("北门",337,52,3);
//-----

//燕园路区域
    insertNode("燕园路与致新路交点",548,175,1);
    insertNode("燕园路拐点1（匹克球场）",568,215,2);
    insertNode("燕园路与力港大道交点",574,244,1);
    insertNode("燕园路拐点2",576,285,2);
    insertNode("燕园路拐点3",572,326,2);
    insertNode("燕园路拐点4",561,364,2);
    insertNode("燕园路拐点5",539,398,2);
    insertNode("燕园路拐点6",498,435,2);
    insertNode("燕园路与正德路交点",445,461,1);
    insertNode("南1门",443,542,3);
//-----
    //厚学路区域
    insertNode("厚学路与正德路交点",443,403,1);
    insertNode("厚学路拐点1（工程实训楼）",480,375,2);
    insertNode("厚学路拐点2（思贸湖）",504,337,2);
    insertNode("厚学路拐点3（机电楼）",513,309,2);
    insertNode("厚学路与力港大道交点",516,279,2);
    insertNode("厚学路拐点4（相思湖）",510,247,2);
    insertNode("厚学路与致新路交点",490,210,1);
    insertNode("厚学路拐点5",470,181,2);
    insertNode("四十四教",405,414,1);
    insertNode("厚学路拐点左2",336,401,2);
    insertNode("厚学路拐点左3",301,405,2);
//-----

    //致新路区域
    insertNode("致新路与力港大道交点",370,298,1);
    insertNode("致新路拐点1（马克思主义学院）",367,280,1);
    insertNode("致新路拐点2（六教）",372,256,1);
    insertNode("致新路拐点3（五教）",390,235,1);
    insertNode("致新路与笃学路交点",407,220,1);
    insertNode("致新路拐点4（信息与通信学院）",445,213,1);
    insertNode("致新路拐点5",472,214,2);
    insertNode("致新路拐点6",526,197,2);
//-----

//力港大道区域
    insertNode("11教",394,293,1);
    insertNode("会议中心和办公楼",485,296,1);
    insertNode("力港大道与正德路交点",445,299,1);
    insertNode("力港大道拐点1",550,263,2);
    insertNode("思援湖",318,309,1);
    insertNode("力港大道与潜学路交点",423,294,1);
//-----

    //潜学路区域
    insertNode("潜学路与厚学路和明学路交点",361,403,1);
    insertNode("潜学路拐点1",421,331,1);
    insertNode("潜学路拐点2（十六教）",394,341,1);
    insertNode("潜学路拐点3（十七教）",385,369,1);
//-----
    //明学路区域
    insertNode("明学路与恒学路交点",345,434,1);
    insertNode("明学路与勤学路交点",327,467,1);
    insertNode("南2门",345,526,3);
//-----
//恒学路与勤学路区域
    insertNode("恒学路拐点1（艺术与设计学院）",397,462,1);
    insertNode("恒学路拐点2（四十五教）",363,456,1);
    insertNode("恒学路拐点3（唔学广场）",305,443,1);
    insertNode("恒学路与勤学路交点（雅园餐厅）",278,453,1);
    insertNode("勤学路岔口（濛苑）",263,444,1);
    insertNode("勤学西路",235,446,1);
    insertNode("勤学北路",250,424,1);
    insertNode("勤学北路与彩虹大道交点",233,412,1);
//-----

    //新增结点及道路
    insertNode("清苑",250,46,3);
    insertNode("泾苑",275,118,3);
    insertNode("桃李园",138,100,3);
    insertNode("花江运动区",378,103,3);
    insertNode("思援湖运动区",250,289,3);
    insertNode("思齐湖运动区",366,508,3);
    insertNode("商业街",383,139,3);
    insertNode("中央食堂",360,152,3);
    insertNode("四创中心",269,210,3);
    insertNode("润苑",51,309,3);
    insertNode("汀苑",57,468,3);
    insertNode("溶苑",129,419,3);
    insertNode("濛苑",248,484,3);
    insertNode("思进湖",313,357,3);
    insertNode("思援湖2",311,271,3);
    insertNode("思贤湖",467,360,3);
    insertNode("相思湖",484,258,3);
    insertNode("思齐湖",412,508,3);
    insertNode("燕园",502,163,3);
    insertNode("仲园餐厅",135,309,3);
    insertNode("雅园餐厅",281,432,3);
    insertNode("11，13，14教学楼",373,327,3);
    insertNode("15，16教学楼",413,360,3);
    insertNode("1，2，3教学楼",418,181,3);
    insertNode("44，43，42教学楼",399,441,3);
    insertNode("4，5，6教学楼",364,227,3);
    insertNode("7，8教学楼",347,274,3);
    insertNode("图书馆",412,257,3);
    insertNode("建交与交通工程和机电工程学院",534,334,3);
    insertNode("工程实训大楼",516,376,3);
    insertNode("信息与通信学院",445,203,3);


    insertNode("力港大道新增结点1",237,328,1);
    insertNode("紫荆路新增结点1",109,303,1);
    insertNode("求学路新增结点1",179,311,1);
    insertNode("求学路新增结点2",194,267,1);
    insertNode("研学路新增结点1",84,479,1);
    insertNode("善学路新增结点1",102,451,1);
    insertNode("厚学路新增结点1",272,400,1);


    insertRoad("力港大道新增结点1","求学路与力港大道交点");
    insertRoad("力港大道新增结点1","彩虹大道与力港大道交点");

    insertRoad("紫荆路新增结点1","紫荆路与力港大道交点（润苑）");
    insertRoad("紫荆路新增结点1","紫荆路拐点1");

    insertRoad("求学路新增结点1","求学路拐点下1");
    insertRoad("求学路新增结点1","求学路与力港大道交点");
    insertRoad("求学路新增结点2","求学路拐点下1");
    insertRoad("求学路新增结点2","求学路拐点下2");

    insertRoad("研学路新增结点1","花江慧谷右上");
    insertRoad("研学路新增结点1","研学路拐点1（汀苑）");

    insertRoad("善学路新增结点1","研学路与善学路交点");
    insertRoad("善学路新增结点1","彩虹大道与善学路交点");

    insertRoad("厚学路新增结点1","厚学路拐点左3");
    insertRoad("厚学路新增结点1","彩虹大道与厚学路交点");

    //-----

    //正德路区域（人行区域）
    insertRoad("厚学路与正德路交点","力港大道与正德路交点");
    insertRoad("力港大道与正德路交点","致新路拐点4（信息与通信学院）");

//-----
    insertRoad("劝学路与力港大道交点（仲园餐厅）","求学路与力港大道交点");

    insertRoad("彩虹大道起点","彩虹大道与研学路交点1");
    insertRoad("彩虹大道与研学路交点1","彩虹大道与研学路交点2");
    insertRoad("彩虹大道与研学路交点2","彩虹大道与善学路交点");
    insertRoad("彩虹大道与善学路交点","彩虹大道拐点1");
    insertRoad("彩虹大道拐点1","彩虹大道与劝学路交点");
    insertRoad("彩虹大道与劝学路交点","勤学北路与彩虹大道交点");
    insertRoad("勤学北路与彩虹大道交点","彩虹大道与厚学路交点");
    insertRoad("彩虹大道与厚学路交点","彩虹大道拐点2（思进湖）");
    insertRoad("彩虹大道拐点2（思进湖）","彩虹大道与力港大道交点");
    insertRoad("彩虹大道与力港大道交点","彩虹大道拐点3（足球场）");
    insertRoad("彩虹大道拐点3（足球场）","彩虹大道与博学路交点");
    insertRoad("彩虹大道与博学路交点","彩虹大道拐点4（四创中心）");
    insertRoad("彩虹大道拐点4（四创中心）","彩虹大道与笃行路交点（中央食堂）");
    insertRoad("彩虹大道与笃行路交点（中央食堂）","彩虹大道拐点5（二三教学楼）");
    insertRoad("彩虹大道拐点5（二三教学楼）","彩虹大道与乐学路和厚学路交点");
    insertRoad("彩虹大道与乐学路和厚学路交点","彩虹大道拐点6（燕园）");
    insertRoad("彩虹大道拐点6（燕园）","彩虹大道与燕园路交点");
    insertRoad("彩虹大道与燕园路交点","彩虹大道终点（花江桥）");

    insertRoad("彩虹大道起点","花江慧谷中下");
    insertRoad("彩虹大道与研学路交点1","花江慧谷中中（花江慧谷区域）");
    insertRoad("彩虹大道与研学路交点2","花江慧谷右上");
    insertRoad("花江慧谷右上","花江慧谷中上");
    insertRoad("花江慧谷中上","花江慧谷左上");
    insertRoad("花江慧谷左上","花江慧谷左下");
    insertRoad("花江慧谷左下","花江慧谷中下");
    insertRoad("花江慧谷中下","花江慧谷中中（花江慧谷区域）");
    insertRoad("花江慧谷中中（花江慧谷区域）","花江慧谷中上");

    //insertRoad("花江慧谷右上","研学路拐点1（汀苑）");
    insertRoad("研学路拐点1（汀苑）","研学路与善学路交点");
    insertRoad("研学路与善学路交点","善学路拐点1");
    insertRoad("善学路拐点1","善学路与劝学路交点");
    //insertRoad("研学路与善学路交点","彩虹大道与善学路交点");
    insertRoad("劝学路与力港大道交点（仲园餐厅）","善学路与劝学路交点");
    insertRoad("善学路与劝学路交点","劝学路拐点1（溶苑）");
    insertRoad("劝学路拐点1（溶苑）","彩虹大道与劝学路交点");

    insertRoad("紫荆路与力港大道交点（润苑）","劝学路与力港大道交点（仲园餐厅）");
    //insertRoad("紫荆路与力港大道交点（润苑）","紫荆路拐点1");
    insertRoad("紫荆路拐点1","紫荆路拐点2");
    insertRoad("紫荆路拐点2","紫荆路拐点3");
    insertRoad("紫荆路拐点3","紫荆路与求学路交点");
    insertRoad("劝学路与力港大道交点（仲园餐厅）","求学路与力港大道交点");

    insertRoad("求学路与博学路交点","求学路拐点下2");
    //insertRoad("求学路拐点下1","求学路拐点下2");
    //insertRoad("求学路拐点下1","求学路与力港大道交点");
    insertRoad("求学路与博学路交点","彩虹大道与博学路交点");
    insertRoad("求学路与博学路交点","紫荆路与求学路交点");
    insertRoad("紫荆路与求学路交点","求学路拐点上1");
    insertRoad("求学路拐点上1","求学路拐点上2");
    insertRoad("求学路拐点上2","求学路与笃行路和乐学路交点");
    //insertRoad("求学路与力港大道交点","彩虹大道与力港大道交点");

    insertRoad("求学路与笃行路和乐学路交点","彩虹大道与笃行路交点（中央食堂）");
    insertRoad("求学路与笃行路和乐学路交点","乐学路拐点1（汀苑）");
    insertRoad("乐学路拐点1（汀苑）","乐学路拐点2");
    insertRoad("乐学路拐点2","乐学路拐点3（清苑）");
    insertRoad("乐学路拐点3（清苑）","乐学路拐点4");
    insertRoad("乐学路拐点4","北门");
    insertRoad("乐学路拐点4","乐学路拐点5");
    insertRoad("乐学路拐点5","乐学路拐点6");
    insertRoad("乐学路拐点6","淑苑");
    insertRoad("乐学路拐点6","乐学路拐点7（花江运动区）");
    insertRoad("乐学路拐点7（花江运动区）","乐学路拐点8");
    insertRoad("乐学路拐点8","乐学路青年教工楼");
    insertRoad("乐学路拐点8","彩虹大道与乐学路和厚学路交点");

    insertRoad("厚学路与正德路交点","燕园路与正德路交点");
    insertRoad("厚学路与正德路交点","厚学路拐点1（工程实训楼）");
    insertRoad("厚学路拐点1（工程实训楼）","厚学路拐点2（思贸湖）");
    insertRoad("厚学路拐点2（思贸湖）","厚学路拐点3（机电楼）");
    insertRoad("厚学路拐点3（机电楼）","厚学路与力港大道交点");
    insertRoad("厚学路与力港大道交点","厚学路拐点4（相思湖）");
    insertRoad("厚学路拐点4（相思湖）","厚学路与致新路交点");
    insertRoad("厚学路与致新路交点","厚学路拐点5");
    insertRoad("厚学路拐点5","彩虹大道与乐学路和厚学路交点");
    insertRoad("厚学路与正德路交点","四十四教");
    insertRoad("四十四教","潜学路与厚学路和明学路交点");
    insertRoad("潜学路与厚学路和明学路交点","厚学路拐点左2");
    insertRoad("厚学路拐点左2","厚学路拐点左3");
    //insertRoad("厚学路拐点左3","彩虹大道与厚学路交点");

    insertRoad("致新路与笃学路交点","彩虹大道与笃行路交点（中央食堂）");
    insertRoad("致新路与力港大道交点","致新路拐点1（马克思主义学院）");
    insertRoad("致新路拐点1（马克思主义学院）","致新路拐点2（六教）");
    insertRoad("致新路拐点2（六教）","致新路拐点3（五教）");
    insertRoad("致新路拐点3（五教）","致新路与笃学路交点");
    insertRoad("致新路与笃学路交点","致新路拐点4（信息与通信学院）");
    insertRoad("致新路拐点4（信息与通信学院）","致新路拐点5");
    insertRoad("致新路拐点5","厚学路与致新路交点");
    insertRoad("厚学路与致新路交点","致新路拐点6");
    insertRoad("致新路拐点6","燕园路与致新路交点");

    insertRoad("彩虹大道与力港大道交点","思援湖");
    insertRoad("思援湖","致新路与力港大道交点");
    insertRoad("致新路与力港大道交点","11教");
    insertRoad("11教","力港大道与潜学路交点");
    insertRoad("力港大道与潜学路交点","力港大道与正德路交点");
    insertRoad("力港大道与正德路交点","会议中心和办公楼");
    insertRoad("会议中心和办公楼","厚学路与力港大道交点");
    insertRoad("厚学路与力港大道交点","力港大道拐点1");
    insertRoad("力港大道拐点1","燕园路与力港大道交点");

    insertRoad("潜学路与厚学路和明学路交点","潜学路拐点3（十七教）");
    insertRoad("潜学路拐点3（十七教）","潜学路拐点2（十六教）");
    insertRoad("潜学路拐点2（十六教）","潜学路拐点1");
    insertRoad("潜学路拐点1","力港大道与潜学路交点");

    insertRoad("潜学路与厚学路和明学路交点","明学路与恒学路交点");
    insertRoad("明学路与恒学路交点","明学路与勤学路交点");
    insertRoad("明学路与勤学路交点","南2门");

    insertRoad("燕园路与正德路交点","恒学路拐点1（艺术与设计学院）");
    insertRoad("恒学路拐点1（艺术与设计学院）","恒学路拐点2（四十五教）");
    insertRoad("恒学路拐点2（四十五教）","明学路与恒学路交点");
    insertRoad("明学路与恒学路交点","恒学路拐点3（唔学广场）");
    insertRoad("恒学路拐点3（唔学广场）","恒学路与勤学路交点（雅园餐厅）");
    insertRoad("恒学路与勤学路交点（雅园餐厅）","明学路与勤学路交点");
    insertRoad("恒学路与勤学路交点（雅园餐厅）","勤学路岔口（濛苑）");
    insertRoad("勤学路岔口（濛苑）","勤学北路");
    insertRoad("勤学北路","勤学北路与彩虹大道交点");
    insertRoad("勤学路岔口（濛苑）","勤学西路");
    insertRoad("勤学西路","彩虹大道与劝学路交点");

    insertRoad("彩虹大道与燕园路交点","燕园路与致新路交点");
    insertRoad("燕园路与致新路交点","燕园路拐点1（匹克球场）");
    insertRoad("燕园路拐点1（匹克球场）","燕园路与力港大道交点");
    insertRoad("燕园路与力港大道交点","燕园路拐点2");
    insertRoad("燕园路拐点2","燕园路拐点3");
    insertRoad("燕园路拐点3","燕园路拐点4");
    insertRoad("燕园路拐点4","燕园路拐点5");
    insertRoad("燕园路拐点5","燕园路拐点6");
    insertRoad("燕园路拐点6","燕园路与正德路交点");
    insertRoad("燕园路与正德路交点","南1门");
}
