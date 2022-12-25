#ifndef ADREGISTER_H
#define ADREGISTER_H

#include <QWidget>

namespace Ui {
class adregister;
}

class adregister : public QWidget
{
    Q_OBJECT

public:
    explicit adregister(QWidget *parent = nullptr);
    ~adregister();
    void paintEvent(QPaintEvent *);
private:
    Ui::adregister *ui;
};

#endif // ADREGISTER_H
