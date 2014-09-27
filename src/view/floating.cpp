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
    QDesktopWidget *desktop = QApplication::desktop();
    screenLimits.clear();
    for (int i=0; i< desktop->screenCount(); i++)
    {
        QRect scr = QApplication::desktop()->availableGeometry(i);
        //QPoint size(geometry().size().width(), geometry().size().height());
        //scr.setBottomRight(scr.bottomRight() - size);

        screenLimits.push_back(scr);

#ifdef DEBUG
    std::cout << "Limits(" << i << "): " << scr.x();
    std::cout << "," << scr.y();
    std::cout << "," << scr.width();
    std::cout << "," << scr.height() << std::endl;
#endif
    }


}

/**
 * @brief Floating::whatScreenIsPoint
 * @param requested
 * @return Screen number stating at 0, -1 is outside any screen
 */
int Floating::whatScreenIsPoint(QPoint requested)
{
    int scrNumber = -1;

    for (std::size_t i=0; i < screenLimits.size(); i++) {
        QRect scr = screenLimits.at(i);
        if (scr.contains(requested))
        {
            scrNumber = i;
            break;
        }
    }
    return scrNumber;
}

QLine Floating::xLimitsForPoint(QPoint p)
{

}

QLine Floating::yLimitsForPoint(QPoint p)
{

}


QPoint Floating::calculateNewPosition(QPoint requestedPos)
{
    QPoint adjustedPos;
    QRect scr = screenLimits.back();

    adjustedPos.setX(limit_value(requestedPos.x(),xLimitsForPoint(requestedPos).p1().x(),
                                 xLimitsForPoint(requestedPos).p2().x()));
    adjustedPos.setY(limit_value(requestedPos.y(),xLimitsForPoint(requestedPos).p1().y(),
                                 xLimitsForPoint(requestedPos).p2().y()));

#ifdef DEBUG
    std::cout << whatScreenIsPoint(requestedPos) << " - ";
    std::cout << requestedPos.x() << "," << requestedPos.y();
    std::cout << " => ";
    std::cout << adjustedPos.x() << "," << adjustedPos.y();
    std::cout << std::endl;
#endif

    return adjustedPos;
}

QPoint Floating::calculateMenuPosition(QContextMenuEvent *event)
{
    return event->globalPos();
}
