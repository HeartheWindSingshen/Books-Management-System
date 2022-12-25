#ifndef ITEMFORM2_H
#define ITEMFORM2_H

#include <QWidget>

namespace Ui {
class itemform2;
}

class itemform2 : public QWidget
{
    Q_OBJECT

public:
    explicit itemform2(QWidget *parent = nullptr);
    ~itemform2();
    void setStaffInfo2(QString aid,QString apassword,QString aname);

private:
    Ui::itemform2 *ui;
};

#endif // ITEMFORM2_H
