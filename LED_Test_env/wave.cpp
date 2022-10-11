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
    //int midPoint = (width + 2 - 1)/2;   //Ceiling
    removeTrail();      //reset strip

    if(ledIndex-width < leds->getMaxLeds())
    {
        ledIndex++;
    }
    else
    {
        ledIndex=0;
    }

    for(int i = ledIndex-width; i < ledIndex+width; i++)
    {
        if(i >= 0 && i < leds->getMaxLeds())
        {
            int newR = leds->ledStrip[i].r * reduction;
            int newG = leds->ledStrip[i].g * reduction;
            int newB = leds->ledStrip[i].b * reduction;

            leds->setLed(i, newR, newG, newB);

         }
    }

    leds->update();
}

void Wave::removeTrail()
{
    //int midPoint = (width + 2 - 1)/2;   //Ceiling
    //int trailIndex = ledIndex - width;

    for(int i = ledIndex - width; i  < ledIndex+width; i++)
    {
        if(i >= 0 && i < leds->getMaxLeds())
        {
            int newR = leds->ledStrip[i].r / reduction;
            int newG = leds->ledStrip[i].g / reduction;
            int newB = leds->ledStrip[i].b / reduction;

            leds->setLed(i, newR, newG, newB);
        }
    }
}
