#ifndef REMOTESTATUS_H
#define REMOTESTATUS_H

#include <string>
#include "src/model/pomodoro.h"

class RemoteStatusRepository
{
public:
    virtual ~RemoteStatusRepository() {}
    virtual Pomodoro getStatus(std::string parameter) = 0;
    virtual std::list<Pomodoro> getHistory(std::string parameter) = 0;
    virtual void startPomodoro(std::string parameter) = 0;
    virtual void startShortBreak(std::string parameter) = 0;
    virtual void startLongBreak(std::string parameter) = 0;
};

#endif // REMOTESTATUS_H
