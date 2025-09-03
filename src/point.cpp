#include "../inc/point.hpp"
// 设置和获取X坐标
void Point::setX(int x)
{
    _x = x;
}

int Point::x() const
{
    return _x;
}


// 设置和获取Y坐标
void Point::setY(int y)
{
    _y = y;
}

int Point::y() const
{
    return _y;
}


// 设置X和Y坐标
void Point::move(int x, int y)
{
    _x = x;
    _y = y;
}


// 构造函数
Point::Point():_x(0), _y(0){}

Point::Point(int x , int y):_x(x), _y(y){}
