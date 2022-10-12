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
    int ledIndex = 0;
    int timerInterval = 0;
    Strip *leds;

    int width = 1;         //Total area of the strip will be affected
    float reduction = 0.5; //The 'depth' of the wave 0-1 -> 0%(Off) to 100%(No change to light)

    void removeTrail();
};

#endif // WAVE_H
