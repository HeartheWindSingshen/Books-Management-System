#include "relogin.h"                               //读者登录界面
#include "ui_relogin.h"
#include "reinformation.h"
#include <QPainter>
#include <QPushButton>
#include <updatereinformation.h>
#include <QSqlQuery>
#include <radio1.h>
#include <QMessageBox>
#include <bookinformation.h>
#include "radio1.h"
#include <QDate>
#include <itemform4.h>
#include <itemform5.h>
#include <QDebug>
#include <rereturn.h>
relogin::relogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::relogin)
{
     ui->setupUi(this);
     this->setWindowTitle("读者服务界面");
     connect(ui->pushButton,&QPushButton::clicked,[=](){
         reinformation*rein=new reinformation;
         rein->show();
     });
     connect(ui->pushButton_2,&QPushButton::clicked,[=](){
         updatereinformation*updat=new updatereinformation;
         updat->show();
     });
     connect(ui->pushButton_6,&QPushButton::clicked,[=](){
         QSqlQuery query;
         if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
         {QString sqlDelete=QString("delete from reader where id='%1';").arg(readerid);
         query.exec(sqlDelete);
         QMessageBox::information(this,"提示","注销账号成功！");}
     });
     connect(ui->pushButton_7,&QPushButton::clicked,[=](){
         this->close();
     });
     connect(ui->pushButton_3,&QPushButton::clicked,[=](){
          bookinformation*bookinfor=new bookinformation;
          bookinfor->show();
     });
     connect(ui->pushButton_8,&QPushButton::clicked,[=](){
         ui->listWidget->clear();
         QSqlQuery query;
         QString sqlSelect=QString("select *from borrow;");
         query.exec(sqlSelect);
         while (query.next()) {
             QString id=query.value("id").toString();
             QString bid=query.value("bid").toString();
             QString stime=query.value("stime").toString();
             QString etime=query.value("etime").toString();

             if(readerid==id)
             {
                itemform4 *staffitem=new itemform4;
             staffitem->setStaffInfo4(id,bid,stime,etime);
             QListWidgetItem * item=new QListWidgetItem;
             item->setSizeHint(QSize(370,33));
             ui->listWidget->addItem(item);
             ui->listWidget->setItemWidget(item,staffitem);
             }
         }
     });
         connect(ui->pushButton_9,&QPushButton::clicked,[=](){
             ui->listWidget_2->clear();
             QSqlQuery query;
             QString sqlSelect=QString("select *from returned;");
             query.exec(sqlSelect);
             while (query.next()) {
                 QString id=query.value("id").toString();
                 QString bid=query.value("bid").toString();
                 QString rtime=query.value("rtime").toString();
                 QString note=query.value("note").toString();
                if(readerid==id)
                 { itemform5*staffitem=new itemform5;
                 staffitem->setStaffInfo5(id,bid,rtime,note);
                 QListWidgetItem * item=new QListWidgetItem;
                 item->setSizeHint(QSize(433,38));
                 ui->listWidget_2->addItem(item);
                 ui->listWidget_2->setItemWidget(item,staffitem);
             }
             }
         });
         connect(ui->pushButton_4,&QPushButton::clicked,[=](){
                 QString bid=ui->lineEdit->text();
                 QString stime=ui->lineEdit_2->text();
                 QString etime=ui->lineEdit_4->text();
                 QSqlQuery query;
                 if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
                { QString sqlInsert=QString("insert into borrow(id,bid,stime,etime)" "values('%1','%2','%3','%4');")
                       .arg(readerid) .arg(bid).arg(stime).arg(etime);
                 query.exec(sqlInsert);

                 QSqlQuery query2;
                 QString sqlUpdate=QString("update book set state=state-1 where bid='%2';").arg(bid);
                 query2.exec(sqlUpdate);
                 QMessageBox::information(this,"提示","借书成功！");}
         });
         connect(ui->pushButton_5,&QPushButton::clicked,[=](){

             QString bid=ui->lineEdit->text();
             QString rtime=ui->lineEdit_3->text();
             QString note=ui->lineEdit_5->text();
             QSqlQuery query;
             if(QMessageBox::Save==QMessageBox::question(this,"提问","你确定要执行此操作吗？",QMessageBox::Save|QMessageBox::Cancel))
            { QString sqlInsert=QString("insert into returned(id,bid,rtime,note)" "values('%1','%2','%3','%4');")
                   .arg(readerid) .arg(bid).arg(rtime).arg(note);
             query.exec(sqlInsert);

             QSqlQuery query2;
             QString sqlUpdate=QString("update book set state=state+1 where bid='%2';").arg(bid);
             query2.exec(sqlUpdate);

             QSqlQuery query3;
             QString id=ui->lineEdit->text();
             QString sqlDelete=QString("delete from borrow where id='%1'and bid='%2';").arg(readerid).arg(bid);
             query3.exec(sqlDelete);
             QMessageBox::information(this,"提示","还书成功！");}
         });
}

relogin::~relogin()
{
    delete ui;
}
void relogin::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/picture/sfji.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
