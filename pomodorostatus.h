#ifndef POMODOROSTATUS_H
#define POMODOROSTATUS_H
#include <string>

using namespace std;

class PomodoroStatus
{
public:
    typedef enum {
        POMODORO,
        SHORT_BREAK,
        LONG_BREAK
    } PomodoroEvent;

    long timeRemaining;
    PomodoroEvent pomodoroEvent;

    PomodoroStatus();
    PomodoroStatus(long timeRemaining, PomodoroEvent pomodoroEvent);
    string toString();
};

#endif // POMODOROSTATUS_H
