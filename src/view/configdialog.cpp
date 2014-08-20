#include "configdialog.h"
#include "ui_configdialog.h"

ConfigDialog::ConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
    QStringList types;
    types << "Offline";
    types << "TooMuch";
    types << "Tomatoi";
    types << "Shell";

    ui->cbType->addItems(types); ;

}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}
