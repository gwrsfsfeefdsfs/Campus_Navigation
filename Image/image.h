//
// Created by 湖东行不足 on 2024/7/8.
//

#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include <graphics.h>

class Tooltip {
public:
    Tooltip() : visible(false), buffer(nullptr) {}

    ~Tooltip() {
        if (buffer) {
            delete buffer;
        }
    }

    void show(int x, int y, const std::string& text, const std::string& imagePath) {
        if (visible) return;
        visible = true;

        this->x = x;
        this->y = y;
        this->width = 200;
        this->height = 100;

        buffer = new IMAGE;
        getimage(buffer, x, y, x + width, y + height);

        //背景
        setfillcolor(WHITE);
        solidrectangle(x, y, x + width, y + height);

        //图片
        IMAGE img;
        loadimage(&img, imagePath.c_str(), 70, 70);
        putimage(x + 10, y + 10, &img);

        //文字
        settextcolor(BLACK);
        outtextxy(x + 150, y + 70, text.c_str());
    }

    void hide() {
        if (!visible) return;
        visible = false;

        // Restore the saved background image
        putimage(x, y, buffer);

        delete buffer;
        buffer = nullptr;
    }

private:
    bool visible;
    int x, y, width, height;
    IMAGE* buffer;
};

#endif //IMAGE_H
