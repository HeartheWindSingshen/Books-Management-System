#ifndef ITEMFORM5_H
#define ITEMFORM5_H

#include <QWidget>

namespace Ui {
class itemform5;
}

class itemform5 : public QWidget
{
    Q_OBJECT

public:
    explicit itemform5(QWidget *parent = nullptr);
    ~itemform5();
    void setStaffInfo5(QString id,QString bid,QString rtime,QString note);

private:
    Ui::itemform5 *ui;
};

#endif // ITEMFORM5_H
