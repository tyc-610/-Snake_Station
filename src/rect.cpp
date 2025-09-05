#include <iostream>
using namespace std;

#include "screen.hpp"
#include "point.hpp"
#include "rect.hpp"

// 构造函数
Rect::Rect(int x, int y, int w, int h, Color color):_p(x,y),_w(w),_h(h),_color(color){}

void Rect::draw_rect(Screen &s)
{

    // 画矩形
    for (int i = _p.x(); i < _p.x() + _w; i++)
    {
        for (int j = _p.y(); j < _p.y() + _h; j++)
        {
            s.drawPoint(i, j, _color);
        }
    }
}

void Rect::draw_rect(int x, int y, int w, int h, int color, Screen &s)
{

    // 画矩形
    for (int i = x; i < x + w; i++)
    {
        for (int j = y; j < y + h; j++)
        {
            s.drawPoint(i, j, _color);
        }
    }
}

// 移动矩形位置
void Rect::move(int x, int y)
{
    _p.move(x, y);
}

// 调整矩形大小
void Rect::resize(int w, int h)
{
    _w = w;
    _h = h;
}

// 设置矩形颜色
void Rect::setColor(const Color& color)
{
    // 设置颜色
    _color = color;
}



