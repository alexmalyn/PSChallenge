#include <QCoreApplication>
#include <iostream>

#include "imagetransformer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << argv;

    ImageTransformer* mTransformer = new ImageTransformer(argv);

    delete mTransformer;

    return a.exec();
}
