#ifndef REINFORMATION_H
#define REINFORMATION_H

#include <QWidget>

namespace Ui {
class reinformation;
}

class reinformation : public QWidget
{
    Q_OBJECT

public:
    explicit reinformation(QWidget *parent = nullptr);
    ~reinformation();

private:
    Ui::reinformation *ui;
};

#endif // REINFORMATION_H
