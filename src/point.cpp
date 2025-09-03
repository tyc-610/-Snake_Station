#include "../inc/point.hpp"
// ���úͻ�ȡX����
void Point::setX(int x)
{
    _x = x;
}

int Point::x() const
{
    return _x;
}


// ���úͻ�ȡY����
void Point::setY(int y)
{
    _y = y;
}

int Point::y() const
{
    return _y;
}


// ����X��Y����
void Point::move(int x, int y)
{
    _x = x;
    _y = y;
}


// ���캯��
Point::Point():_x(0), _y(0){}

Point::Point(int x , int y):_x(x), _y(y){}
