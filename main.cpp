#include <QCoreApplication>
#include <iostream>

#include "imagetransformer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try {
        if (argc != 2)
            throw "Incorrect argument count.\n";
    }  catch (const char* e) {
        fprintf(stderr, "%s", e);
        exit(1);
    }

    ImageTransformer* mTransformer = new ImageTransformer(argv[1]);


    //mTransformer->adjustSatRGB();
    //mTransformer->showOriginalChannels();
    mTransformer->convertRGBToYCbCr();
    mTransformer->adjustSatYCbCr();
    mTransformer->convertYCbCrToRGB();
    mTransformer->showImage();

    delete mTransformer;

    return a.exec();
}
