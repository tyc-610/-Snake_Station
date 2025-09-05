#ifndef TOUCH_HPP
#define TOUCH_HPP

#include "point.hpp"

class TouchEvent
{
public:
    TouchEvent(); // /dev/input/event0
    ~TouchEvent();

    // �����ƶ�����
    enum move_dir
    {
        MOV_UP = 0,
        MOV_DOWN,
        MOV_LEFT,
        MOV_RIGHT,
        MOV_ERR = 1024
    };

    // ��ȡ��ǰλ��
    Point getPos();

    // ��ȡ�ƶ�����
    void getMoveDir();

    // ���÷���
    void setDir(move_dir dir);

    // ��ȡ����
    enum move_dir dir();

private:

    // �������ļ�������
    int _fd;

    move_dir _dir;
};

#endif