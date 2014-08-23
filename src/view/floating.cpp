#include <QtGui>
#include <iostream>
#include "floating.h"
#include "ui_floating.h"
#include "src/format.h"
#include "src/model/config.h"

#define limit_value(v, _min, _max) (v<_min?_min:v>_max?_max:v)

Floating::Floating(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Floating)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);

    checkScreenLimits();
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
    if (event->buttons() == Qt::LeftButton) {
        event->accept();
        dragPos = event->pos();
        checkScreenLimits();
    } else {
        event->ignore();
    }
}

void Floating::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton)
    {
        event->accept();
        this->move(calculateNewPosition(event->globalPos() - dragPos));
    } else {
        event->ignore();
    }
}

void Floating::contextMenuEvent(QContextMenuEvent *event) {
    contextMenu->move(calculateMenuPosition(event));
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
    c->widgetPosition = (this->pos());
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

void Floating::checkScreenLimits()
{
    screenLimits = QApplication::desktop()->availableGeometry();
    QPoint size(geometry().size().width(), geometry().size().height());

    screenLimits.setBottomRight(screenLimits.bottomRight() - size);

#ifdef DEBUG
    std::cout << "Limits: " << screenLimits.x();
    std::cout << "," << screenLimits.y();
    std::cout << "," << screenLimits.width();
    std::cout << "," << screenLimits.height() << std::endl;
#endif
}

QPoint Floating::calculateNewPosition(QPoint requestedPos)
{
    QPoint adjustedPos;

    adjustedPos.setX(limit_value(requestedPos.x(),screenLimits.x(), screenLimits.bottomRight().x()));
    adjustedPos.setY(limit_value(requestedPos.y(),screenLimits.y(), screenLimits.bottomRight().y()));

#ifdef DEBUG
    std::cout << requestedPos.x() << "," << requestedPos.y();
    std::cout << " => ";
    std::cout << adjustedPos.x() << "," << adjustedPos.y() << std::endl;
#endif

    return adjustedPos;
}

QPoint Floating::calculateMenuPosition(QContextMenuEvent *event)
{
    return event->globalPos();
}
