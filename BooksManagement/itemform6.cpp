#include "itemform6.h"                                      //用于书籍信息的查询
#include "ui_itemform6.h"

itemform6::itemform6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemform6)
{
    ui->setupUi(this);
}

itemform6::~itemform6()
{
    delete ui;
}
void itemform6::setStaffInfo6(QString id,QString bid,QString stime,QString etime)
{
    ui->label->setText(id);
    ui->label_2->setText(bid);
    ui->label_3->setText(stime);
    ui->label_4->setText(etime);

}
