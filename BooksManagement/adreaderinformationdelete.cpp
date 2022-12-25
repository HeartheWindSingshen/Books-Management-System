#include "adreaderinformationdelete.h"                              //管理员界面的读者信息管理的删除界面
#include "ui_adreaderinformationdelete.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QPainter>
adreaderinformationdelete::adreaderinformationdelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adreaderinformationdelete)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员读者账号注销界面");
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->close();
    });
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QSqlQuery query;
        QString id=ui->lineEdit->text();
        if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
        {QString sqlDelete=QString("delete from reader where id='%1';").arg(id);
        query.exec(sqlDelete);
        QMessageBox::information(this,"提示","注销账号成功！");}
    });
}

adreaderinformationdelete::~adreaderinformationdelete()
{
    delete ui;
}
