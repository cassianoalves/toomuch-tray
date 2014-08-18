#ifndef FLOATING_H
#define FLOATING_H

#include <QWidget>
#include "src/model/pomodoro.h"

namespace Ui {
class Floating;
}

class Floating : public QWidget
{
    Q_OBJECT

public:
    explicit Floating(QWidget *parent = 0);
    ~Floating();

public slots:
    void updatePomodoro(Pomodoro status);

private:
    Ui::Floating *ui;
};

#endif // FLOATING_H
