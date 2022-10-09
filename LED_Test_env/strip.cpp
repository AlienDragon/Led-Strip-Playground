#include "strip.h"
#include <QPainter>
#include <QTimer>
strip::strip(int maxLed, QWidget *parent)
    : QWidget(parent)
{
    numLeds = maxLed;
    ledStrip = QList<led>(numLeds);
}

QSize strip::minimumSizeHint()const{
    return QSize(100, 100);
}

QSize strip::sizeHint() const
{
    return QSize(400, 200);
}

void strip::paintEvent(QPaintEvent *event){

    QRect rect(5,5,10,10);

    QPainter painter(this);

    // --Testing-- Subtract 25 from R value every repaint
    //if(ledStrip[0].r-25 >= 0){
    //    ledStrip[0].r -= 25;
    //}

    for(int i =0; i < numLeds-1; i++){
        painter.setBrush(QColor(ledStrip[i].r,
                                ledStrip[i].g,
                                ledStrip[i].b));
        painter.translate(15, 0);
        painter.drawRect(rect);
    }


    //Calls this paint event repetedly
    //this->update();
}
