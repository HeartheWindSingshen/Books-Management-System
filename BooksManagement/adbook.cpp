#include "adbook.h"
#include "ui_adbook.h"
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
#include <bookinformation.h>
adbook::adbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adbook)
{
    ui->setupUi(this);
    this->setWindowTitle("书籍信息管理");
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        bookinformation*bookinfor=new bookinformation;
        bookinfor->show();
    });
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){
        this->close();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        QString bid=ui->lineEdit->text();
        QString bname=ui->lineEdit_2->text();
        QString author=ui->lineEdit_3->text();
        QString publisher=ui->lineEdit_4->text();
        int  state=ui->lineEdit_5->text().toInt();
        QString note=ui->lineEdit_6->text();
        QSqlQuery query;
        if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
       { QString sqlUpdate=QString("update book set bname='%1',author='%2',publisher='%3',state=%4,note='%5' where bid='%6';")
               .arg(bname).arg(author).arg(publisher).arg(state).arg(note).arg(bid);
        query.exec(sqlUpdate);
        QMessageBox::information(this,"提示","图书信息更新成功！");}
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        QString bid=ui->lineEdit_7->text();
        QSqlQuery query;
       if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
       { QString sqlDelete=QString("delete from book where bid='%1';").arg(bid);
        query.exec(sqlDelete);
        QMessageBox::information(this,"提示","删除书籍成功！");}
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        QString bid=ui->lineEdit->text();
        QString bname=ui->lineEdit_2->text();
        QString author=ui->lineEdit_3->text();
        QString publisher=ui->lineEdit_4->text();
        int  state=ui->lineEdit_5->text().toInt();
        QString note=ui->lineEdit_6->text();

        QSqlQuery query;
        if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
        {QString sqlInsert=QString("insert into book(bid,bname,author,publisher,state,note)" "values('%1','%2','%3','%4',%5,'%6');")
               .arg(bid).arg(bname).arg(author).arg(publisher).arg(state).arg(note);
        query.exec(sqlInsert);
        QMessageBox::information(this,"提示","图书增添成功！");}
    });

}

adbook::~adbook()
{
    delete ui;
}
