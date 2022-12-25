#include "reregister.h"                                          //读者注册界面
#include "ui_reregister.h"
#include <QPainter>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
reregister::reregister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reregister)
{
    ui->setupUi(this);
    this->setWindowTitle("读者注册界面");
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->close();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        QString name = ui->lineEdit->text().trimmed();                 //用户名
         //密码
        QString realname=ui->lineEdit_3->text().trimmed();              //真实姓名      上面是读取
        QString sex=ui->lineEdit_4->text().trimmed();
        QString birthday=ui->lineEdit_5->text().trimmed();
        QString password=ui->lineEdit_7->text().trimmed();
        QString tel=ui->lineEdit_6->text().trimmed();
        QString email=ui->lineEdit_2->text().trimmed();
        if(name.isEmpty()||password.isEmpty()||realname.isEmpty()||sex.isEmpty()||birthday.isEmpty()||tel.isEmpty()||email.isEmpty())
        {QMessageBox::information(this,"提示","请输入");}
        else
        {QSqlQuery query;                                                   //这儿开始是插入
        query.prepare("INSERT INTO reader(id,name,sex,birthday,password,tel,email,note,times)""VALUES(?,?,?,?,?,?,?,?,?)");     //插入时候由于aid是主键，所以插入时候写入的用户名不能重复
        query.addBindValue(name);
        query.addBindValue(realname);
        query.addBindValue(sex);
        query.addBindValue(birthday);
        query.addBindValue(password);
        query.addBindValue(tel);
        query.addBindValue(email);
        query.addBindValue("无");
        query.addBindValue(0);
        query.exec();
        QMessageBox::information(this,"提示","读者注册成功！");}
    });
}

reregister::~reregister()
{
    delete ui;
}
void reregister::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/picture/sfji.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
