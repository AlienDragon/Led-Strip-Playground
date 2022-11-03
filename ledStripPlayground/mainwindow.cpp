#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view = new StripViewer(200, 200, this);
    this->layout()->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

