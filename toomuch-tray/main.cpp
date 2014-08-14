#include "mainwindow.h"
#include "floating.h"
#include <QApplication>
#include <QSystemTrayIcon>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    QSystemTrayIcon *tray = new QSystemTrayIcon();
    QPixmap content;
    content.fill(Qt::red);
    QIcon ico(content);
    tray->setIcon(ico);
    tray->show();

*/

    Floating w;
    w.setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
    w.setGeometry(100,100,40,50);
    w.show();

    return a.exec();
}
