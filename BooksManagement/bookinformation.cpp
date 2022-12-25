#include "bookinformation.h"
#include "ui_bookinformation.h"
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
#include <itemform3.h>
bookinformation::bookinformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookinformation)
{
    ui->setupUi(this);
    this->setWindowTitle("书籍信息查询界面");
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->close();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        ui->listWidget->clear();
        QSqlQuery query;
        QString sqlSelect=QString("select *from book;");
         QString name=ui->lineEdit->text();
        query.exec(sqlSelect);
        while (query.next()) {
            QString bid=query.value("bid").toString();
            QString bname=query.value("bname").toString();
            QString author=query.value("author").toString();
            QString publisher=query.value("publisher").toString();
            int state=query.value("state").toInt();
            QString note=query.value("note").toString();
            if(bname==name){
            itemform3 *staffitem=new itemform3;
            staffitem->setStaffInfo3(bid,bname,author,publisher,state,note);
            QListWidgetItem * item=new QListWidgetItem;
            item->setSizeHint(QSize(613,38));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,staffitem);
            }
        }
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        ui->listWidget->clear();
        QSqlQuery query;
        QString sqlSelect=QString("select *from book;");
        query.exec(sqlSelect);
        while (query.next()) {
            QString bid=query.value("bid").toString();
            QString bname=query.value("bname").toString();
            QString author=query.value("author").toString();
            QString publisher=query.value("publisher").toString();
            int state=query.value("state").toInt();
            QString note=query.value("note").toString();
            itemform3 *staffitem=new itemform3;
            staffitem->setStaffInfo3(bid,bname,author,publisher,state,note);
            QListWidgetItem * item=new QListWidgetItem;
            item->setSizeHint(QSize(613,38));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,staffitem);
        }
    });
}

bookinformation::~bookinformation()
{
    delete ui;
}
