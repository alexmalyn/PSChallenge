#include <iostream>
#include <stdexcept>

#include "imagetransformer.h"

using namespace cv;

ImageTransformer::ImageTransformer( char* filepath)
{
    std::cout << "In constructor, filename: " << filepath << std::endl;
    try {
        Image = imread(filepath, IMREAD_COLOR); //converted to BGR
        if (Image.empty())
            throw "Image could not be read. Adjust path or use a different image.\n";
    }  catch (const char* e) {
        fprintf(stderr,"%s",e);
        exit(1);
    }
    this->reset();
}

void ImageTransformer::show() const
{
    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image",transformedImage);
}

void ImageTransformer::reset()
{
    transformedImage = Image;
}

void ImageTransformer::save()
{

}

void ImageTransformer::convertToYCbCr()
{
    cvtColor(Image, transformedImage, COLOR_BGR2YUV);
}

void ImageTransformer::adjustSaturationYCbCr()
{
    split(transformedImage,transformedImageChannels);

}

void ImageTransformer::convertToRGB()
{

}


ImageTransformer::~ImageTransformer()
{
    std::cout << "Object deleted." << std::endl;
}
