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

StorageModule storageT;
class Menu {
public:
    MOUSEMSG m{};

      Menu() {
        initgraph(800, 800,EW_SHOWCONSOLE | EW_DBLCLKS);
        setbkcolor(WHITE);
        cleardevice();
        IMAGE img1;
        IMAGE img2;
        int nodeNum=0;
        Node po[M];
        loadimage(&img1, "../UI.png",800,800);
        loadimage(&img2, "../guetMap.png",600,600);
        drawAlpha(&img1,0,0);
        drawAlpha(&img2, 0, 0);
        std::unordered_map <std::string, Node>map=storageT.getNodes();
    Node temp;
    // for(auto kv: map){
    //     IMAGE img;
    //     loadimage(&img, "../temp233.png",10,10);
    //     drawAlpha(&img,kv.second.x-3,kv.second.y-3);
    // }
   std::unordered_map<std::string, std::unordered_map<std::string, double>>map1=storageT.getAdjMatrix();
    // for(auto kv: map1){
    //
    //
    //
    //         auto ts=map.find(kv.first);
    //     for(auto kc:  map1[kv.first]) {
    //         auto te=map.find(kc.first);
    //         LINE(ts->second,te->second,0);
    //     }
    // }
    while (1) {
        m = GetMouseMsg();

        if (m.x >= 0 && m.x <= 600 && m.y >= 0 && m.y <= 600) {
            if (m.uMsg == WM_LBUTTONDOWN) {
                if (nodeNum==2) {
                    drawAlpha(&img2,0,0);
                 for (int i=0;i<=2;i++) {
                   storageT.deleteNode("start");
                     storageT.deleteNode("end");

                 }
                    nodeNum=0;
                }
                IMAGE img;
                loadimage(&img, "../temp233.png",10,10);
                drawAlpha(&img,m.x-3,m.y-3);
                nodeNum+=1;
               if (nodeNum==1)storageT.insertNode("start",m.x,m.y,0);
                if (nodeNum==2)storageT.insertNode("end",m.x,m.y,0);
                if (nodeNum>=2) {
                   drawWay();

                }
            }
        }
        if (m.uMsg == WM_LBUTTONDOWN)std::cout<<m.x<<" "<<m.y<<"\n";
        if (m.x >= 632 && m.x <=774  && m.y >= 136 && m.y <= 170) { if (m.uMsg == WM_LBUTTONDOWN)std::cout << 1<<"\n"; }
        if (m.x >= 632 && m.x <= 774 && m.y >= 202 && m.y <= 237){if (m.uMsg == WM_LBUTTONDOWN)std::cout << 2<<"\n";}
        if (m.x >= 632 && m.x <= 774 && m.y >= 279 && m.y <= 311){if (m.uMsg == WM_LBUTTONDOWN)std::cout << 3<<"\n";}
        if (m.x >= 632 && m.x <= 774 && m.y >= 345 && m.y <= 376){if (m.uMsg == WM_LBUTTONDOWN)std::cout << 4<<"\n";}

    }


}

