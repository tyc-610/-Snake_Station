#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include <deque>

#include "rect.hpp"
#include "map.hpp"
#include "touch.hpp"

class Snake
{
private:
    std::deque<Rect> _snacks; // �ߵ�����
    Map *_map;                // ��ͼ
    int speed;                // �ߵ��ٶ�
    TouchEvent *_te;          // �������¼�,������ȡ����
public:
    Snake(Map *map, TouchEvent *te);
    ~Snake();

    // ��ʼ��
    void init();

    // �ƶ�
    void move();

    // ��ʳ��
    void eat();

    // ����
    void draw();

    // ����
    bool isDead();

};

#endif