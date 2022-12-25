#include "itemform.h"                                                 //有关读者信息查询的帮助函数，为读者信息查询做帮助
#include "ui_itemform.h"

itemform::itemform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::itemform)
{
    ui->setupUi(this);
}

itemform::~itemform()
{
    delete ui;
}
void itemform::setStaffInfo(QString id, QString name, QString sex, QString birthday, QString password, QString tel, QString email, QString note, int times)
{
              ui->label->setText(id);
              ui->label_2->setText(name);
              ui->label_3->setText(sex);
              ui->label_4->setText(birthday);
              ui->label_5->setText(password);
              ui->label_6->setText(tel);
              ui->label_7->setText(email);
              ui->label_8->setText(note);
              ui->label_9->setText(QString::number(times));
}
