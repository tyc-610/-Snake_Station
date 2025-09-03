#ifndef __POINT_HPP__
#define __POINT_HPP__

// Point类的声明
class Point
{
public:
    // 设置和获取X坐标
    void setX(int x); 
    int x() const;

    // 设置和获取Y坐标
    void setY(int y);
    int y() const;

    // 设置X和Y坐标
    void move(int x, int y);

    // 构造函数
    Point();
    Point(int x , int y);
    
private:
    int _x;
    int _y;
};


#endif