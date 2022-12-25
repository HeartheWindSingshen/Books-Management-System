#ifndef UPDATEREINFORMATION_H
#define UPDATEREINFORMATION_H

#include <QWidget>

namespace Ui {
class updatereinformation;
}

class updatereinformation : public QWidget
{
    Q_OBJECT

public:
    explicit updatereinformation(QWidget *parent = nullptr);
    ~updatereinformation();

private:
    Ui::updatereinformation *ui;
};

#endif // UPDATEREINFORMATION_H
