#include "itemform5.h"
#include "ui_itemform5.h"

itemform5::itemform5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemform5)
{
    ui->setupUi(this);
}

itemform5::~itemform5()
{
    delete ui;
}
void itemform5::setStaffInfo5(QString id,QString bid,QString rtime,QString note)
{
    ui->label->setText(id);
    ui->label_2->setText(bid);
    ui->label_3->setText(rtime);
    ui->label_4->setText(note);
}
