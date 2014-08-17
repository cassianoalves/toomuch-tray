#ifndef TICKER_H
#define TICKER_H

#include <QObject>
#include "pomodorostatus.h"

class Ticker : public QObject
{
    Q_OBJECT
public:
    explicit Ticker(QObject *parent = 0);

signals:
    PomodoroStatus changed();


public slots:
    void tick();

};

#endif // TICKER_H
