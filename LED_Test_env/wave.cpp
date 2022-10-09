#include "wave.h"

Wave::Wave(int tInterval, Strip *s,  QObject *parent)
    : QObject{parent}
{
    testT = new QTimer(this);
    leds = s;
    ledIndex = 0;
    timerInterval = tInterval;

    connect(testT, &QTimer::timeout, this,
        QOverload<>::of(&Wave::stepWave));
}


void Wave::startWave(){
    testT->start(timerInterval);
}

void Wave::stopWave(){
    testT->stop();
}

void Wave::stepWave(){
    if(ledIndex < leds->getMaxLeds()){
        ledIndex++;
        //Got this far
    }
}
