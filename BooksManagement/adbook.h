#ifndef ADBOOK_H
#define ADBOOK_H

#include <QWidget>

namespace Ui {
class adbook;
}

class adbook : public QWidget
{
    Q_OBJECT

public:
    explicit adbook(QWidget *parent = nullptr);
    ~adbook();

private:
    Ui::adbook *ui;
};

#endif // ADBOOK_H
