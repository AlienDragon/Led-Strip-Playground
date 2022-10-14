#include "window.h"

#include <QtWidgets>

Window::Window()
{

    ledStrip = new Strip(24);
    ledStrip->setStripTo(QColor(255, 0, 0));

    testWave = new Wave(500, ledStrip);

    testWave2 = new Wave(800, ledStrip);

    drawBtn = new QPushButton(this);
    drawBtn->setText("Start Test Wave");

    stopBtn = new QPushButton(this);
    stopBtn->setText("Stop Test Wave");

    connect(drawBtn, &QPushButton::clicked, testWave, QOverload<>::of(&Wave::startWave));
    connect(drawBtn, &QPushButton::clicked, testWave2, QOverload<>::of(&Wave::startWave));
    connect(stopBtn, &QPushButton::clicked, testWave, QOverload<>::of(&Wave::stopWave));

    QBoxLayout *main = new QBoxLayout(QBoxLayout::LeftToRight);
    main->addWidget(ledStrip);
    main->addWidget(drawBtn);
    main->addWidget(stopBtn);

    setLayout(main);
    setWindowTitle(tr("Led Strip Simulator"));
}
