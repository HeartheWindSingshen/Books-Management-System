#include "radio1.h"
bool radio;                             //声明radio是全局变量的一部分操作
bool flag;                              //flag
QString readerid;
QString administratorid;
radio1::radio1(QObject *parent) : QObject(parent)
{

}

void radio1::radio11()
{
    radio=true;
}
