#include "itemform3.h"
#include "ui_itemform3.h"

itemform3::itemform3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemform3)
{
    ui->setupUi(this);
}

itemform3::~itemform3()
{
    delete ui;
}
void itemform3::setStaffInfo3(QString bid,QString bname,QString author,QString publisher,int state,QString note)
{
    ui->label->setText(bid);
    ui->label_2->setText(bname);
    ui->label_3->setText(author);
    ui->label_4->setText(publisher);
    ui->label_5->setText(QString::number(state));
    ui->label_6->setText(note);
}
