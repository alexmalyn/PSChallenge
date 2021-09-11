#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QImage myImage;
    myImage.load("../assets/tiger.jpeg");
    ui->ImageDisplay->setPixmap(QPixmap::fromImage(myImage.scaledToHeight(510)));


}

MainWindow::~MainWindow()
{
    delete ui;
}
