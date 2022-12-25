#ifndef REREGISTER_H
#define REREGISTER_H

#include <QWidget>

namespace Ui {
class reregister;
}

class reregister : public QWidget
{
    Q_OBJECT

public:
    explicit reregister(QWidget *parent = nullptr);
    ~reregister();
    void paintEvent(QPaintEvent *);
private:
    Ui::reregister *ui;
};

#endif // REREGISTER_H
