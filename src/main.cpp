#include <QApplication>
#include <QSystemTrayIcon>
#include <QPixmap>
#include <QLabel>
#include <QDesktopWidget>
#include <iostream>

#include "src/view/floating.h"
#include "src/view/menu.h"
#include "src/view/configdialog.h"
#include "src/dao/configdatdao.h"
#include "src/repository/configrepository.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Floating widget;
    Menu menu(&widget);
    widget.setContextMenu(&menu);
    ConfigDialog config;
    ConfigRepository * configRepo = new ConfigDatDAO(getenv("HOME"));
    config.setConfigRepository(configRepo);
    widget.setConfigRepository(configRepo);
    PomodoroStatus pomodoroStatus;

    About about;

    menu.setConfigDialog(&config);
    menu.setPomodoroStatus(&pomodoroStatus);
    menu.setAboutDialog(&about);

    QObject::connect(&pomodoroStatus, SIGNAL(changed(Pomodoro)), &widget, SLOT(updatePomodoro(Pomodoro)));

    widget.show();

    return app.exec();
}
