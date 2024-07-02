//
// Created by Admin on 24-7-2.
//

#ifndef MENU_H
#define MENU_H
class Menu {
    MOUSEMSG m{};
public:  Menu() {
        initgraph(800, 800,EW_SHOWCONSOLE | EW_DBLCLKS);	// 创建绘图窗口，大小为 640x480 像素
        setbkcolor(WHITE);
        cleardevice();
        IMAGE img1;
        IMAGE img2;
        loadimage(&img1, "../UI.png",800,800);
        loadimage(&img2, "../guetMap.png",600,600);
        drawAlpha(&img1,0,0);
        drawAlpha(&img2,0,0);
    while (1) {
        m = GetMouseMsg();
        if (m.x >= 0 && m.x <= 600 && m.y >= 0 && m.y <= 600) {
            if (m.uMsg == WM_LBUTTONDOWN) {

                IMAGE img;
                loadimage(&img, "../temp233.png",10,10);
                drawAlpha(&img,m.x,m.y);

            }
        }

    }
        _getch();
        closegraph();

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
