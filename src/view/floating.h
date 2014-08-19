#ifndef FLOATING_H
#define FLOATING_H

#include <QWidget>
#include <QMenu>
#include "src/model/pomodoro.h"

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

public slots:
    void updatePomodoro(Pomodoro status);

protected:
     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void contextMenuEvent(QContextMenuEvent *event);


private:
    Ui::Floating *ui;
    QPoint dragPos;
    QMenu *contextMenu;
};

#endif // FLOATING_H
