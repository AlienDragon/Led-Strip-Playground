#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QComboBox;
class QPushButton;
class QBoxLayout;
QT_END_NAMESPACE

#include "strip.h"
#include "wave.h"


class Window : public QWidget
{
    Q_OBJECT
public:
    Window();

private:
    Strip *ledStrip;
    Wave *testWave;
    QPushButton *drawBtn;
    //QBoxLayout *mainLayout;
    //QTimer *timer;
private:
    void repaintStrip();

};

#endif // WINDOW_H
