#include "itemform7.h"
#include "ui_itemform7.h"

itemform7::itemform7(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemform7)
{
    ui->setupUi(this);
}

itemform7::~itemform7()
{
    delete ui;
}
void itemform7::setStaffInfo7(QString id,QString bid,QString rtime,QString note)
{
    ui->label->setText(id);
    ui->label_2->setText(bid);
    ui->label_3->setText(rtime);
    ui->label_4->setText(note);

}
