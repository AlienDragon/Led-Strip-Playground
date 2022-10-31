#ifndef STRIP_H
#define STRIP_H

#include <QObject>


struct led{
    int r = 255,
        g = 255,
        b = 255;    //These values should never exceed 255 -MUST WRITE PROTECTION METHODS-

};

class Strip : public QObject
{
    Q_OBJECT
public:
    explicit Strip(int ledCount, QObject *parent = nullptr);
    QList<led> ledStrip;
    void resetStrip();  //Sets all LEDs to White
    void setStripTo(QColor stripCol);
    int getMaxLeds(){ return ledStrip.length(); }

signals:

};

#endif // STRIP_H