   static  void LINE(Node a,Node b,int SLEEP)
{

    short x1=a.x;
    short y1=a.y;
    short x2;
    short y2;
    IMAGE img;
    loadimage(&img, "../temp233.png",10,10);
    for(int i=0;i<=20;i++)
    {
        LINESTYLE Style;
        getlinestyle(&Style);
        Style.thickness=3;
        setlinestyle(&Style);
        setlinecolor(RGB(71, 143, 221));
        x2=a.x+(b.x-a.x)*i/20;
        y2=a.y+(b.y-a.y)*i/20;
        line(a.x,a.y,x2,y2);
        x1=x2;
        y1=y2;
        drawAlpha(&img,a.x-3,a.y-3);
        drawAlpha(&img,b.x-3,b.y-3);
        Sleep(SLEEP);
    }
}
 static void drawAlpha(IMAGE* picture, int  picture_x, int picture_y){

    DWORD *dst = GetImageBuffer();
    DWORD *draw = GetImageBuffer();
    DWORD *src = GetImageBuffer(picture);
    int picture_width = picture->getwidth();
    int picture_height = picture->getheight();
    int graphWidth = getwidth();
    int graphHeight = getheight();
    int dstX = 0;
    for (int iy = 0; iy < picture_height; iy++)
    {
        for (int ix = 0; ix < picture_width; ix++)
        {
            int srcX = ix + iy * picture_width;
            int sa = ((src[srcX] & 0xff000000) >> 24);
            int sr = ((src[srcX] & 0xff0000) >> 16);
            int sg = ((src[srcX] & 0xff00) >> 8);
            int sb = src[srcX] & 0xff;
            if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
            {
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
    static void drawWay(){
    short numb=1000;
    short numa=1000;
    int tap;
    short tempx,tempy;
    std::string drawPo[100];
    std::string tempN;
    std::string p1,p2;
          std::unordered_map <std::string, Node>map=storageT.getNodes();
          std::unordered_map<std::string, std::unordered_map<std::string, double>>map1=storageT.getAdjMatrix();
    for(auto kv: map){
        if (kv.first!="start") {
            short tempNum;
            tempNum=sqrt(pow(kv.second.x -map.find("start")->second.x, 2) + pow(kv.second.y - map.find("start")->second.y, 2));
            if(tempNum<numa) {
                numa=tempNum;
                p1=kv.first;
            }
        }
    }

    for(auto kv: map){
         if (kv.first!="end") {
          double tempNum;
            tempNum=sqrt(pow(kv.second.x -map.find("end")->second.x, 2) + pow(kv.second.y - map.find("end")->second.y, 2));
             if(tempNum<numb) {
                numb=tempNum;
              p2=kv.first;
            }
         }
     }
          int temptag;
     for(auto kv: map1[p1]){
         short tempNum;

         tempNum=PointToSegDist(map.find("start")->second.x,map.find("start")->second.y,map.find(p1)->second.x,map.find(p1)->second.y,map.find(kv.first)->second.x,map.find(kv.first)->second.y);
         if(tempNum<=numa) {
             numa=tempNum;
             tempN=kv.first;
        }
     }

          tap=PointToSegStyle(map.find("start")->second.x,map.find("start")->second.y,map.find(p2)->second.x,map.find(p2)->second.y,map.find(tempN)->second.x,map.find(tempN)->second.y);
     if (tap==0) {
         Node tempNode=PointToSegNode(map.find("start")->second.x,map.find("start")->second.y,map.find(p2)->second.x,map.find(p2)->second.y,map.find(tempN)->second.x,map.find(tempN)->second.y);
         tempx=tempNode.x;
         tempy=tempNode.y;
         storageT.insertNode("start1",tempx,tempy,tap);
         storageT.insertRoad("start","start1");
         storageT.insertRoad("start1",p1);

    }

     else  storageT.insertRoad("start",p1);

     for(auto kv: map1[p2]){
         short tempNum;
         tempNum=PointToSegDist(map.find("end")->second.x,map.find("end")->second.y,map.find(p2)->second.x,map.find(p2)->second.y,map.find(kv.first)->second.x,map.find(kv.first)->second.y);
        if(tempNum<=numb) {
             numb=tempNum;
             tempN=kv.first;
         }
      }
     tap=PointToSegStyle(map.find("end")->second.x,map.find("end")->second.y,map.find(p2)->second.x,map.find(p2)->second.y,map.find(tempN)->second.x,map.find(tempN)->second.y);
     if (tap==0) {
         Node tempNode=PointToSegNode(map.find("end")->second.x,map.find("end")->second.y,map.find(p2)->second.x,map.find(p2)->second.y,map.find(tempN)->second.x,map.find(tempN)->second.y);
         tempx=tempNode.x;
         tempy=tempNode.y;
         storageT.insertNode("end1",tempx,tempy,tap);
         storageT.insertRoad("end1","end");
         storageT.insertRoad(p2,"end1");
      }
     else  storageT.insertRoad(p2,"end");
          NavigationModule go(storageT);
      std::cout <<  go.findShortestPath("start","end",drawPo);;

      for (int i=0;i<=99;i++) {
       if (i>=1) {
           if (drawPo[i]!="") {
               LINE(storageT.getNodes().find(drawPo[i-1])->second,storageT.getNodes().find(drawPo[i])->second,10);
           }
       }


      }



}

   static  double PointToSegDist(double x, double y, double x1, double y1, double x2, double y2)
      {
          double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
          if (cross <= 0) {
              return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
          }
          double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
          if (cross >= d2) {
              return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
          }
          double r = cross / d2;  //相似三角形原理求出c点的坐标
          double px = x1 + (x2 - x1) * r;
          double py = y1 + (y2 - y1) * r;
          return sqrt((x - px) * (x - px) + (py - y) * (py - y));
      }
    static  Node PointToSegNode(double x, double y, double x1, double y1, double x2, double y2)
      {
          double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
          double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
          double r = cross / d2;  //相似三角形原理求出c点的坐标
          double px = x1 + (x2 - x1) * r;
          double py = y1 + (y2 - y1) * r;
          Node a={"aa",(short)px,(short)py,0};
          return a;
      }
    static  int PointToSegStyle(double x, double y, double x1, double y1, double x2, double y2)
      {
          double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
          if (cross <= 0) {
              return 1;
          }
          double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
          if (cross >= d2) {
              return 1;
          }
          return 0;
      }
};


#endif //MENU_H
