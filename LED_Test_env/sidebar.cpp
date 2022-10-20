#include "sidebar.h"
#include <QPushButton>


Sidebar::Sidebar(QWidget *parent)
    : QWidget{parent}
{
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::black);
    //pal.setColor(QPalette::Button, Qt::green);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    layout = new QVBoxLayout(this);
    setLayout(layout);

    QPushButton *btn = new QPushButton(this);
    layout->addWidget(btn);


}


QSize Sidebar::minimumSizeHint()const
{
    return QSize(20, 100);
}
