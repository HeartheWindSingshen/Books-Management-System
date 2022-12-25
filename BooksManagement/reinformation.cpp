#include "reinformation.h"                                      //读者信息查询界面，只查询自己
#include "ui_reinformation.h"
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
reinformation::reinformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reinformation)
{
    ui->setupUi(this);
    this->setWindowTitle("读者信息查询界面");
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->close();
    });

    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
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

            if(readerid==id)
            {
               itemform *staffitem=new itemform;
            staffitem->setStaffInfo(id,name,sex,birthday,password,tel,email,note,times);
            QListWidgetItem * item=new QListWidgetItem;
            item->setSizeHint(QSize(748,52));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,staffitem);
            }
        }

    });
}

reinformation::~reinformation()
{
    delete ui;
}
