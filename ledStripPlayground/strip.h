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
    QList<led> mLedStrip; //modified by any animations applied to it
    void resetStrip();  //Sets all LEDs to White
    void setStripTo(QColor stripCol);
    int getMaxLeds(){ return ledStrip.length(); }

private:
    QList<led> ledStrip;        //maintains original colours unless changed by the user. Also used for resetting of strip each frame
signals:

};

#endif // STRIP_H
