#include <iostream>
#include <stdexcept>
#include <vector>

#include "imagetransformer.h"

using namespace cv;

ImageTransformer::ImageTransformer()
{
    std::cout << "Transformer initialized." << std::endl;
}

ColorspaceImage* ImageTransformer::convertRGBToYUV(ColorspaceImage& src)
{
    std::vector<Mat> channels = src.getChannels();
    ColorspaceImage* result = new ColorspaceImage();
    Mat mergedImage;

    Mat R = channels[0].clone();
    Mat G = channels[1].clone();
    Mat B = channels[2].clone();

    //Y
    channels[0] = Wr*R + Wg*G + Wb*B;
    Mat Y = channels[0];
    //U
    channels[1] = Umax * ((B - Y) / (1 - Wb));
    //V
    channels[2] = Vmax * ((R - Y) / (1 - Wr));

    merge(channels, mergedImage);
    result->setChannels(channels);
    result->setImage(mergedImage);

    //std::cout << "Done converting RGB to YUV." << std::endl;
    return result;
}

ColorspaceImage* ImageTransformer::convertYUVToRGB(ColorspaceImage& src)
{
    std::vector<Mat> channels = src.getChannels();
    ColorspaceImage* result = new ColorspaceImage();
    Mat mergedImage;

    Mat Y = channels[0].clone();
    Mat U = channels[1].clone();
    Mat V = channels[2].clone();

    //R
    channels[0] = Y + 1.14 * V;
    //G
    channels[1] = Y - 0.395 * U - 0.581 * V;
    //B
    channels[2] = Y + 2.033 * U;

    merge(channels, mergedImage);
    result->setChannels(channels);
    result->setImage(mergedImage);

    //std::cout << "Done converting YUV to RGB." << std::endl;
    return result;
}

ColorspaceImage* ImageTransformer::convertRGBToHSV(ColorspaceImage& src)
{
    ColorspaceImage* result = new ColorspaceImage();

    Mat convertedImage;
    std::vector<Mat> channels;
    cvtColor(src.getImage(), convertedImage, COLOR_RGB2HSV);
    split(convertedImage, channels);

    result->setImage(convertedImage);
    result->setChannels(channels);

    //std::cout << "Done converting RGB to HSV." << std::endl;
    return result;
}

ColorspaceImage* ImageTransformer::convertHSVToRGB(ColorspaceImage& src)
{
    ColorspaceImage* result = new ColorspaceImage();

    Mat convertedImage;
    std::vector<Mat> channels;
    cvtColor(src.getImage(), convertedImage, COLOR_HSV2RGB);
    split(convertedImage, channels);

    result->setImage(convertedImage);
    result->setChannels(channels);

    //std::cout << "Done converting HSV to RGB." << std::endl;
    return result;
}

void ImageTransformer::adjustSatYUV(ColorspaceImage& src)
{
    do {
        std::cout << "Enter a saturation value >= 0%" << std::endl;
        std::cin >> satAdjustment;
    } while(satAdjustment < 0);

    ColorspaceImage localRGB = *convertYUVToRGB(src);
    ColorspaceImage localHSV = *convertRGBToHSV(localRGB);

    std::vector<Mat> HSVChannels = localHSV.getChannels();
    Mat newImage;

    HSVChannels[1] *= satAdjustment / 100;
    merge(HSVChannels, newImage);

    localHSV.setChannels(HSVChannels);
    localHSV.setImage(newImage);

    localRGB = *convertHSVToRGB(localHSV);
    src = *convertRGBToYUV(localRGB);

    std::cout << "Saturation adjustments applied." << std::endl;
}

ImageTransformer::~ImageTransformer()
{

}
