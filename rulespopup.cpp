#include "rulespopup.h"
#include "ui_rulespopup.h"

rulespopup::rulespopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rulespopup)
{
    ui->setupUi(this);
}

rulespopup::~rulespopup()
{
    delete ui;
}
