#ifndef ADUPDATEREINFORMATION_H
#define ADUPDATEREINFORMATION_H

#include <QWidget>

namespace Ui {
class adupdatereinformation;
}

class adupdatereinformation : public QWidget
{
    Q_OBJECT

public:
    explicit adupdatereinformation(QWidget *parent = nullptr);
    ~adupdatereinformation();

private:
    Ui::adupdatereinformation *ui;
};

#endif // ADUPDATEREINFORMATION_H
