#include "rereturn.h"
#include "ui_rereturn.h"
#include <QPainter>
#include <QPushButton>
#include <updatereinformation.h>
#include <QSqlQuery>
#include <radio1.h>
#include <QMessageBox>
#include <bookinformation.h>
#include "radio1.h"
#include <QDate>
#include "itemform5.h"
rereturn::rereturn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rereturn)
{
    ui->setupUi(this);
//    connect(ui->pushButton,&QPushButton::clicked,[=](){
//        ui->listWidget->clear();
//        QSqlQuery query;
//        QString sqlSelect=QString("select *from returned;");
//        query.exec(sqlSelect);
//        while (query.next()) {
//            QString id=query.value("id").toString();
//            QString bid=query.value("bid").toString();
//            QString rtime=query.value("rtime").toString();
//            QString note=query.value("note").toString();

//             itemform5*staffitem=new itemform5;
//            staffitem->setStaffInfo5(id,bid,rtime,note);
//            QListWidgetItem * item=new QListWidgetItem;
//            item->setSizeHint(QSize(433,38));
//            ui->listWidget->addItem(item);
//            ui->listWidget->setItemWidget(item,staffitem);
//        }
//    });
}
rereturn::~rereturn()
{
    delete ui;
}
