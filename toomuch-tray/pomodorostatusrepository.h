#ifndef POMODOROSTATUSREPOSITORY_H
#define POMODOROSTATUSREPOSITORY_H

#include "pomodorostatus.h"

class PomodoroStatusRepository
{
public:
    PomodoroStatusRepository();
    virtual PomodoroStatus getStatus() = 0;
    virtual void startEvent(PomodoroStatus::PomodoroEvent event) = 0;
};

#endif // POMODOROSTATUSREPOSITORY_H
