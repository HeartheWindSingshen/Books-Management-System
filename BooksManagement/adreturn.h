#ifndef ADRETURN_H
#define ADRETURN_H

#include <QWidget>

namespace Ui {
class adreturn;
}

class adreturn : public QWidget
{
    Q_OBJECT

public:
    explicit adreturn(QWidget *parent = nullptr);
    ~adreturn();

private:
    Ui::adreturn *ui;
};

#endif // ADRETURN_H
