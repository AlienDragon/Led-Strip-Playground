#include "stripviewer.h"

StripViewer::StripViewer(int x, int y, QWidget *parent)
    : QWidget{parent}
{

    this->move(x, y);

    QPalette pal = QPalette();

    // set black background
    // Qt::black / "#000000" / "black"
    pal.setColor(QPalette::Window, Qt::black);

    this->setAutoFillBackground(true);
    this->setPalette(pal);
    //this->show();
}
