#ifndef MENU_H
#define MENU_H

#include <QMenu>
#include "src/view/configdialog.h"
#include "src/model/pomodorostatus.h"
#include "src/view/about.h"

class Menu : public QMenu
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = 0);
    void setConfigDialog(ConfigDialog *);
    void setPomodoroStatus(PomodoroStatus *);
    void setAboutDialog(About *);

public slots:


private:
    QAction *pauseResumeAction;
    QAction *startPomodoroAction;
    QAction *startShortBreakAction;
    QAction *startLongBreakAction;
    QAction *configureAction;
    QAction *aboutAction;
    QAction *quitAction;

    ConfigDialog * configDialog;
    PomodoroStatus * pomodoroStatus;
    About * aboutDialog;
};

#endif // MENU_H
