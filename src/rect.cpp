#include <iostream>
using namespace std;

#include "screen.hpp"
#include "point.hpp"
#include "rect.hpp"

// ���캯��
Rect::Rect(int x, int y, int w, int h, Color color):_p(x,y),_w(w),_h(h),_color(color){}

void Rect::draw_rect(Screen &s)
{

    // ������
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

    // ������
    for (int i = x; i < x + w; i++)
    {
        for (int j = y; j < y + h; j++)
        {
            s.drawPoint(i, j, _color);
        }
    }
}

// �ƶ�����λ��
void Rect::move(int x, int y)
{
    _p.move(x, y);
}

// �������δ�С
void Rect::resize(int w, int h)
{
    _w = w;
    _h = h;
}

// ���þ�����ɫ
void Rect::setColor(const Color& color)
{
    // ������ɫ
    _color = color;
}



