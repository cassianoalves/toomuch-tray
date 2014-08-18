#include <string>
#include <stdio.h>
#include "src/model/pomodoro.h"

using namespace std;

string formatTime(long time) {
    char fmt[6];
    sprintf(fmt, "%02ld:%02ld", (time / 60), (time % 60));
    return string(fmt);
}



/*
string formatEvent(Pomodoro::PomodoroEvent event) {
    const char * eventStr = "";
    switch(event) {
        case Pomodoro::PomodoroEvent::POMODORO:
            eventStr = "Pomodoro";
            break;
    }

    return string(eventStr);
}

    /*
     * POMODORO,
           SHORT_BREAK,
           LONG_BREAK*/
