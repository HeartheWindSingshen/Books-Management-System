#ifndef ADREADERINFORMATIONDELETE_H
#define ADREADERINFORMATIONDELETE_H

#include <QWidget>

namespace Ui {
class adreaderinformationdelete;
}

class adreaderinformationdelete : public QWidget
{
    Q_OBJECT

public:
    explicit adreaderinformationdelete(QWidget *parent = nullptr);
    ~adreaderinformationdelete();

private:
    Ui::adreaderinformationdelete *ui;
};

#endif // ADREADERINFORMATIONDELETE_H
