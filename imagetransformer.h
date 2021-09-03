#ifndef IMAGETRANSFORMER_H
#define IMAGETRANSFORMER_H
#include <stdio.h>
#include <string>
#include <opencv4/opencv2/opencv.hpp>

class ImageTransformer
{
    //never modified, only initialized
    cv::Mat Image;

    //modified Image/Channels
    cv::Mat transformedImage;
    cv::Mat transformedImageChannels[3];

public:
    ImageTransformer( char* filepath);
    ~ImageTransformer();

    void show() const;
    void reset(); //reset transformedImage to original Image
    void save();

    void convertToYCbCr();
    void adjustSaturationYCbCr();
    void convertToRGB();


};

#endif // IMAGETRANSFORMER_H
