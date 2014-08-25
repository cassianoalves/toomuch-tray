#ifndef TOMATOIDAO_H
#define TOMATOIDAO_H

#include <string>
#include "src/repository/remotestatusrepository.h"

class TomatoiDAO : public RemoteStatusRepository
{
public:
    TomatoiDAO();
    Pomodoro getStatus(std::string parameter);
    std::list<Pomodoro> getHistory(std::string parameter);
    void startPomodoro(std::string parameter);
    void startShortBreak(std::string parameter);
    void startLongBreak(std::string parameter);

private:
    std::string getBody(const char * url);
    Pomodoro::PomodoroEvent str2Event(std::string);
};

#endif // TOMATOIDAO_H
