#ifndef POMODOROSTATUS_H
#define POMODOROSTATUS_H

#include <QObject>

#include "src/model/pomodoro.h"

class PomodoroStatus : public QObject
{
    Q_OBJECT
public:
    explicit PomodoroStatus(QObject *parent = 0);
    Pomodoro getStatus();

signals:
    void changed(Pomodoro current);
    void alarm(Pomodoro::PomodoroEvent event);

public slots:
    void tick();
    void startPomodoro();
    void startShortBreak();
    void startLongBreak();
    void start(Pomodoro::PomodoroEvent event);
    void start(Pomodoro::PomodoroEvent event, long time);
    void reset(Pomodoro::PomodoroEvent event);
    void reset(Pomodoro::PomodoroEvent event, long time);
    void onOff();



private:
    Pomodoro status;
    bool activate;
    void init();
    long getTimeByEvent(Pomodoro::PomodoroEvent);
};

#endif // POMODOROSTATUS_H
