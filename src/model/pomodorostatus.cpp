#include <QTimer>

#include "pomodorostatus.h"


PomodoroStatus::PomodoroStatus(QObject *parent) :
    QObject(parent)
{
    init();
}

void PomodoroStatus::init()
{
    status.timeRemaining = 25 * MINUTES;
    status.pomodoroEvent = Pomodoro::POMODORO;
    activate = false;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer->start(1000);

    activate=false;
}

void PomodoroStatus::tick()
{
    if (activate && status.timeRemaining > 0)
    {
        status.timeRemaining--;
        if (status.timeRemaining == 0)
        {
            emit alarm(status.pomodoroEvent);
        }
    }

    emit changed(status);
}

long PomodoroStatus::getTimeByEvent(Pomodoro::PomodoroEvent e)
{
    switch(e)
    {
        case Pomodoro::LONG_BREAK:
            return LONG_BREAK_TIME;
        case Pomodoro::SHORT_BREAK:
            return SHORT_BREAK_TIME;
        case Pomodoro::POMODORO:
            return POMODORO_TIME;
    }
    return 0;
}


void PomodoroStatus::start(Pomodoro::PomodoroEvent event, long time)
{
    status.timeRemaining = time;
    status.pomodoroEvent = event;
    activate = true;
}

void PomodoroStatus::start(Pomodoro::PomodoroEvent event)
{
    start(event, getTimeByEvent(event));
}

void PomodoroStatus::reset(Pomodoro::PomodoroEvent event, long time)
{
    activate = false;
    status.timeRemaining = time;
    status.pomodoroEvent = event;
}

void PomodoroStatus::reset(Pomodoro::PomodoroEvent event)
{
    reset(event, getTimeByEvent(event));
}

void PomodoroStatus::onOff()
{
    activate = !activate;
}

void PomodoroStatus::startPomodoro()
{
    start(Pomodoro::POMODORO);
}

void PomodoroStatus::startShortBreak()
{
    start(Pomodoro::SHORT_BREAK);
}

void PomodoroStatus::startLongBreak()
{
    start(Pomodoro::LONG_BREAK);
}

