#include <QtGui>
#include <iostream>
#include "floating.h"
#include "ui_floating.h"
#include "src/format.h"

Floating::Floating(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Floating)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
}

Floating::~Floating()
{
    delete ui;
}

void Floating::updatePomodoro(Pomodoro status) {
    ui->lbEvent->setText(Format::formatTime(status.timeRemaining).c_str());
    ui->lbTime->setText(Format::formatEvent(status.pomodoroEvent).c_str());
}

void Floating::mousePressEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        event->accept();
        dragPos = event->pos();
    } else {
        event->ignore();
    }
}

void Floating::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        event->accept();
        this->move(event->globalPos() - dragPos);
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
