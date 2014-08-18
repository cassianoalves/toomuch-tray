#include "format.h"

Format::Format()
{
}

std::string Format::formatTime(long time) {
    char fmt[6];
    sprintf(fmt, "%02ld:%02ld", (time / 60), (time % 60));
    return std::string(fmt);
}

std::string Format::formatEvent(Pomodoro::PomodoroEvent event) {
    const char * eventName = "";
    switch(event) {
        case Pomodoro::LONG_BREAK:
            eventName = "Long Break";
            break;
        case Pomodoro::SHORT_BREAK:
            eventName = "Short Break";
            break;
        case Pomodoro::POMODORO:
            eventName = "Pomodoro";
            break;
    }

    return std::string(eventName);
}
