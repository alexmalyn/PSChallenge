#include <QApplication>
#include "mainwindow.h"
#include "imagetransformer.h"
#include "colorspaceimage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    try {
        if (argc != 2)
            throw "Incorrect argument count.\n";
    }  catch (const char* e) {
        fprintf(stderr, "%s", e);
        exit(1);
    }

    ImageTransformer* _Transformer = new ImageTransformer();

    ColorspaceImage* _RGBImage = new ColorspaceImage(argv[1]);
    ColorspaceImage* _YUVImage = _Transformer->convertRGBToYUV(*_RGBImage);
    _Transformer->adjustSatYUV(*_YUVImage);
    _RGBImage = _Transformer->convertYUVToRGB(*_YUVImage);
    _RGBImage->saveImage();

    delete _RGBImage;
    delete _YUVImage;
    delete _Transformer;

    return 0;
}
