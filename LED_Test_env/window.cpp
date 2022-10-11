#include "window.h"

#include <QtWidgets>

Window::Window()
{

    ledStrip = new Strip(24);
    ledStrip->setStripTo(QColor(255, 0, 0));

    testWave = new Wave(500, ledStrip);


    drawBtn = new QPushButton(this);
    drawBtn->setText("Start Test Wave");

    connect(drawBtn, &QPushButton::clicked, testWave, QOverload<>::of(&Wave::startWave));

    QBoxLayout *main = new QBoxLayout(QBoxLayout::LeftToRight);
    main->addWidget(ledStrip);
    main->addWidget(drawBtn);



    setLayout(main);
    setWindowTitle(tr("Led Strip Simulator"));
}
