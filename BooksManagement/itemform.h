#ifndef ITEMFORM_H
#define ITEMFORM_H

#include <QMainWindow>

namespace Ui {
class itemform;
}

class itemform : public QMainWindow
{
    Q_OBJECT

public:
    explicit itemform(QWidget *parent = nullptr);
    ~itemform();
    void setStaffInfo(QString id,QString name,QString sex,QString birthday,QString password,QString tel,QString email,QString note,int times);
private:
    Ui::itemform *ui;
};

#endif // ITEMFORM_H
