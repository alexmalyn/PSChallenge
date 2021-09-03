#ifndef IMAGETRANSFORMER_H
#define IMAGETRANSFORMER_H
#include <stdio.h>
#include <string>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core/mat.hpp>

class ImageTransformer
{
    //never modified, only initialized
    cv::Mat Image;
    cv::Mat ImageChannels[3];

    cv::Mat transformedImage;
    cv::Mat transformedImageChannels[3];

    //constants defined by PAL/NTSC standards
    double Wr = 0.299;
    double Wb = 0.114;
    double Wg = 0.587;
    double Umax = 0.436;
    double Vmax = 0.615;

    double satAdjustment;

    void adjustSatRGB();

public:
    ImageTransformer( char* filepath);
    ~ImageTransformer();

    void showImage() const;
    void showOriginalChannels() const;
    void showTransformedChannels() const;
    void reset(); //reset transformedImage to original Image
    void save();

    void convertRGBToYCbCr();

    void adjustSatYCbCr();
    void convertYCbCrToRGB();


};

#endif // IMAGETRANSFORMER_H
