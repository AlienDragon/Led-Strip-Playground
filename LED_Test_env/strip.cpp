#include "strip.h"
#include <QPainter>
#include <QTimer>
Strip::Strip(int maxLed, QWidget *parent)
    : QWidget(parent)
{
    numLeds = maxLed;
    ledStrip = QList<led>(numLeds);
}

QSize Strip::minimumSizeHint()const{
    return QSize(100, 100);
}

QSize Strip::sizeHint() const
{
    return QSize(400, 200);
}

void Strip::resetStrip(){

}

void Strip::paintEvent(QPaintEvent *event){

    QRect rect(startCoord.x(),startCoord.y(),
               startCoord.x() + ledWidth,
               startCoord.y() + ledHeight);

    QPainter painter(this);

    // --Testing-- Subtract 25 from R value every repaint
    //if(ledStrip[0].r-25 >= 0){
    //    ledStrip[0].r -= 25;
    //}

    for(int i =0; i < numLeds-1; i++){
        painter.setBrush(QColor(ledStrip[i].r,
                                ledStrip[i].g,
                                ledStrip[i].b));
        painter.translate(ledXSpaceOffset, 0);
        painter.drawRect(rect);
    }


    //Calls this paint event repetedly
    //this->update();
}
