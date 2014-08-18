#ifndef POMODORO_H
#define POMODORO_H

class Pomodoro
{
public:
    typedef enum {
           POMODORO,
           SHORT_BREAK,
           LONG_BREAK
       } PomodoroEvent;

    long timeRemaining;
    PomodoroEvent pomodoroEvent;

    Pomodoro();
    Pomodoro(long timeRemaining, PomodoroEvent pomodoroEvent);
};

#endif // POMODORO_H
