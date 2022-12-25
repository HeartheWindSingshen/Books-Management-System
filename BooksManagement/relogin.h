#ifndef RELOGIN_H
#define RELOGIN_H

#include <QWidget>

namespace Ui {
class relogin;
}

class relogin : public QWidget
{
    Q_OBJECT

public:
    explicit relogin(QWidget *parent = nullptr);
    ~relogin();
    void paintEvent(QPaintEvent *);

private:
    Ui::relogin *ui;
};

#endif // RELOGIN_H
