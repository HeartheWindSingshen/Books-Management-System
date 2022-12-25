#include "adupdatereinformation.h"                                    //管理员界面的读者信息管理的更改界面
#include "ui_adupdatereinformation.h"
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
adupdatereinformation::adupdatereinformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adupdatereinformation)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员的读者信息更改界面");
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->close();
    });
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString id=ui->lineEdit->text();
        QString name=ui->lineEdit_2->text();
        QString sex=ui->lineEdit_3->text();
        QString birthday=ui->lineEdit_4->text();
        QString password=ui->lineEdit_5->text();
        QString tel=ui->lineEdit_6->text();
        QString email=ui->lineEdit_7->text();
        QString note=ui->lineEdit_8->text();
        int times=ui->lineEdit_9->text().toInt();

        QSqlQuery query;
        if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
        {QString sqlUpdate=QString("update reader set name='%1',sex='%2',birthday='%3',password='%4',tel='%5',email='%6',note='%7',times=%8 where id='%9';")
               .arg(name).arg(sex).arg(birthday).arg(password).arg(tel).arg(email).arg(note).arg(times).arg(id);
        query.exec(sqlUpdate);
        QMessageBox::information(this,"提示","读者信息更新成功！");}
    });

}

adupdatereinformation::~adupdatereinformation()
{
    delete ui;
}
