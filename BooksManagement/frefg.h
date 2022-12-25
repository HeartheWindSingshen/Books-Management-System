#ifndef FREFG_H
#define FREFG_H

#include <QDialog>

namespace Ui {
class frefg;
}

class frefg : public QDialog
{
    Q_OBJECT

public:
    explicit frefg(QWidget *parent = nullptr);
    ~frefg();

private:
    Ui::frefg *ui;
};

#endif // FREFG_H
