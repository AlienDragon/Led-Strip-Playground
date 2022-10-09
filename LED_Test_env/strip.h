#ifndef STRIP_H
#define STRIP_H

#include <QWidget>
#include <QBrush>
//#include <QPen>

struct led{
    int r = 255,
        g = 255,
        b = 255;    //These values should never exceed 255 -MUST WRITE PROTECTION METHODS-

};

class Strip : public QWidget
{
    Q_OBJECT
public:
    Strip(int maxLed, QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    void resetStrip();  //Sets all LEDs to White

    int getMaxLeds(){ return numLeds; }

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int numLeds;
    const int ledXSpaceOffset = 15;
    const int ledWidth = 5;
    const int ledHeight = 5;
    QPoint startCoord = QPoint(5, 5);
    QList<led> ledStrip;

};

#endif // STRIP_H
