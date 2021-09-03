#include <iostream>
#include <stdexcept>
#include <vector>

#include "imagetransformer.h"

using namespace cv;

ImageTransformer::ImageTransformer( char* filepath)
{
    std::cout << "In constructor, filename: " << filepath << std::endl;
    try {
        Image = imread(filepath, IMREAD_COLOR);
        if (Image.empty())
            throw "Image could not be read. Adjust path or use a different image.\n";
    }  catch (const char* e) {
        fprintf(stderr,"%s",e);
        exit(1);
    }

    Image.convertTo(Image,CV_32F);
    split(Image,ImageChannels);
    this->reset();
}

void ImageTransformer::reset()
{
    transformedImage = Image;
    for (int i = 0; i < 3; ++i)
        transformedImageChannels[i] = ImageChannels[i];
}

void ImageTransformer::showImage() const
{
    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image",transformedImage);
}

void ImageTransformer::showOriginalChannels() const
{
    namedWindow("Blue", WINDOW_AUTOSIZE);
    imshow("Blue",ImageChannels[0]);

    namedWindow("Green", WINDOW_AUTOSIZE);
    imshow("Green",ImageChannels[1]);

    namedWindow("Red", WINDOW_AUTOSIZE);
    imshow("Red",ImageChannels[2]);
}

void ImageTransformer::showTransformedChannels() const
{
    namedWindow("Blue", WINDOW_AUTOSIZE);
    imshow("Blue",transformedImageChannels[0]);

    namedWindow("Green", WINDOW_AUTOSIZE);
    imshow("Green",transformedImageChannels[1]);

    namedWindow("Red", WINDOW_AUTOSIZE);
    imshow("Red",transformedImageChannels[2]);
}

void ImageTransformer::save()
{
    merge(transformedImageChannels, 3, transformedImage);
    transformedImage.convertTo(transformedImage,CV_8U);
    imwrite("assets/saved.png",transformedImage);
}

void ImageTransformer::convertRGBToYCbCr()
{
//    cvtColor(transformedImage, transformedImage, COLOR_BGR2YUV);
//    split(transformedImage, transformedImageChannels);

//    double minVal;
//    double maxVal;
//    Point minLoc;
//    Point maxLoc;

//    minMaxLoc( ImageChannels[2], &minVal, &maxVal, &minLoc, &maxLoc );

//    std::cout << "min val: " << minVal << std::endl;
//    std::cout << "max val: " << maxVal << std::endl;


    Mat R = transformedImageChannels[0].clone();
    Mat G = transformedImageChannels[1].clone();
    Mat B = transformedImageChannels[2].clone();

    //Y'
    transformedImageChannels[0] = Wr*R + Wg*G + Wb*B;
    Mat Y = transformedImageChannels[0];
    //U
    transformedImageChannels[1] = Umax * ((B - Y) / (1 - Wb));
    //V
    transformedImageChannels[2] = Vmax * ((R - Y) / (1 - Wr));

    std::cout << "Done converting to Y U V channels" << std::endl;

}

void ImageTransformer::convertYCbCrToRGB()
{
//    cvtColor(transformedImage,transformedImage, COLOR_YUV2BGR);

    Mat Y = transformedImageChannels[0].clone();
    Mat U = transformedImageChannels[1].clone();
    Mat V = transformedImageChannels[2].clone();

    //R
    transformedImageChannels[0] = Y + 1.14 * V;
    //G
    transformedImageChannels[1] = Y - 0.395 * U - 0.581 * V;
    //B
    transformedImageChannels[2] = Y + 2.033 * U;

    std::cout << "Done converting back to RGB." << std::endl;
}

void ImageTransformer::adjustSatYCbCr()
{

    do {
        std::cout << "Enter a saturation value >= 0%" << std::endl;
        std::cin >> satAdjustment;
    } while(satAdjustment < 0);

    //use original channels to calculate and adjust saturation in HSV space, and then
    //convert back into RGB and calculate new U,V

}

void ImageTransformer::adjustSatRGB()
{

    cvtColor(transformedImage, transformedImage, COLOR_RGB2HSV);
    Mat HSVChannels[3];
    split(transformedImage, HSVChannels);

    HSVChannels[1] =  HSVChannels[1] * (satAdjustment / 100);

    merge( HSVChannels, 3, transformedImage);
    cvtColor(transformedImage, transformedImage, COLOR_HSV2RGB);

    std::cout << "Saturation adjustment applied." << std::endl;

}


ImageTransformer::~ImageTransformer()
{
    std::cout << "Object deleted." << std::endl;
}
