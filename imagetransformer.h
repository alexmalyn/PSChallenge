#ifndef IMAGETRANSFORMER_H
#define IMAGETRANSFORMER_H
#include <opencv4/opencv2/opencv.hpp>
#include "colorspaceimage.h"

class ImageTransformer
{
    //constants defined by PAL/NTSC standards
    double Wr = 0.299;
    double Wb = 0.114;
    double Wg = 0.587;
    double Umax = 0.436;
    double Vmax = 0.615;

public:
    ImageTransformer( );
    ~ImageTransformer();

    void adjustSatYUV(ColorspaceImage& src, const int satAdjustment);

    ColorspaceImage* convertRGBToYUV(ColorspaceImage& src);
    ColorspaceImage* convertYUVToRGB(ColorspaceImage& src);
    ColorspaceImage* convertAnything(ColorspaceImage& src, const cv::ColorConversionCodes code);

};

#endif // IMAGETRANSFORMER_H
