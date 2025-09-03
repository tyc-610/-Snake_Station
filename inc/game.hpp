#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "screen.hpp"
#include "touch.hpp"
#include "bitmap.hpp"
#include "point.hpp"
#include "map.hpp"

#include <iostream>
using namespace std;

class Game
{
public:
    Game();
    ~Game();
    void run();
private:
    Screen _s;
    TouchEvent _te;
    Bitmap _bmp;
    Point _pos;
    Map *_map;
};


#endif