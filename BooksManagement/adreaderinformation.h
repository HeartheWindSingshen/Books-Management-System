#ifndef ADREADERINFORMATION_H
#define ADREADERINFORMATION_H

#include <QWidget>

namespace Ui {
class adreaderinformation;
}

class adreaderinformation : public QWidget
{
    Q_OBJECT

public:
    explicit adreaderinformation(QWidget *parent = nullptr);
    ~adreaderinformation();
    void paintEvent(QPaintEvent *);

private:
    Ui::adreaderinformation *ui;
};

#endif // ADREADERINFORMATION_H
