#ifndef RERETURN_H
#define RERETURN_H

#include <QWidget>

namespace Ui {
class rereturn;
}

class rereturn : public QWidget
{
    Q_OBJECT

public:
    explicit rereturn(QWidget *parent = nullptr);
    ~rereturn();

private:
    Ui::rereturn *ui;
};

#endif // RERETURN_H
