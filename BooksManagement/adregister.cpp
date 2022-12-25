#include "adregister.h"                                                  //管理员注册界面
#include "ui_adregister.h"
#include <QPainter>
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
adregister::adregister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adregister)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员注册界面");
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->close();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        QString name = ui->lineEdit->text().trimmed();                 //用户名
        QString password = ui->lineEdit_2->text().trimmed();              //密码
        QString realname=ui->lineEdit_3->text().trimmed();              //真实姓名      上面是读取
        if(name.isEmpty()||password.isEmpty()||realname.isEmpty())
        {QMessageBox::information(this,"提示","请输入");}
        else
        {QSqlQuery query;                                                   //这儿开始是插入
        query.prepare("INSERT INTO administrator(aid,apassword,aname)""VALUES(?,?,?)");     //插入时候由于aid是主键，所以插入时候写入的用户名不能重复
        query.addBindValue(name);
        query.addBindValue(password);
        query.addBindValue(realname);
        query.exec();
        QMessageBox::information(this,"提示","管理员注册成功！");}
    });

}

adregister::~adregister()
{
    delete ui;
}
void adregister::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/picture/sfji.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
