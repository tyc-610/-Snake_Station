#ifndef TOUCH_HPP
#define TOUCH_HPP

#include "point.hpp"

class TouchEvent
{
public:
    TouchEvent(); // /dev/input/event0
    ~TouchEvent();

     //????,????
    enum move_dir
    {
        MOV_UP = 0,
        MOV_DOWN,
        MOV_LEFT,
        MOV_RIGHT,
        MOV_ERR = 1024
    };

    //????????
    Point getPos();

    //?????????????
    void getMoveDir();

    //??????
    void setDir(move_dir dir);

    //??????
    enum move_dir dir();

   

private:

    //´¥ÃþÆÁÎÄ¼þÃèÊö·û
    int _fd;

    move_dir _dir;
};

#endif