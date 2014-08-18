#ifndef FORMAT_H
#define FORMAT_H
#include <string>
#include "src/model/pomodoro.h"


class Format
{
public:
    Format();
    static std::string formatTime(long time);
    static std::string formatEvent(Pomodoro::PomodoroEvent event);
};

#endif // FORMAT_H
