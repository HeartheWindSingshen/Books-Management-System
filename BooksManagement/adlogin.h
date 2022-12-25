#ifndef ADLOGIN_H
#define ADLOGIN_H

#include <QMainWindow>

namespace Ui {
class adlogin;
}

class adlogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit adlogin(QWidget *parent = nullptr);
    ~adlogin();
    void paintEvent(QPaintEvent *);

private:
    Ui::adlogin *ui;
};

#endif // ADLOGIN_H
