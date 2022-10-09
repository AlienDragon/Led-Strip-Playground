#ifndef WAVE_H
#define WAVE_H

#include <QObject>
#include <QTimer>

#include "strip.h"

class Wave : public QObject
{
    Q_OBJECT
public:
    explicit Wave(int timerInterval, Strip *s, QObject *parent = nullptr);
    void startWave();
    void stopWave();
    void stepWave();

private:
    QTimer *testT;
    int ledIndex;
    int timerInterval;
    Strip *leds;
};

#endif // WAVE_H
