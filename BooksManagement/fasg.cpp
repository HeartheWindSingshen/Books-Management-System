#include "fasg.h"
#include "ui_fasg.h"

fasg::fasg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fasg)
{
    ui->setupUi(this);
}

fasg::~fasg()
{
    delete ui;
}
