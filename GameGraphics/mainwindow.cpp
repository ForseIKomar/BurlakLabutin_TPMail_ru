#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int scaling = 50;

    if (scaling > 120)
        scaling = 120;

    ui->graphicsView->setGeometry(0, 0, scaling * 8 + 2, scaling * 8 + 2);

    scene = new Graphics();
    scene->setScaling(scaling);
    scene->setLabel(ui->label);
    scene->setSceneRect(0, 0, scaling * 8, scaling * 8);
    scene->generateNewGraphics();

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
