#ifndef BOOKINFORMATION_H
#define BOOKINFORMATION_H

#include <QWidget>

namespace Ui {
class bookinformation;
}

class bookinformation : public QWidget
{
    Q_OBJECT

public:
    explicit bookinformation(QWidget *parent = nullptr);
    ~bookinformation();

private:
    Ui::bookinformation *ui;
};

#endif // BOOKINFORMATION_H
