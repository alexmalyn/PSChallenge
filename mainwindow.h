#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtGui>
#include "imagetransformer.h"
#include "colorspaceimage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr );
    ~MainWindow();

    void initColorspaces();

private:
    Ui::MainWindow *ui;
    ImageTransformer* transformer;
    QString fileName, savefileName;
    QImage img;

    ColorspaceImage *OriginalRGBImage = NULL;
    ColorspaceImage NewRGBImage;
    ColorspaceImage *OriginalYUVImage = NULL;
    ColorspaceImage NewYUVImage;

private slots:
    void openFile();
    void saveFile();
    void satChanged();
};

#endif // MAINWINDOW_H
