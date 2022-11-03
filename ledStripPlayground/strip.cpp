#include "strip.h"
#include <QPainter>

Strip::Strip(int ledCount, QObject *parent)
    : QObject{parent}
{
    ledStrip = QList<led>(ledCount);
    mLedStrip = QList<led>(ledCount);
}


void Strip::resetStrip()
{
    for(int i = 0; i < ledStrip.length(); i++)
    {
        mLedStrip[i].r = ledStrip[i].r;
        mLedStrip[i].b = ledStrip[i].b;
        mLedStrip[i].g = ledStrip[i].g;
    }
}

void Strip::setStripTo(QColor stripCol)
{
    for(int i = 0; i < ledStrip.length(); i++)
    {
        ledStrip[i].r = stripCol.red();
        ledStrip[i].b = stripCol.blue();
        ledStrip[i].g = stripCol.green();
    }
}
