#include "src/view/floating.h"
#include <QApplication>
#include <QSystemTrayIcon>
#include <QPixmap>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    QSystemTrayIcon tray;
    QPixmap content;
    content.fill(Qt::red);

    QIcon ico;
    tray.setIcon(ico);

    tray.show();

*/


    Floating w;
    QMenu menu;
    menu.addAction("Quit");

    w.setContextMenu(&menu);


    //QRect cur = w.geometry();
    //cur.setCoords(300,500,50,50);

    //w.setGeometry(500,100,200,200);
    w.show();


    return a.exec();
}
