#ifndef POMODORO_H
#define POMODORO_H

#define MINUTES 60
#define POMODORO_TIME (25 * MINUTES)
#define SHORT_BREAK_TIME (5 * MINUTES)
#define LONG_BREAK_TIME (15 * MINUTES)

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
