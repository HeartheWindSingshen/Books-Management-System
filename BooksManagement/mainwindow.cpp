#include "mainwindow.h"                                 //主界面
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include "adlogin.h"
#include "adregister.h"
#include "relogin.h"
#include "reregister.h"
#include <QSqlQuery>
#include <radio1.h>                  //包含头文件radio1的原因是该类声明了全局变量radio  属于全局变量操作的一部分
#include <radio2.h>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mainW()
{
     ui->radioButton->setChecked(true);  //默认选中管理员
     radio=true;
    //判断是选的是管理员还是读者                        //全局变量radio的值是确定自己选的是管理员还是读者
     radio1* r1=new radio1;
     radio2* r2=new radio2;
    connect(ui->radioButton,&QPushButton::clicked,r1,&radio1::radio11);
    //两个connect都是关于radio button的选择的
    connect(ui->radioButton_2,&QPushButton::clicked,r2,&radio2::radio22);

    adlogin*adlog=new adlogin;
    adregister*adreg=new adregister;
    relogin*relog=new relogin;
    reregister*rereg=new reregister;

 //不要冲撞全局变量   bool flag = false;      //登陆成功标志
       flag=false;
//    QString name = ui->lineEdit->text().trimmed();                 //用户名
//    QString password = ui->lineEdit_2->text().trimmed();              //密码
        connect(ui->btn2,&QPushButton::clicked,[=](){         //注册按钮
            if(radio==true)
            {
//               this->hide();
               adreg->show();
            }
            else
            {
//                this->hide();
                rereg->show();
            }
        });
        connect(ui->btn1,&QPushButton::clicked,[=](){         //登录按钮
            QString name = ui->lineEdit->text().trimmed();                 //用户名
            QString password = ui->lineEdit_2->text().trimmed();              //密码
            if(radio==true)
            {
                if(name.isEmpty()||password.isEmpty())
                    QMessageBox::information(this,"提示","请输入用户名或者密码");
                else
                {
                    QSqlQuery query;
                    query.exec("select * from administrator");  //查询Administer表
                    while(query.next())
                    {
                        if(name == query.value(0).toString() && password == query.value(1).toString())   //用户名、密码匹配
                        {
                            flagchange();
                            administratorid=query.value(0).toString();
//                            this->hide();
                            adlog->show();
                        }
                    }
                    if(!flag)
                     QMessageBox::information(this,"提示","用户名或密码错误！");
                }
            }
            else
            {
                if(name.isEmpty()||password.isEmpty())
                    QMessageBox::information(this,"提示","请输入用户名或者密码");
                else
                {
                    QSqlQuery query;
                    query.exec("select * from reader");  //查询reader表
                    while(query.next())
                    {
                        if(name == query.value(0).toString() && password == query.value(4).toString())   //用户名、密码匹配
                        {
                            flagchange();
                            readerid=query.value(0).toString();
//                            this->hide();
                            relog->show();

                        }
                    }
                    if(!flag)
                     QMessageBox::information(this,"提示","用户名或密码错误！");
                }
            }
        });
    connect(ui->btn3,&QPushButton::clicked,[=](){       //退出按钮功能
      this->close();
    });
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/picture/sfji.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
void MainWindow::flagchange()
{
    flag=true;
}

