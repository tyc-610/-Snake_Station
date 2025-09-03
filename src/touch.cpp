#include "../inc/touch.hpp"
#include "../inc/point.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <stdlib.h>
#include <iostream>


TouchEvent::TouchEvent()
{
    this->_fd = open("/dev/input/event0",O_RDWR);
    if (this->_fd < 0)
    {
        throw("open dev input event0 error");
    }
    
}

TouchEvent::~TouchEvent()
{
    close(this->_fd);
}

Point TouchEvent::getPos()
{
    //1.定义一个结构体变量
    struct input_event ts;
    //定义一个点
    Point pos;


    //2.不断的获取点的坐标，直到获取到为止
    int x = -1, y = -1;
    while(1)
    {
        int r = read(this->_fd, &ts , sizeof(ts));
        if(r < 0)
        {
            throw("read struct input_event error");
        }

        //3.解析输入信息 
        if(ts.type == EV_ABS && ts.code == ABS_X)
        {
            x = ts.value * 800 / 1024;
        }
        if(ts.type == EV_ABS && ts.code == ABS_Y)
        {
            y = ts.value * 480 / 600;
        }
        if(ts.type == EV_SYN && ts.code == SYN_REPORT)
        {
            if(x >= 0 && y >= 0)
            {
                pos.setX(x);
                pos.setY(y);
                return pos;
            }

        }

    }
}

void TouchEvent::getMoveDir()
{
    //1.定义一个结构体变量
    struct input_event ts;

    //2.定义两个点 , 分别用来记录起始点和终点
    Point p1;
    Point p2;

    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;


    //2.不断获取起始点和终点的下标
    while(1)
    {
        
        int r = read(this->_fd, &ts, sizeof(ts));
        if(r < 0)
        {
            throw("read struct input_event error");
        }

        if(ts.type == EV_ABS && ts.code == ABS_X)
        {
            if(x1 < 0)
            {
                x1 = ts.value;
            }
            x2 = ts.value;
        }
        if(ts.type == EV_ABS && ts.code == ABS_Y)
        {
            if(y1 < 0)
            {
                y1 = ts.value;
            }
            y2 = ts.value;
        }

        //同步
        if(ts.type == EV_SYN && ts.code == SYN_REPORT)
        {
            if(x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0)
            {
                p1.setX(x1);
                p1.setY(y1);
                p2.setX(x2);
                p2.setY(y2);
        
            }
        }

        //手指离开屏幕,计算滑动方向
        if(ts.type == EV_KEY && ts.code == BTN_TOUCH && ts.value == 0)
        {
            int det_x = abs(p1.x() - p2.x());
            int det_y = abs(p1.y() - p2.y());

            if(det_x > det_y)
            {
                //左右滑动
                if(p1.x() > p2.x())
                {
                    this->setDir(MOV_LEFT);
                }
                else
                {
                    this->setDir(MOV_RIGHT);
                }

            }
            else
            {
                //上下滑动
                if(p1.y() > p2.y())
                {
                    this->setDir(MOV_UP);
                }
                else
                {
                    this->setDir(MOV_DOWN);
                }

            }
            break;

        }

    }

}






void TouchEvent::setDir(enum move_dir dir)
{
    this->_dir = dir;
}

TouchEvent::move_dir TouchEvent::dir() { return _dir; }

