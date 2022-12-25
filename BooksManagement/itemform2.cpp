#include "itemform2.h"                                             //有关管理员信息查询的帮助函数，上一级是adlogin
#include "ui_itemform2.h"

itemform2::itemform2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemform2)
{
    ui->setupUi(this);
}

itemform2::~itemform2()
{
    delete ui;
}
void itemform2::setStaffInfo2(QString aid,QString apassword,QString aname)
{
    ui->label->setText(aid);
    ui->label_2->setText(apassword);
    ui->label_3->setText(aname);
}
