#include "window.h"

#include <QtWidgets>

Window::Window()
{
    ledStrip = new strip(100);
    //ledStrip->show();

    drawBtn = new QPushButton(this);
    drawBtn->setText("Testing alloooooo");

    connect(drawBtn, &QPushButton::clicked, this, QOverload<>::of(&strip::update));

    QBoxLayout *main = new QBoxLayout(QBoxLayout::LeftToRight);
    main->addWidget(ledStrip);
    main->addWidget(drawBtn);



    setLayout(main);
    setWindowTitle(tr("Led Strip Simulator"));


    //QTimer *timer = new QTimer(this);
    //timer->timeout();
    //QObject::connect(timer, &QTimer::timeout, this, ledStrip->repaint());
    //QObject::connect(timer, &QTimer::timeout,ledStrip->repaint());
    //connect(timer, &QTimer::timeout, this, ledStrip->update());
    //timer->start(1000);
}

void Window::repaintStrip(){
    ledStrip->repaint();
}
