#include "snake.hpp"

Snake::Snake(Map *map, TouchEvent *te):_map(map),_te(te)
{
    init();
}

Snake::~Snake()
{
}

void Snake::init()
{
    // 初始化蛇
    this->_snacks.push_back(Rect(75,0, 15, 15, Color(0, 255, 0, 255)));
    this->_snacks.push_back(Rect(60,0, 15, 15, Color(255, 0, 0, 255)));
    this->_snacks.push_back(Rect(45,0, 15, 15, Color(255, 0, 0, 255)));
    this->speed = 10;
}

void Snake::draw()
{
    for(auto &e : this->_snacks)
    {
        e.draw_rect(*this->_map->getScreen());
    }
}

void Snake::move()
{
    //1. 获取当前方向
}



