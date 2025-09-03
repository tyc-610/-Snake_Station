#include "../inc/bitmap.hpp"
#include "../inc/color.hpp"
#include "../inc/point.hpp"

#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <iostream>
using namespace std;

Bitmap::Bitmap(std::string name) : _name(name), _fd(-1)
{
    //1.拼接路径
    string bmp_path = "./bmp/" + name;
    this->_name = bmp_path;


    // 打开位图文件
    this->_fd = open(bmp_path.c_str(), O_RDWR);
    if(this->_fd < 0)
    {
        perror("open bmp file error");
        return;
    }

}
Bitmap::~Bitmap()
{
    //5. 关闭文件
    close(this->_fd);
}

void Bitmap::setName(string name)
{
    //1.拼接路径
    string bmp_path = "./bmp/" + name;
    this->_name = bmp_path;

    // 打开位图文件
    this->_fd = open(bmp_path.c_str(), O_RDWR);
    if(this->_fd < 0)
    {
        perror("open bmp file error");
        return;
    }
}



void Bitmap::draw(Screen& s)
{
    

    //2. 解析位图宽度高度色深
    int width;
    lseek(this->_fd, 0x12 , SEEK_SET);
    int ret = read(this->_fd, &width, 4);
    if(ret < 0)
    {
        perror("read width error");
        return;
    }

    int height;
    lseek(this->_fd, 0x16 , SEEK_SET);
    ret = read(this->_fd, &height, 4);
    if(ret < 0)
    {
        perror("read height error");
        return;
    }

    short depth;
    lseek(this->_fd, 0x1c , SEEK_SET);
    ret = read(this->_fd, &depth, 2);
    if(ret < 0)
    {
        perror("read depth error");
        return;
    }

    //3.计算像素数组大小 
    int laizi = 0;
    int line_bytes = abs(width) * depth / 8;//一行有效字节数
    if(line_bytes % 4 != 0)
    {
        laizi = 4 - line_bytes % 4;
    }

    //一行实际字节数 * 位图高度 = 像素数组大小
    int arr_size = (line_bytes + laizi) * abs(height);

    //4.像素数组的解析
    //4.1开辟一个像素数组大小的空间,用于存储像素数组
    unsigned char * p = (unsigned char *)malloc(arr_size);

    //4.2 将像素数组的内容,读取到p中
    lseek(this->_fd, 0x54 , SEEK_SET);
    ret = read(this->_fd , p ,arr_size);
    if(ret < 0)
    {
        perror("read pixel array error");
        return;
    }

    //5.解析颜色值,并在对应的坐标画点
    Color color;
    Point pos;
    int i = 0;
    for(pos.setY(0); pos.y() < abs(height); pos.setY(pos.y() + 1))
    {
        for(pos.setX(0); pos.x() < abs(width); pos.setX(pos.x() + 1))
        {
            //计算颜色值的偏移
            color.setB(*(p + i));
            i++;
            color.setG(*(p + i));
            i++;
            color.setR(*(p + i));
            i++;
            if(depth == 32)
            {
                color.setA(*(p + i));
                i++;
            }
            else
            {
                color.setA(0); // 如果是24位深度，透明度为0
            }
            // 修正y坐标映射，保证图片方向正确
            s.drawPoint(
                pos.x(),
                (height > 0 ? (abs(height) - pos.y() - 1) : pos.y()),
                color
            );
            //跳过赖子
            i += laizi;
        }
    }
    //6.释放像素数组空间
    free(p);


}











