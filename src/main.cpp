#include <QApplication>
#include <QSystemTrayIcon>
#include <QPixmap>
#include <QLabel>

#include "src/view/floating.h"
#include "src/view/menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Floating w;
    Menu menu(&w);
    w.setContextMenu(&menu);

    QObject::connect(&menu, SIGNAL(quit()), &a, SLOT(quit()));


    //QRect cur = w.geometry();
    //cur.setCoords(300,500,50,50);

    //w.setGeometry(500,100,200,200);
    w.show();


    return a.exec();
}
