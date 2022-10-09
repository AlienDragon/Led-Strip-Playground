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

class strip : public QWidget
{
    Q_OBJECT
public:
    strip(int maxLed, QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int numLeds;
    QList<led> ledStrip;

};

#endif // STRIP_H
