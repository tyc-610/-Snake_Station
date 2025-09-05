#include "../inc/map.hpp"


Map::Map(Screen *screen):_screen(screen), _rows(30), _cols(40), _cell_size(15), _gap_size(1), _cell_color(200,200,200,255)
{
    _cells = new Rect[_rows * _cols];
    for(int i = 0; i < _rows; i++)
    {
        for(int j = 0; j < _cols; j++)
        {
            _cells[i * _cols + j].move(i * (_cell_size + _gap_size), j * (_cell_size + _gap_size));
            _cells[i * _cols + j].resize(_cell_size, _cell_size);
            _cells[i * _cols + j].setColor(_cell_color);
        }
    }
}

Map::~Map()
{
    delete [] _cells;
}   

// 绘制地图
void Map::draw()
{
    for(int i = 0; i < _rows; i++)
    {
        for(int j = 0; j < _cols; j++)
        {
            _cells[i * _cols + j].draw_rect(*_screen);
        }
    }
}

// 获取屏幕指针
Screen* Map::getScreen()
{
    return this->_screen;
}


