#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>

bool sqlconnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");  //MySQL驱动
        db.setDatabaseName("library");                         //数据库名
        db.setHostName("127.0.0.1");                            //数据库所在主机IP，此处数据库保存在本地
        db.setPort(3306);                                       //端口号
        db.setUserName("root");                                 //登陆用户名
        db.setPassword("111111");                             //登陆密码
        if(!db.open())
        {
            qDebug() << "open fail\n" << db.lastError().driverText() << "\n";
            return false;
        }
        qDebug()<<"success";
        return true;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(sqlconnection()==false)
        return 1;
    MainWindow w;
    w.show();
    w.mainW();
    return a.exec();
}
