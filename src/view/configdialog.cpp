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
    types << "Shell";
    types << "Tomatoi";

    ui->cbType->addItems(types);
}

void ConfigDialog::show()
{
    Config * config = configRepository->readConfig();
    ui->txtParameter->setText(config->sourceInfo.c_str());
    ui->spInterval->setValue(config->updateTime);
    ui->cbType->setCurrentIndex(config->source);
    QDialog::show();
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

void ConfigDialog::setConfigRepository(ConfigRepository * repo)
{
    configRepository = repo;
}

void ConfigDialog::accept()
{
    Config * c = configRepository->readConfig();
    c->sourceInfo = ui->txtParameter->text().toStdString();
    c->updateTime = ui->spInterval->value();
    c->setSource(ui->cbType->currentIndex());
    configRepository->writeConfig(*c);
    QDialog::accept();
}
