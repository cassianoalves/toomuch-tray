#include "mainwindow.h"
#include <QApplication>
#include <QSystemTrayIcon>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSystemTrayIcon *tray = new QSystemTrayIcon();
    QPixmap content;
    content.fill(Qt::red);
    QIcon ico(content);
    tray->setIcon(ico);
    tray->show();

    //MainWindow w;
    //w.show();

    return a.exec();
}
