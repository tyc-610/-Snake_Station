#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "color.hpp"
#include "rect.hpp"

class Map
{
public:
    Map(Screen *screen = nullptr);
    ~Map();
    void draw(); // 绘制地图
    Screen *getScreen();
private:
    int _rows; // 地图行数
    int _cols; // 地图列数
    int _cell_size; // 单元格大小
    int _gap_size; // 单元格间距
    Color _cell_color; // 单元格颜色
    Rect *_cells; // 地图单元格数组
    Screen *_screen; // 屏幕指针
};

#endif