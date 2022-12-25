#ifndef ITEMFORM4_H
#define ITEMFORM4_H

#include <QWidget>
#include <QDate>
namespace Ui {
class itemform4;
}

class itemform4 : public QWidget
{
    Q_OBJECT

public:
    explicit itemform4(QWidget *parent = nullptr);
    ~itemform4();
    void setStaffInfo4(QString id,QString bid,QString stime,QString etime);
private:
    Ui::itemform4 *ui;
};

#endif // ITEMFORM4_H
