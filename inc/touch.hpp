#ifndef TOUCH_HPP
#define TOUCH_HPP

#include "point.hpp"

class TouchEvent
{
public:
    TouchEvent(); // /dev/input/event0
    ~TouchEvent();

    // 方向，移动方向
    enum move_dir
    {
        MOV_UP = 0,
        MOV_DOWN,
        MOV_LEFT,
        MOV_RIGHT,
        MOV_ERR = 1024
    };

    // 获取当前位置
    Point getPos();

    // 获取移动方向
    void getMoveDir();

    // 设置方向
    void setDir(move_dir dir);

    // 获取方向
    enum move_dir dir();

private:

    // 触摸屏文件描述符
    int _fd;

    move_dir _dir;
};

#endif