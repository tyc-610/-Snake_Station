#ifndef __RECT_HPP__
#define __RECT_HPP__

#include "point.hpp"
#include "screen.hpp"
#include "color.hpp"

class Rect
{
private:
    //������㣬���Ǿ�����ʼ���Ǹ���
    Point _p;
    int _w;
    int _h;
    Color _color;
public:
    void draw_rect(Screen &s);
    void draw_rect(int x, int y, int w, int h, int color, Screen &s);
    void move(int x, int y);
    void resize(int w, int h);
    void setColor(const Color& color);

};


#endif