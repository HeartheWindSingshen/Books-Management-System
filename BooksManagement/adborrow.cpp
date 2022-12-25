#include "adborrow.h"
#include "ui_adborrow.h"
#include <QPainter>
#include <QPushButton>
#include <QSqlQuery>
#include <QMessageBox>
#include <bookinformation.h>
#include "radio1.h"
#include <QDate>
#include <QDebug>
#include <itemform6.h>
adborrow::adborrow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adborrow)
{
    ui->setupUi(this);
    this->setWindowTitle("借阅信息管理");
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->listWidget->clear();
        QSqlQuery query;
        QString sqlSelect=QString("select *from borrow;");
        query.exec(sqlSelect);
        while (query.next()) {
            QString id=query.value("id").toString();
            QString bid=query.value("bid").toString();
            QString stime=query.value("stime").toString();
            QString etime=query.value("etime").toString();

               itemform6 *staffitem=new itemform6;
            staffitem->setStaffInfo6(id,bid,stime,etime);
            QListWidgetItem * item=new QListWidgetItem;
            item->setSizeHint(QSize(370,33));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,staffitem);
        }
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        this->close();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        QString id=ui->lineEdit->text();
        QString bid=ui->lineEdit_2->text();
        QString stime=ui->lineEdit_3->text();
        QString etime=ui->lineEdit_4->text();

        QSqlQuery query;
        if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
       { QString sqlUpdate=QString("update borrow set stime='%1',etime='%2' where id='%3'and bid='%4';")
               .arg(stime).arg(etime).arg(id).arg(bid);
        query.exec(sqlUpdate);
        QMessageBox::information(this,"提示","借阅信息更新成功！");}
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        QString id=ui->lineEdit_5->text();
        QString bid=ui->lineEdit_6->text();
        QSqlQuery query;
       if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
        {QString sqlDelete=QString("delete from borrow where id='%1'and bid='%2';").arg(id).arg(bid);
        query.exec(sqlDelete);
        QMessageBox::information(this,"提示","删除借阅信息成功！");}
    });
}

adborrow::~adborrow()
{
    delete ui;
}
