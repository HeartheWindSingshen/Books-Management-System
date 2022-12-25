#ifndef RADIO1_H
#define RADIO1_H

#include <QObject>
extern bool radio;                         //全局变量radio的关键一步
extern bool flag;                          //flag
extern QString readerid;
extern QString administratorid;
class radio1 : public QObject
{
    Q_OBJECT
public:
    explicit radio1(QObject *parent = nullptr);

signals:

public slots:
    void radio11();
};

#endif // RADIO1_H
