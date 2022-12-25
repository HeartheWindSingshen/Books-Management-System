#ifndef RADIO2_H
#define RADIO2_H

#include <QObject>

class radio2 : public QObject
{
    Q_OBJECT
public:
    explicit radio2(QObject *parent = nullptr);

signals:

public slots:
    void radio22();
};

#endif // RADIO2_H
