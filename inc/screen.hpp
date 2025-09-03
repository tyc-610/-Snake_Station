#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "point.hpp"
#include "color.hpp"

class Screen
{
public:
    void init();
    void _close();
    void drawPoint(int x, int y,Color color);
    void drawPoint(const Point& pos, const Color& color);
    void clean();    
    Screen();
    ~Screen();

private:
    const char* _name;
    int _w;
    int _h;
    int _bpp; // 位深
    int _fd;
    int* _addr;
    int pixel_size; // 像素点大小

};

#endif