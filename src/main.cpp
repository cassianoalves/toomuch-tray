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
    QApplication a(argc, argv);

    Floating w;
    Menu menu(&w);
    w.setContextMenu(&menu);
    ConfigDialog config;
    ConfigRepository * configRepo = new ConfigDatDAO(getenv("HOME"));
    config.setConfigRepository(configRepo);
    w.setConfigRepository(configRepo);

    QObject::connect(&menu, SIGNAL(quit()), &a, SLOT(quit()));
    QObject::connect(&menu, SIGNAL(configure()), &config, SLOT(show()));


    //QRect cur = w.geometry();
    //cur.setCoords(300,500,50,50);

    //w.setGeometry(500,100,200,200);
    w.show();


    return a.exec();
}
