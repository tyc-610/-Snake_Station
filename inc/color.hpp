#ifndef __COLOR_HPP__
#define __COLOR_HPP__


class Color
{
public:
    void setColor(unsigned char r, unsigned char g, unsigned char b,unsigned char a);
    unsigned int toInt() const;
    void setR(unsigned char r);
    void setG(unsigned char g);
    void setB(unsigned char b);
    void setA(unsigned char a);



    Color();
    Color(unsigned char r , unsigned char g , unsigned char b,unsigned char a);

private:
    unsigned char _r;
    unsigned char _g;
    unsigned char _b;
    unsigned char _a;
};

#endif