#ifndef ITEMFORM7_H
#define ITEMFORM7_H

#include <QWidget>

namespace Ui {
class itemform7;
}

class itemform7 : public QWidget
{
    Q_OBJECT

public:
    explicit itemform7(QWidget *parent = nullptr);
    ~itemform7();
    void setStaffInfo7(QString id,QString bid,QString rtime,QString note);
private:
    Ui::itemform7 *ui;
};

#endif // ITEMFORM7_H
