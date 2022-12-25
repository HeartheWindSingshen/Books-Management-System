#include "radio2.h"
#include "radio1.h"            //包含头文件radio1的原因是该类声明了全局变量radio  属于全局变量操作的一部分
#include <QDebug>
radio2::radio2(QObject *parent) : QObject(parent)
{

}
void radio2::radio22()
{
    radio=false;
}
