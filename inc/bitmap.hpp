#ifndef BITMAP_HPP
#define BITMAP_HPP

#include "screen.hpp"
#include <string>
using namespace std;

class Bitmap
{
public:
    Bitmap(std::string name);
    ~Bitmap();
    void draw(Screen& s);
    void setName(string name);
private:
    string _name;
    int _fd;
    // ...
};


#endif