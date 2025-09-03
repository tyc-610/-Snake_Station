#include <iostream>

#include "color.hpp"

void Color::setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->_r = r;
    this->_g = g;
    this->_b = b;
    this->_a = a;

}

void Color::setR(unsigned char r)
{
    this->_r = r;
}

void Color::setG(unsigned char g)
{
    this->_g = g;
}

void Color::setB(unsigned char b)
{
    this->_b = b;
}

void Color::setA(unsigned char a)
{
    this->_a = a;
}



unsigned int Color::toInt() const
{
    return ((_a << 24)|(_r << 16)|(_g << 8)|_b);


}

Color::Color(): _r(0), _g(0), _b(0), _a(0){}


Color::Color(unsigned char r , unsigned char g , unsigned char b, unsigned char a): _r(r), _g(g), _b(b), _a(a){}