#include <vector>
#include "imagetransformer.h"

using namespace cv;

ImageTransformer::ImageTransformer()
{
    std::cout << "Transformer initialized." << std::endl;
}

//Colorspace conversions involving YUV are performed formulaically using PAL/NTSC standards
//while colorspace conversions involving HSV are performed using openCV's cvtColor() function.
//These are not used in the GUI version.

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

ColorspaceImage* ImageTransformer::convertAnything(ColorspaceImage& src, const ColorConversionCodes code)
{
    ColorspaceImage* result = new ColorspaceImage();

    Mat convertedImage;
    std::vector<Mat> channels;
    cvtColor(src.getImage(), convertedImage, code);
    split(convertedImage, channels);

    result->setImage(convertedImage);
    result->setChannels(channels);

    return result;
}

void ImageTransformer::adjustSatYUV(ColorspaceImage &src, const int satAdjustment)
{
    ColorspaceImage localRGB = *convertAnything(src, COLOR_YUV2RGB);
    ColorspaceImage localHSV = *convertAnything(localRGB, COLOR_RGB2HSV);

    std::vector<Mat> HSVChannels = localHSV.getChannels();
    Mat newImage;

    HSVChannels[1] *= satAdjustment / 50.0;
    merge(HSVChannels, newImage);

    localHSV.setChannels(HSVChannels);
    localHSV.setImage(newImage);

    localRGB = *convertAnything(localHSV, COLOR_HSV2RGB);
    src = *convertAnything(localRGB, COLOR_RGB2YUV);

    //std::cout << "Saturation adjustments applied." << std::endl;
}

//manual YUV conversions not working for QImage purposes.
//void ImageTransformer::adjustSatYUV(ColorspaceImage& src, const int satAdjustment)
//{
//    ColorspaceImage localRGB = *convertYUVToRGB(src);
//    ColorspaceImage localHSV = *convertRGBToHSV(localRGB);

//    std::vector<Mat> HSVChannels = localHSV.getChannels();
//    Mat newImage;

//    //HSVChannels[1] = satAdjustment / 100 * 100;
//    merge(HSVChannels, newImage);

//    localHSV.setChannels(HSVChannels);
//    localHSV.setImage(newImage);

//    localRGB = *convertHSVToRGB(localHSV);
//    src = *convertRGBToYUV(localRGB);

//    std::cout << "Saturation adjustments applied." << std::endl;
//}



ImageTransformer::~ImageTransformer()
{

}
