#ifndef ITEMFORM3_H
#define ITEMFORM3_H

#include <QWidget>

namespace Ui {
class itemform3;
}

class itemform3 : public QWidget
{
    Q_OBJECT

public:
    explicit itemform3(QWidget *parent = nullptr);
    ~itemform3();
    void setStaffInfo3(QString bid,QString bname,QString author,QString publisher,int state,QString note);
private:
    Ui::itemform3 *ui;
};

#endif // ITEMFORM3_H
