#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "color.hpp"
#include "rect.hpp"

class Map
{
public:
    Map(Screen *screen = nullptr);
    ~Map();
    void draw(); // ���Ƶ�ͼ
    Screen *getScreen();
private:
    int _rows; // ��ͼ����
    int _cols; // ��ͼ����
    int _cell_size; // ��Ԫ���С
    int _gap_size; // ��Ԫ����
    Color _cell_color; // ��Ԫ����ɫ
    Rect *_cells; // ��ͼ��Ԫ������
    Screen *_screen; // ��Ļָ��
};

#endif