#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>



#include <iostream>
using namespace std;


#include "../inc/screen.hpp"

void Screen::init()
{
    // 打开
    _fd = open("/dev/fb0" , O_RDWR);
    if(_fd == -1)
    {
        cout<<"open fb error"<<endl;
        return ;
    }

    //获取屏幕的信息
	struct fb_var_screeninfo fb_info;
   	int  r=  ioctl( _fd, FBIOGET_VSCREENINFO ,  &fb_info );
   	if(r == -1)
   	{
		cout<<"ioctl error"<<endl;
		return ;
   	}

   	//解析fd_info里面信息
   	_w = fb_info.xres; //屏幕宽度
   	_h = fb_info.yres; //屏幕高度
   	pixel_size = fb_info.bits_per_pixel / 8; //像素点大小

    // 映射
    _addr = (int*)mmap(NULL , _w*_h*pixel_size, PROT_READ | PROT_WRITE, MAP_SHARED, _fd, 0);
    if(_addr == MAP_FAILED)
    {
        cout<<"mmap error"<<endl;
        return ;
    }

}

void Screen::_close()
{
    // 解除
    munmap(_addr, _w*_h*pixel_size);
    // 关闭
    close(_fd);
}

void Screen::drawPoint(int x, int y, Color color)
{
    // 画点
    if(x >= 0 && x < _w && y >= 0 && y < _h)
    {
        int* p = _addr + y * _w + x;
        *p = color.toInt();
    }
}
void Screen::drawPoint(const Point &pos, const Color& color)
{
    drawPoint(pos.x(), pos.y(), color);
}
void Screen::clean()
{
    for(int i = 0; i < _w; i++)
    {
        for(int j = 0; j < _h; j++)
        {
            drawPoint(i, j, Color(0,0,0,0));
        }
    }
}

// 构造函数
Screen::Screen()
{
    //初始化屏幕
    init();
    //清理屏幕
    clean();

}

// 析构函数
Screen::~Screen()
{
    //关闭屏幕
    _close();
}







