//
// Created by Admin on 24-7-2.
//
#ifndef MENU_H
#define MENU_H

#define NUM 500
#define M 11

#include "Module/NavigationModule.h"
#include "Module/OperationalModule.h"
#include "Module/StorageModule.h"
#include <cmath>
#include <map>
#include "Image/image.h"
#include "TextBox.h"
// 实例化存储和导航模块
StorageModule storageT;
NavigationModule navigation(storageT);

//Menu 类定义
class Menu {
public:
    MOUSEMSG m{};
    std::unordered_map<std::string, Node> nodes;
    Tooltip tooltip;
    std::string currentNodeKey;
    bool isOverNode;
    // 构造函数
    Menu() {
        // 初始化图形界面
        initgraph(800, 600, EW_SHOWCONSOLE | EW_DBLCLKS);
        setbkcolor(WHITE);
        cleardevice();
        int tempsx=-1;
        int tempsy=-1;
        int tempex=-1;
        int tempey=-1;
        int road=-1;
        IMAGE img1;
        IMAGE img2;
        IMAGE img3;
        IMAGE img4;
        int nodeNum = 0;
        Node po[M];
        bool drawS=false,drawE=false;
        // 加载图像
        loadimage(&img1, "../UI.png", 800, 600);
        loadimage(&img2, "../guetMap.png", 600, 600);
        loadimage(&img3, "../temp2333.png", 146, 40);
        loadimage(&img4, "../logo.png", 90, 80);
        drawAlpha(&img1, 0, 0);
        drawAlpha(&img2, 0, 0);
        drawAlpha(&img4, 700, 500);
        drawAlpha(&img3, 629, 132);
        drawAlpha(&img3, 629, 198);
        drawAlpha(&img3, 629, 274);
        // 获取节点和邻接矩阵
        setbkmode(TRANSPARENT);
        std::unordered_map<std::string, Node> map = storageT.getNodes();
        for(auto kv: map){
            if (kv.second.type==3)
                {
                    IMAGE img;
                    loadimage(&img, "../temp233.png",10,10);
                    drawAlpha(&img,kv.second.x-3,kv.second.y-3);}
                }
        std::unordered_map<std::string, std::unordered_map<std::string, double>> map1 = storageT.getAdjMatrix();
        centerText("出发地",630,100,36,140,20);
        centerText("目的地",630,172,30,140,20);
        centerText("路程距离",630,239,40,140,20);
        centerText("重选",633,345,28,147,20);
        // 主循环
        while (1) {
            m = GetMouseMsg();
            bool overNode = false;
            for (auto& kv : map) {
                Node node = kv.second;
                if (m.x >= node.x - 5 && m.x <= node.x + 5 && m.y >= node.y - 5 && m.y <= node.y + 5 && node.type==3) {
                    tooltip.show(m.x, m.y, node.imagetext, node.imagepath);
                    overNode = true;
                    break;
                }
            }
            if (!overNode && isOverNode) {
                tooltip.hide();
            }
            isOverNode = overNode;

            // 判断鼠标在地图区域内
            if (m.x >= 0 && m.x <= 600 && m.y >= 0 && m.y <= 600) {
                if (m.uMsg == WM_LBUTTONDOWN) {
                    bool Isdraw=false;
                    if (drawE&&drawS) {
                        storageT.reClear();
                        storageT.generateTestData();
                        cleardevice();
                        drawAlpha(&img1, 0, 0);
                        drawAlpha(&img2, 0, 0);
                        drawAlpha(&img3, 629, 132);
                        drawAlpha(&img3, 629, 198);
                        drawAlpha(&img3, 629, 274);
                        drawAlpha(&img4, 700, 500);
                        centerText("出发地",630,100,36,140,20);
                        centerText("目的地",630,172,30,140,20);
                        centerText("路程距离",630,239,40,140,20);
                        centerText("重选",633,345,28,147,20);
                        for(auto kv: map){
                            if (kv.second.type==3)
                            {
                                IMAGE img;
                                loadimage(&img, "../temp233.png",10,10);
                                drawAlpha(&img,kv.second.x-3,kv.second.y-3);}
                        }
                        drawE=false;
                        drawS=false;
                    }
                    IMAGE img;
                    loadimage(&img, "../temp233.png", 10, 10);
                    drawAlpha(&img, m.x - 3, m.y - 3);
                    if (!drawS&&!Isdraw) {
                        storageT.insertNode("start", m.x, m.y, 0);
                        std::string str;
                        str=std::to_string(m.x)+","+std::to_string(m.y);
                        const char* cstr = str.c_str();
                        centerText(cstr,629,132,37,140,10);
                        drawS=true;
                        Isdraw=true;
                    }
                    if (!drawE&&!Isdraw) {
                        storageT.insertNode("end", m.x, m.y, 0);
                        std::string str;
                        str=std::to_string(m.x)+","+std::to_string(m.y);
                        const char* cstr = str.c_str();
                        centerText(cstr,630,198,37,140,10);
                        drawE=true;
                        Isdraw=true;
                    }
                    if (drawE&&drawS&&Isdraw==true) {
                        drawWay();
                    }
                }
            }
            // 检测按钮点击
            if (m.x >= 632 && m.x <= 774 && m.y >= 136 && m.y <= 170) {
                if (drawE&&drawS) {
                    storageT.reClear();
                    storageT.generateTestData();
                    cleardevice();
                    drawAlpha(&img1, 0, 0);
                    drawAlpha(&img2, 0, 0);
                    drawAlpha(&img3, 629, 132);
                    drawAlpha(&img3, 629, 198);
                    drawAlpha(&img3, 629, 274);
                    drawAlpha(&img4, 700, 500);
                    centerText("出发地",630,100,36,140,20);
                    centerText("目的地",630,172,30,140,20);
                    centerText("路程距离",630,239,40,140,20);
                    centerText("重选",633,345,28,147,20);
                    for(auto kv: map){
                        if (kv.second.type==3)
                        {
                            IMAGE img;
                            loadimage(&img, "../temp233.png",10,10);
                            drawAlpha(&img,kv.second.x-3,kv.second.y-3);}
                    }
                    drawE=false;
                    drawS=false;
                }
                if (m.uMsg == WM_LBUTTONDOWN) {
                    std::cout << 1 << "\n";
                    char a[100];
                    InputBox(a, 20, "输入出发点名称", "出发点", nullptr,200,100);
                    std::cout <<a;
                    map = storageT.getNodes();
                   if (map.count(a)==1) {
                       if (map.find(a)->second.type==3) {
                           if (!map.count("start")==0)storageT.deleteNode("start");
                           storageT.insertNode("start",map.find(a)->second.x, map.find(a)->second.y, 0);
                           std::string str;
                           std::cout << map.find(a)->second.x << " " << map.find(a)->second.y << "\n";
                           str=std::to_string(map.find(a)->second.x)+","+std::to_string(map.find(a)->second.y);
                           const char* cstr = str.c_str();
                           centerText(cstr,629,132,37,140,10);
                           drawS=true;
                           if (drawE) {
                               drawWay();
                           }
                       }
                   }

                }
            }
            if (m.x >= 632 && m.x <= 774 && m.y >= 202 && m.y <= 237) {
                if (m.uMsg == WM_LBUTTONDOWN) {
                    if (drawE&&drawS) {
                        storageT.reClear();
                        storageT.generateTestData();
                        cleardevice();
                        drawAlpha(&img1, 0, 0);
                        drawAlpha(&img2, 0, 0);
                        drawAlpha(&img3, 629, 132);
                        drawAlpha(&img3, 629, 198);
                        drawAlpha(&img3, 629, 274);
                        drawAlpha(&img4, 700, 500);
                        centerText("出发地",630,100,36,140,20);
                        centerText("目的地",630,172,30,140,20);
                        centerText("路程距离",630,239,40,140,20);
                        centerText("重选",633,345,28,147,20);
                        for(auto kv: map){
                            if (kv.second.type==3)
                            {
                                IMAGE img;
                                loadimage(&img, "../temp233.png",10,10);
                                drawAlpha(&img,kv.second.x-3,kv.second.y-3);}
                        }
                        drawE=false;
                        drawS=false;
                    }
                    std::cout << 1 << "\n";
                    char a[100];
                    InputBox(a, 20, "输入目的地名称", "目的地", nullptr,200,100);
                    std::cout <<a;
                    map = storageT.getNodes();
                    if (map.count(a)==1) {
                        if (map.find(a)->second.type==3) {
                            if (!map.count("end")==0)storageT.deleteNode("end");
                            storageT.insertNode("end",map.find(a)->second.x, map.find(a)->second.y, 0);
                            std::string str;
                            std::cout << map.find(a)->second.x << " " << map.find(a)->second.y << "\n";
                            str=std::to_string(map.find(a)->second.x)+","+std::to_string(map.find(a)->second.y);
                            const char* cstr = str.c_str();
                            centerText(cstr,630,198,37,140,10);
                            drawE=true;
                            if (drawS) {
                                drawWay();
                            }
                        }
                    }

                }
            }
            if (m.x >= 632 && m.x <= 774 && m.y >= 345 && m.y <= 376) {
                if (m.uMsg == WM_LBUTTONDOWN) {

                    drawE=false;
                    drawS=false;
                    storageT.reClear();
                    storageT.generateTestData();

                    cleardevice();
                    drawAlpha(&img1, 0, 0);
                    drawAlpha(&img2, 0, 0);
                    drawAlpha(&img3, 629, 132);
                    drawAlpha(&img3, 629, 198);
                    drawAlpha(&img3, 629, 274);
                    drawAlpha(&img4, 700, 500);
                    centerText("出发地",630,100,36,140,20);
                    centerText("目的地",630,172,30,140,20);
                    centerText("路程距离",630,239,40,140,20);
                    centerText("重选",633,345,28,147,20);
                    for(auto kv: map){
                        if (kv.second.type==3)
                        {
                            IMAGE img;
                            loadimage(&img, "../temp233.png",10,10);
                            drawAlpha(&img,kv.second.x-3,kv.second.y-3);}
                    }
                }
            }
        }
    }

