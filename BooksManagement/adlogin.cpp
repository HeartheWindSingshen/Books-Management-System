#include "adlogin.h"                                                     //管理员登录界面
#include "ui_adlogin.h"
#include <QPainter>
#include <QPushButton>
#include <QSqlQuery>
#include <radio1.h>
#include <QMessageBox>
#include <itemform2.h>
#include <QListWidgetItem>
#include <adreaderinformation.h>
#include "adbook.h"
#include "adborrow.h"
#include "adreturn.h"
adlogin::adlogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adlogin)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员登录界面");
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){
        this->close();
    });
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){
        QSqlQuery query;
        if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel)){
        QString sqlDelete=QString("delete from administrator where aid='%1';").arg(administratorid);
        query.exec(sqlDelete);
        QMessageBox::information(this,"提示","管理员注销账号成功！");}
    });
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->listWidget->clear();
        QSqlQuery query;
        QString sqlSelect=QString("select *from administrator;");
        query.exec(sqlSelect);
        while (query.next()) {
            QString aid=query.value("aid").toString();
            QString apassword=query.value("apassword").toString();
            QString aname=query.value("aname").toString();

            itemform2 *staffitem=new itemform2;
            staffitem->setStaffInfo2(aid,apassword,aname);
            QListWidgetItem * item=new QListWidgetItem;
            item->setSizeHint(QSize(474,37));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,staffitem);
        }
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        adreaderinformation*adreader=new adreaderinformation;
        adreader->show();
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
       adbook*adbo=new adbook;
       adbo->show();
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        adborrow*adbo=new adborrow;
        adbo->show();
    });
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){
        adreturn*adre=new adreturn;
        adre->show();
    });
}

adlogin::~adlogin()
{
    delete ui;
}
void adlogin::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/picture/library.PNG");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
