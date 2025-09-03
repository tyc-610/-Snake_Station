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
    //1.ƴ��·��
    string bmp_path = "./bmp/" + name;
    this->_name = bmp_path;


    // ��λͼ�ļ�
    this->_fd = open(bmp_path.c_str(), O_RDWR);
    if(this->_fd < 0)
    {
        perror("open bmp file error");
        return;
    }

}
Bitmap::~Bitmap()
{
    //5. �ر��ļ�
    close(this->_fd);
}

void Bitmap::setName(string name)
{
    //1.ƴ��·��
    string bmp_path = "./bmp/" + name;
    this->_name = bmp_path;

    // ��λͼ�ļ�
    this->_fd = open(bmp_path.c_str(), O_RDWR);
    if(this->_fd < 0)
    {
        perror("open bmp file error");
        return;
    }
}



void Bitmap::draw(Screen& s)
{
    

    //2. ����λͼ��ȸ߶�ɫ��
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

    //3.�������������С 
    int laizi = 0;
    int line_bytes = abs(width) * depth / 8;//һ����Ч�ֽ���
    if(line_bytes % 4 != 0)
    {
        laizi = 4 - line_bytes % 4;
    }

    //һ��ʵ���ֽ��� * λͼ�߶� = ���������С
    int arr_size = (line_bytes + laizi) * abs(height);

    //4.��������Ľ���
    //4.1����һ�����������С�Ŀռ�,���ڴ洢��������
    unsigned char * p = (unsigned char *)malloc(arr_size);

    //4.2 ���������������,��ȡ��p��
    lseek(this->_fd, 0x54 , SEEK_SET);
    ret = read(this->_fd , p ,arr_size);
    if(ret < 0)
    {
        perror("read pixel array error");
        return;
    }

    //5.������ɫֵ,���ڶ�Ӧ�����껭��
    Color color;
    Point pos;
    int i = 0;
    for(pos.setY(0); pos.y() < abs(height); pos.setY(pos.y() + 1))
    {
        for(pos.setX(0); pos.x() < abs(width); pos.setX(pos.x() + 1))
        {
            //������ɫֵ��ƫ��
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
                color.setA(0); // �����24λ��ȣ�͸����Ϊ0
            }
            // ����y����ӳ�䣬��֤ͼƬ������ȷ
            s.drawPoint(
                pos.x(),
                (height > 0 ? (abs(height) - pos.y() - 1) : pos.y()),
                color
            );
            //��������
            i += laizi;
        }
    }
    //6.�ͷ���������ռ�
    free(p);


}











