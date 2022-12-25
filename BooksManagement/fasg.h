#ifndef FASG_H
#define FASG_H

#include <QMainWindow>

namespace Ui {
class fasg;
}

class fasg : public QMainWindow
{
    Q_OBJECT

public:
    explicit fasg(QWidget *parent = nullptr);
    ~fasg();

private:
    Ui::fasg *ui;
};

#endif // FASG_H
