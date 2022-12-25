#include "updatereinformation.h"
#include "ui_updatereinformation.h"
#include <QPainter>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QPainter>                         //信息更改界面
#include <QPushButton>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlTableModel>
#include <radio1.h>
#include <QListWidgetItem>
updatereinformation::updatereinformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updatereinformation)
{
    ui->setupUi(this);
    this->setWindowTitle("读者信息更改界面");
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->close();
    });
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString name=ui->lineEdit->text();
        QString sex=ui->lineEdit_2->text();
        QString birthday=ui->lineEdit_3->text();
        QString password=ui->lineEdit_4->text();
        QString tel=ui->lineEdit_5->text();
        QString email=ui->lineEdit_6->text();
        QSqlQuery query;
         if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
       { QString sqlUpdate=QString("update reader set name='%1',sex='%2',birthday='%3',password='%4',tel='%5',email='%6' where id='%7';")
                .arg(name).arg(sex).arg(birthday).arg(password).arg(tel).arg(email).arg(readerid);
        query.exec(sqlUpdate);
        QMessageBox::information(this,"提示","读者信息更新成功！");}
    });

}

updatereinformation::~updatereinformation()
{
    delete ui;
}
