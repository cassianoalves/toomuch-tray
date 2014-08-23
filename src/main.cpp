#include <QApplication>
#include <QSystemTrayIcon>
#include <QPixmap>
#include <QLabel>

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

    menu.setConfigDialog(&config);
    menu.setPomodoroStatus(&pomodoroStatus);

    QObject::connect(&pomodoroStatus, SIGNAL(changed(Pomodoro)), &widget, SLOT(updatePomodoro(Pomodoro)));
//    QObject::connect(&menu, SIGNAL(quit()), &app, SLOT(quit()));
//    QObject::connect(&menu, SIGNAL(configure()), &config, SLOT(show()));


    //QRect cur = w.geometry();
    //cur.setCoords(300,500,50,50);

    //w.setGeometry(500,100,200,200);
    widget.show();


    return app.exec();
}
