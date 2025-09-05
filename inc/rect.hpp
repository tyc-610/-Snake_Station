#ifndef __RECT_HPP__
#define __RECT_HPP__

#include "point.hpp"
#include "screen.hpp"
#include "color.hpp"

class Rect
{
private:
    //首坐标点，就是矩形起始的那个点
    Point _p;
    int _w;
    int _h;
    Color _color;
public:
    Rect(int x=0, int y=0, int w=0, int h=0, Color color=Color(255,255,255,255));
    void draw_rect(Screen &s);
    void draw_rect(int x, int y, int w, int h, int color, Screen &s);
    void move(int x, int y);
    void resize(int w, int h);
    void setColor(const Color& color);

};


#endif