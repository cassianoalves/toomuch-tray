#include <iostream>
#include <curl/curl.h>
#include <boost/regex.hpp>
#include "tomatoidao.h"

#define TOMATOI_URL "http://tomatoi.st"


TomatoiDAO::TomatoiDAO()
{
}

Pomodoro TomatoiDAO::getStatus(std::string parameter)
{
    Pomodoro status;
    std::string url = TOMATOI_URL "/";
    url += parameter;
    std::string body = getBody(url.c_str());


    boost::regex expr("tickTock\\('(.*)','(.*)'\\)");
    boost::cmatch what;

    if(boost::regex_search(body.c_str(),what,expr))
    {
        status.timeRemaining = atol(what[2].str().c_str());
        status.pomodoroEvent = str2Event(what[1].str());
    }
    else
    {
        status.timeRemaining = 0;
        status.pomodoroEvent = Pomodoro::POMODORO;
    }

    return status;
}

Pomodoro::PomodoroEvent TomatoiDAO::str2Event(std::string s)
{
    if (strcmp(s.c_str(), "Pomodoro") == 0) return Pomodoro::POMODORO;
    if (strcmp(s.c_str(), "Long Break") == 0) return Pomodoro::LONG_BREAK;
    if (strcmp(s.c_str(), "Short Break") == 0) return Pomodoro::SHORT_BREAK;
}

std::list<Pomodoro> TomatoiDAO::getHistory(std::string parameter)
{
    std::list<Pomodoro> history;
    return history;
}

void TomatoiDAO::startPomodoro(std::string parameter) {}
void TomatoiDAO::startShortBreak(std::string parameter) {}
void TomatoiDAO::startLongBreak(std::string parameter) {}

std::string TomatoiDAO::getBody(const char *url) {
    std::string body = " $(function(){\n "
            "tickTock('Pomodoro','1489');\n"
          "});";

    return body;

}
