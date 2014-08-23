#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>

#include "src/repository/configrepository.h"

namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigDialog(QWidget *parent = 0);
    ~ConfigDialog();
    void setConfigRepository (ConfigRepository * repo);

private:
    Ui::ConfigDialog *ui;
    ConfigRepository *configRepository;

public slots:
    void accept();
    void show();

};

#endif // CONFIGDIALOG_H
