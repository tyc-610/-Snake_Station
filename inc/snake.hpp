#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include <deque>

#include "rect.hpp"
#include "map.hpp"
#include "touch.hpp"

class Snake
{
private:
    std::deque<Rect> _snacks; // 蛇的身体
    Map *_map;                // 地图
    int speed;                // 蛇的速度
    TouchEvent *_te;          // 触摸屏事件,用来获取方向
public:
    Snake(Map *map, TouchEvent *te);
    ~Snake();

    // 初始化
    void init();

    // 移动
    void move();

    // 吃食物
    void eat();

    // 绘制
    void draw();

    // 死亡
    bool isDead();

};

#endif