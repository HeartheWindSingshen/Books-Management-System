#include "itemform4.h"                                //用于读者借阅信息查询
#include "ui_itemform4.h"
#include <QDate>
#include <QDateTime>
itemform4::itemform4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemform4)
{
    ui->setupUi(this);
}

itemform4::~itemform4()
{
    delete ui;
}
void itemform4::setStaffInfo4(QString id,QString bid,QString stime,QString etime)
{
    ui->label->setText(id);
    ui->label_2->setText(bid);
    ui->label_3->setText(stime);
    ui->label_4->setText(etime);

}
