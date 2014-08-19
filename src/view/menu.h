#ifndef MENU_H
#define MENU_H

#include <QMenu>

class Menu : public QMenu
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = 0);

signals:
    void quit();
    void configure();

public slots:
    void quitSlot();
    void configureSlot();


private:
    QAction *configureAction;
    QAction *quitAction;

};

#endif // MENU_H
