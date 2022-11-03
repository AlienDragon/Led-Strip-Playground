#ifndef STRIPVIEWER_H
#define STRIPVIEWER_H

#include <QWidget>
#include "strip.h"
class StripViewer : public QWidget
{
    Q_OBJECT
public:
    explicit StripViewer(int x, int y, QWidget *parent = nullptr);

signals:


private:
    Strip *leds;
};

#endif // STRIPVIEWER_H