    // 绘制线段函数
    static void LINE(Node a, Node b, int SLEEP) {
        short x1 = a.x;
        short y1 = a.y;
        short x2;
        short y2;

        for (int i = 0; i <= 20; i++) {
            LINESTYLE Style;
            getlinestyle(&Style);
            Style.thickness = 3;
            setlinestyle(&Style);
            setlinecolor(RGB(71, 143, 221));
            x2 = a.x + (b.x - a.x) * i / 20;
            y2 = a.y + (b.y - a.y) * i / 20;
            line(a.x, a.y, x2, y2);
            x1 = x2;
            y1 = y2;

            Sleep(SLEEP);
        }
    }

    // 绘制带透明度的图像
    static void drawAlpha(IMAGE* picture, int picture_x, int picture_y) {
        DWORD *dst = GetImageBuffer();
        DWORD *draw = GetImageBuffer();
        DWORD *src = GetImageBuffer(picture);
        int picture_width = picture->getwidth();
        int picture_height = picture->getheight();
        int graphWidth = getwidth();
        int graphHeight = getheight();
        int dstX = 0;
        for (int iy = 0; iy < picture_height; iy++) {
            for (int ix = 0; ix < picture_width; ix++) {
                int srcX = ix + iy * picture_width;
                int sa = ((src[srcX] & 0xff000000) >> 24);
                int sr = ((src[srcX] & 0xff0000) >> 16);
                int sg = ((src[srcX] & 0xff00) >> 8);
                int sb = src[srcX] & 0xff;
                if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight) {
                    dstX = (ix + picture_x) + (iy + picture_y) * graphWidth;
                    int dr = ((dst[dstX] & 0xff0000) >> 16);
                    int dg = ((dst[dstX] & 0xff00) >> 8);
                    int db = dst[dstX] & 0xff;
                    draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)
                                 | ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)
                                 | (sb * sa / 255 + db * (255 - sa) / 255);
                }
            }
        }
    }

    // 绘制路径
    static void drawWay() {
        short numb = 1000;
        short numa = 1000;
        int tap;
        short tempx, tempy;
        std::string tempN;
        std::string p1, p2;
        std::unordered_map<std::string, Node> map = storageT.getNodes();
        std::unordered_map<std::string, std::unordered_map<std::string, double>> map1 = storageT.getAdjMatrix();

        // 查找与start节点最近的节点
        for (auto kv : map) {
            if (kv.first != "start") {
                if (kv.second.type!=3) {
                    short tempNum = sqrt(pow(kv.second.x - map.find("start")->second.x, 2) + pow(kv.second.y - map.find("start")->second.y, 2));
                    if (tempNum < numa) {
                        numa = tempNum;
                        p1 = kv.first;
                    }
                }

            }
        }

        // 查找与end节点最近的节点
        for (auto kv : map) {
            if (kv.first != "end") {
                if (kv.second.type!=3) {
                    double tempNum = sqrt(pow(kv.second.x - map.find("end")->second.x, 2) + pow(kv.second.y - map.find("end")->second.y, 2));
                    if (tempNum < numb) {
                        numb = tempNum;
                        p2 = kv.first;
                    }
                }

            }
        }

        // 在start和最近节点之间插入新节点
        for (auto kv : map1[p1]) {
            short tempNum = PointToSegDist(map.find("start")->second.x, map.find("start")->second.y, map.find(p1)->second.x, map.find(p1)->second.y, map.find(kv.first)->second.x, map.find(kv.first)->second.y);
            if (tempNum <= numa) {
                numa = tempNum;
                tempN = kv.first;
            }
        }

        tap = PointToSegStyle(map.find("start")->second.x, map.find("start")->second.y, map.find(p2)->second.x, map.find(p2)->second.y, map.find(tempN)->second.x, map.find(tempN)->second.y);
        if (tap == 0) {
            Node tempNode = PointToSegNode(map.find("start")->second.x, map.find("start")->second.y, map.find(p2)->second.x, map.find(p2)->second.y, map.find(tempN)->second.x, map.find(tempN)->second.y);
            tempx = tempNode.x;
            tempy = tempNode.y;
            storageT.insertNode("start1", tempx, tempy, tap);
            storageT.insertRoad("start", "start1");
            storageT.insertRoad("start1", p1);
            storageT.insertRoad(tempN, "start1");
            map = storageT.getNodes();
            map1 = storageT.getAdjMatrix();
        } else {
            storageT.insertRoad("start", p1);
            map = storageT.getNodes();
            map1 = storageT.getAdjMatrix();
        }

        // 在end和最近节点之间插入新节点
        for (auto kv : map1[p2]) {
            short tempNum = PointToSegDist(map.find("end")->second.x, map.find("end")->second.y, map.find(p2)->second.x, map.find(p2)->second.y, map.find(kv.first)->second.x, map.find(kv.first)->second.y);
            if (tempNum <= numb) {
                numb = tempNum;
                tempN = kv.first;
            }
        }
        tap = PointToSegStyle(map.find("end")->second.x, map.find("end")->second.y, map.find(p2)->second.x, map.find(p2)->second.y, map.find(tempN)->second.x, map.find(tempN)->second.y);
        if (tap == 0) {
            Node tempNode = PointToSegNode(map.find("end")->second.x, map.find("end")->second.y, map.find(p2)->second.x, map.find(p2)->second.y, map.find(tempN)->second.x, map.find(tempN)->second.y);
            tempx = tempNode.x;
            tempy = tempNode.y;
            storageT.insertNode("end1", tempx, tempy, tap);
            storageT.insertRoad("end1", "end");
            storageT.insertRoad(p2, "end1");
            storageT.insertRoad(tempN, "end1");
            map = storageT.getNodes();
            map1 = storageT.getAdjMatrix();
        } else {
            storageT.insertRoad(p2, "end");
            map = storageT.getNodes();
            map1 = storageT.getAdjMatrix();
        }

        // 绘制最短路径
        int res= navigation.findShortestPath("start", "end");
        std::vector<std::string> a = navigation.getShortestPath();
        for (int i = 0; i < a.size(); ++i) {
            if (i + 1 <= a.size() - 1) LINE(map.find(a[i])->second, map.find(a[i + 1])->second, 10);
            IMAGE img;
            loadimage(&img, "../temp233.png", 10, 10);
            drawAlpha(&img, map.find("start")->second.x - 3, map.find("start")->second.y - 3);
            drawAlpha(&img, map.find("end")->second.x - 3, map.find("end")->second.y - 3);
        }
        std::string str;
        str=std::to_string(res*2)+"m";
        const char* cstr = str.c_str();
        centerText(cstr,630,272,36,140,10);
    }

    // 计算点到线段的距离
    static double PointToSegDist(double x, double y, double x1, double y1, double x2, double y2) {
        double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
        if (cross <= 0) {
            return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        }
        double d2 = (x2 - x1) * (x2 - x2) + (y2 - y1) * (y2 - y1);
        if (cross >= d2) {
            return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
        }
        double r = cross / d2;  // 相似三角形原理求出c点的坐标
        double px = x1 + (x2 - x1) * r;
        double py = y1 + (y2 - y1) * r;
        return sqrt((x - px) * (x - px) + (py - y) * (py - y));
    }

    // 计算点到线段的垂足
    static Node PointToSegNode(double x, double y, double x1, double y1, double x2, double y2) {
        double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
        double d2 = (x2 - x1) * (x2 - x2) + (y2 - y1) * (y2 - y1);
        double r = cross / d2;  // 相似三角形原理求出c点的坐标
        double px = x1 + (x2 - x1) * r;
        double py = y1 + (y2 - y1) * r;
        Node a = {"aa", (short)px, (short)py, 0};
        return a;
    }

    // 判断点是否在线段上
    static int PointToSegStyle(double x, double y, double x1, double y1, double x2, double y2) {
        double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
        if (cross <= 0) {
            return 1;
        }
        double d2 = (x2 - x1) * (x2 - x2) + (y2 - y1) * (y2 - y1);
        if (cross >= d2) {
            return 1;
        }
        return 0;
    }

    // 文字居中显示函数
   static  void centerText(const char *str1, int rx, int ry, int rh, int rw,int size) {
        settextstyle(size, 0, "System");
        settextcolor(WHITE);
        int hSpace = (rw - textwidth(str1)) / 2;
        int vSpace = (rh - textheight(str1)) / 2;
        outtextxy(rx + hSpace, ry + vSpace, str1);
    }
};

#endif // MENU_H
