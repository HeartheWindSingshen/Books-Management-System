#include "frefg.h"
#include "ui_frefg.h"

frefg::frefg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frefg)
{
    ui->setupUi(this);
}

frefg::~frefg()
{
    delete ui;
}
