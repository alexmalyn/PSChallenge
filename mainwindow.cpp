#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    transformer(new ImageTransformer)
{
    ui->setupUi(this);
    img.load(":/assets/placeholder.png");
    ui->ImageDisplay->setPixmap(QPixmap::fromImage(img.scaledToHeight(510)));
    ui->SaveButton->setEnabled(false);
    ui->SatSlider->setEnabled(false);


    connect(ui->BrowseButton,&QPushButton::clicked, this, &MainWindow::openFile);
    connect(ui->SaveButton, &QPushButton::clicked, this, &MainWindow::saveFile);
    connect(ui->SatSlider, &QSlider::valueChanged, this, &MainWindow::satChanged);

}

MainWindow::~MainWindow()
{
    delete transformer;
    delete ui;
}

void MainWindow::satChanged()
{
    ui->SatValLabel->setText(QString(QString::number(ui->SatSlider->value()) + "%"));

    NewYUVImage = *OriginalYUVImage;
    transformer->adjustSatYUV(NewYUVImage, ui->SatSlider->value());
    NewRGBImage = *transformer->convertAnything(NewYUVImage, cv::COLOR_YUV2RGB);

    cv::Mat tempImg;
    NewRGBImage.getImage().convertTo(tempImg, CV_8U);
    cvtColor(tempImg, tempImg, cv::COLOR_BGR2RGB);

    //NewRGBImage.asQImage() not working here, top half becomes black at every other sat change.
    ui->ImageDisplay->setPixmap(
                QPixmap::fromImage(
                    QImage((unsigned char*)tempImg.data,
                           tempImg.cols,
                           tempImg.rows,
                           QImage::Format_RGB888).scaledToHeight(510)));

}

void MainWindow::openFile()
{
    fileName = QFileDialog::getOpenFileName(this,
       tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.jpeg *.bmp *.tiff)"));
    if (fileName.isEmpty())
        return;

    initColorspaces();
    img.load(fileName);

    ui->SatSlider->setValue(50);
    ui->ImageDisplay->setPixmap(QPixmap::fromImage(img.scaledToHeight(510)));
    ui->filenameLineEdit->setText(fileName);
    ui->SaveButton->setEnabled(true);
    ui->SatSlider->setEnabled(true);
}

void MainWindow::initColorspaces()
{
    if (OriginalRGBImage != NULL)
    {
        delete OriginalRGBImage;
        delete OriginalYUVImage;
    }
    OriginalRGBImage = new ColorspaceImage(&fileName);
    OriginalYUVImage = transformer->convertRGBToYUV(*OriginalRGBImage);
}

void MainWindow::saveFile()
{
    savefileName = QFileDialog::getSaveFileName(this,
       tr("Save Image"), QString(), tr("Images (*.png *.jpg *.jpeg *.bmp *.tiff)"));
    if (!savefileName.isEmpty())
    {
        cv::Mat tempImg;
        NewRGBImage.getImage().convertTo(tempImg, CV_8U);
        cvtColor(tempImg, tempImg, cv::COLOR_BGR2RGB);

        img = QImage((unsigned char*)tempImg.data,
                     tempImg.cols,
                     tempImg.rows,
                     QImage::Format_RGB888);
        img.save(savefileName);
    }
}
