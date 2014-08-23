#include <QtGui>
#include <iostream>
#include "floating.h"
#include "ui_floating.h"
#include "src/format.h"
#include "src/model/config.h"

Floating::Floating(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Floating)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);

    screenLimits = QApplication::desktop()->availableGeometry();
    screenLimits.setBottomRight(screenLimits.bottomRight() - this->geometry().bottomRight());
}

Floating::~Floating()
{
    delete ui;
}

void Floating::updatePomodoro(Pomodoro status) {
    ui->lbTime->setText(Format::formatTime(status.timeRemaining).c_str());
    ui->lbEvent->setText(Format::formatEvent(status.pomodoroEvent).c_str());
}

void Floating::mousePressEvent(QMouseEvent *event) {
    screenLimits = QApplication::desktop()->availableGeometry();
    screenLimits.setBottomRight(screenLimits.bottomRight() - this->geometry().bottomRight());

    if (event->buttons() == Qt::LeftButton) {
        event->accept();
        dragPos = event->pos();
    } else {
        event->ignore();
    }
}

void Floating::mouseMoveEvent(QMouseEvent *event) {
    QPoint newPosition = event->globalPos() - dragPos;
    if ((event->buttons() == Qt::LeftButton)
            && screenLimits.contains(newPosition)
            )
    {
        event->accept();
        this->move(newPosition);
    } else {
        event->ignore();
    }
}

void Floating::contextMenuEvent(QContextMenuEvent *event) {
    contextMenu->move(event->globalPos());
    contextMenu->show();
}

void Floating::setContextMenu(QMenu *menu) {
    contextMenu = menu;
}

void Floating::setConfigRepository(ConfigRepository * repo)
{
    configRepository = repo;
}

void Floating::mouseReleaseEvent(QMouseEvent *event)
{
    Config * c = configRepository->readConfig();
    c->widgetPosition = (event->globalPos() - dragPos);
    configRepository->writeConfig(*c);
    delete c;
    event->ignore();
}

void Floating::show()
{
    Config * c = configRepository->readConfig();
    this->move(c->widgetPosition);
    delete c;
    QWidget::show();
}
