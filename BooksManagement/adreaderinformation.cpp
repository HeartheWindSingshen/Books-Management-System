#include "adreaderinformation.h"                               //管理员登录界面的读者信息管理
#include "ui_adreaderinformation.h"
#include <QPainter>
#include <QPainter>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QPainter>
#include <QPushButton>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlTableModel>
#include <radio1.h>
#include <QListWidgetItem>
#include "itemform.h"
#include "adupdatereinformation.h"
#include "adreaderinformationdelete.h"
adreaderinformation::adreaderinformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adreaderinformation)
{
    ui->setupUi(this);
    this->setWindowTitle("读者信息管理系统");
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        this->close();
    });
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->listWidget->clear();
        QSqlQuery query;
        QString sqlSelect=QString("select *from reader;");
        query.exec(sqlSelect);
        while (query.next()) {
            QString id=query.value("id").toString();
            QString name=query.value("name").toString();
            QString sex=query.value("sex").toString();
            QString birthday=query.value("birthday").toString();
            QString password=query.value("password").toString();
            QString tel=query.value("tel").toString();
            QString email=query.value("email").toString();
            QString note=query.value("note").toString();
            int times=query.value("times").toInt();
               itemform *staffitem=new itemform;
            staffitem->setStaffInfo(id,name,sex,birthday,password,tel,email,note,times);
            QListWidgetItem * item=new QListWidgetItem;
            item->setSizeHint(QSize(784,52));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,staffitem);
        }
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        adupdatereinformation*adupdat=new adupdatereinformation;
        adupdat->show();
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        adreaderinformationdelete*adreader=new adreaderinformationdelete;
        adreader->show();
    });
}

adreaderinformation::~adreaderinformation()
{
    delete ui;
}
void adreaderinformation::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/picture/library.PNG");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
