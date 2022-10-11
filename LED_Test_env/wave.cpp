#include "wave.h"

Wave::Wave(int tInterval, Strip *s,  QObject *parent)
    : QObject{parent}
{
    testT = new QTimer(this);
    leds = s;
    timerInterval = tInterval;

    connect(testT, &QTimer::timeout, this,
        QOverload<>::of(&Wave::stepWave));
}


void Wave::startWave()
{
    testT->start(timerInterval);
}

void Wave::stopWave()
{
    testT->stop();
}

void Wave::stepWave()
{
    if(ledIndex < leds->getMaxLeds())
    {
        int newR = leds->ledStrip[ledIndex].r * reduction;
        int newG = leds->ledStrip[ledIndex].b * reduction;
        int newB = leds->ledStrip[ledIndex].g * reduction;

        leds->setLed(ledIndex, newR, newG, newB);

        removeTrail();

        leds->update();

        if(ledIndex+1 < leds->getMaxLeds())
        {
            ledIndex++;
        }
        else
        {
            ledIndex=0;
        }
    }
}

void Wave::removeTrail()
{
    int midPoint = (width + 2 - 1)/2;   //Ceiling
    int trailIndex = ledIndex - midPoint;
    if(trailIndex >= 0)
    {
        int newR = leds->ledStrip[ledIndex].r / reduction;
        int newG = leds->ledStrip[ledIndex].g / reduction;
        int newB = leds->ledStrip[ledIndex].b / reduction;

        leds->setLed(trailIndex, newR, newG, newB);
    }

    /*
    for(int i = trailIndex; i <= midPoint; i++)
    {
        if(i >= 0)
        {
            int newR = leds->ledStrip[ledIndex].r / reduction;
            int newG = leds->ledStrip[ledIndex].b / reduction;
            int newB = leds->ledStrip[ledIndex].g / reduction;

            leds->setLed(i, QColor(newR, newG, newB));
        }
    }*/
}
