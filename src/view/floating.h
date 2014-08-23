#ifndef FLOATING_H
#define FLOATING_H

#include <QWidget>
#include <QMenu>
#include "src/model/pomodoro.h"
#include "src/repository/configrepository.h"


namespace Ui {
class Floating;
}

class Floating : public QWidget
{
    Q_OBJECT

public:
    explicit Floating(QWidget *parent = 0);
    ~Floating();
    void setContextMenu(QMenu *menu);
    void setConfigRepository (ConfigRepository * repo);

public slots:
    void updatePomodoro(Pomodoro status);
    void show();

protected:
     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void contextMenuEvent(QContextMenuEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);


private:
    Ui::Floating *ui;
    QPoint dragPos;
    QMenu *contextMenu;
    ConfigRepository *configRepository;
    QRect screenLimits;

};

#endif // FLOATING_H
