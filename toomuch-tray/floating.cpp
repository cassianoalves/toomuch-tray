#include "floating.h"
#include "ui_floating.h"

Floating::Floating(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Floating)
{
    ui->setupUi(this);
}

Floating::~Floating()
{
    delete ui;
}
