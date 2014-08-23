#include "menu.h"

Menu::Menu(QWidget *parent) :
    QMenu(parent)
{
    pauseResumeAction = new QAction(tr("Pause/Resume"), this);
    this->addAction(pauseResumeAction);

    this->addSeparator();

    startPomodoroAction = new QAction(tr("Start Pomodoro"), this);
    this->addAction(startPomodoroAction);

    startShortBreakAction = new QAction(tr("Start Short Break"), this);
    this->addAction(startShortBreakAction);

    startLongBreakAction = new QAction(tr("Start Long Break"), this);
    this->addAction(startLongBreakAction);

    this->addSeparator();

/* TODO: Novos Modos
    configureAction = new QAction(tr("Configure..."), this);
    this->addAction(configureAction);

    this->addSeparator();
*/
    quitAction = new QAction(tr("Quit"), this);
    this->addAction(quitAction);
    connect(quitAction, SIGNAL(triggered()), parent, SLOT(close()));

}

void Menu::setConfigDialog(ConfigDialog * c)
{
    configDialog = c;
    //connect(configureAction, SIGNAL(triggered()), configDialog, SLOT(show()));
}

void Menu::setPomodoroStatus(PomodoroStatus * p)
{
    pomodoroStatus = p;
    connect(pauseResumeAction, SIGNAL(triggered()), pomodoroStatus, SLOT(onOff()));
    connect(startPomodoroAction, SIGNAL(triggered()), pomodoroStatus, SLOT(startPomodoro()));
    connect(startShortBreakAction, SIGNAL(triggered()), pomodoroStatus, SLOT(startShortBreak()));
    connect(startLongBreakAction, SIGNAL(triggered()), pomodoroStatus, SLOT(startLongBreak()));
}
