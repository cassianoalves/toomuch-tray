#ifndef MENU_H
#define MENU_H

#include <QMenu>
#include "src/view/configdialog.h"
#include "src/model/pomodorostatus.h"

class Menu : public QMenu
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = 0);
    void setConfigDialog(ConfigDialog *);
    void setPomodoroStatus(PomodoroStatus *);

public slots:


private:
    QAction *pauseResumeAction;
    QAction *startPomodoroAction;
    QAction *startShortBreakAction;
    QAction *startLongBreakAction;
    QAction *configureAction;
    QAction *quitAction;

    ConfigDialog * configDialog;
    PomodoroStatus * pomodoroStatus;
};

#endif // MENU_H
