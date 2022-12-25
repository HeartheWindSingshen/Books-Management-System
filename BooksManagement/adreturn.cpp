#include "adreturn.h"
#include "ui_adreturn.h"
#include "itemform7.h"
#include <QPainter>
#include <QPushButton>
#include <QSqlQuery>
#include <QMessageBox>
#include <bookinformation.h>
#include "radio1.h"
#include <QDate>
#include <QDebug>
#include <QListWidgetItem>
adreturn::adreturn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adreturn)
{
    ui->setupUi(this);
    this->setWindowTitle("归还信息管理");
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->listWidget->clear();
        QSqlQuery query;
        QString sqlSelect=QString("select *from returned;");
        query.exec(sqlSelect);
        while (query.next()) {
            QString id=query.value("id").toString();
            QString bid=query.value("bid").toString();
            QString rtime=query.value("rtime").toString();
            QString note=query.value("note").toString();

               itemform7 *staffitem=new itemform7;
            staffitem->setStaffInfo7(id,bid,rtime,note);
            QListWidgetItem * item=new QListWidgetItem;
            item->setSizeHint(QSize(339,33));
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
        QString rtime=ui->lineEdit_3->text();
        QString note=ui->lineEdit_4->text();

        QSqlQuery query;
        if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
        {QString sqlUpdate=QString("update returned set rtime='%1',note='%2' where id='%3'and bid='%4';")
               .arg(rtime).arg(note).arg(id).arg(bid);
        query.exec(sqlUpdate);
        QMessageBox::information(this,"提示","还书信息更新成功！");}
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        QString id=ui->lineEdit_5->text();
        QString bid=ui->lineEdit_6->text();
        QSqlQuery query;
        if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
        {QString sqlDelete=QString("delete from returned where id='%1'and bid='%2';").arg(id).arg(bid);
        query.exec(sqlDelete);
        QMessageBox::information(this,"提示","删除还书信息成功！");}
    });
}

adreturn::~adreturn()
{
    delete ui;
}
