#ifndef ADBORROW_H
#define ADBORROW_H

#include <QWidget>

namespace Ui {
class adborrow;
}

class adborrow : public QWidget
{
    Q_OBJECT

public:
    explicit adborrow(QWidget *parent = nullptr);
    ~adborrow();

private:
    Ui::adborrow *ui;
};

#endif // ADBORROW_H
