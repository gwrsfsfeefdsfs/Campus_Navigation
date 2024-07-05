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

#include <map>


class Menu {
    MOUSEMSG m{};
public:  Menu(StorageModule storage) {
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
        std::unordered_map <std::string, Node>map=storage.getNodes();
    Node temp;
    for(auto kv: map){
        IMAGE img;
        loadimage(&img, "../temp233.png",10,10);
        drawAlpha(&img,kv.second.x-3,kv.second.y-3);
    }
   std::unordered_map<std::string, std::unordered_map<std::string, double>>map1=storage.getAdjMatrix();

    while (1) {
        m = GetMouseMsg();

        if (m.x >= 0 && m.x <= 600 && m.y >= 0 && m.y <= 600) {
            if (m.uMsg == WM_LBUTTONDOWN) {
                if (nodeNum==10) {
                    drawAlpha(&img2,0,0);
                 for (int i=0;i<=9;i++) {
                     po[i].x=0;
                     po[i].y=0;

                 }
                    nodeNum=0;
                }
                IMAGE img;
                loadimage(&img, "../temp233.png",10,10);
                drawAlpha(&img,m.x-3,m.y-3);
                nodeNum+=1;
                po[nodeNum].x=m.x;
                po[nodeNum].y=m.y;
                if (nodeNum>=2) {
                    LINE(po[nodeNum-1],po[nodeNum],10);

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
    static void drawWay(Node a,Node b)
    {








}
    void LINE(Node a,Node b,int SLEEP)
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
    static void drawAlpha(IMAGE* picture, int  picture_x, int picture_y)
{

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
};

#endif //MENU_H
