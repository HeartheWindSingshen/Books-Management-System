#ifndef ITEMFORM6_H
#define ITEMFORM6_H

#include <QWidget>

namespace Ui {
class itemform6;
}

class itemform6 : public QWidget
{
    Q_OBJECT

public:
    explicit itemform6(QWidget *parent = nullptr);
    ~itemform6();
    void setStaffInfo6(QString id,QString bid,QString stime,QString etime);
private:
    Ui::itemform6 *ui;
};

#endif // ITEMFORM6_H
