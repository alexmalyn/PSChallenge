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

    double satAdjustment;

public:
    ImageTransformer( );
    ~ImageTransformer();

    void save();
    void adjustSatYUV(ColorspaceImage& src);

    ColorspaceImage* convertRGBToYUV(ColorspaceImage& src);
    ColorspaceImage* convertYUVToRGB(ColorspaceImage& src);
    ColorspaceImage* convertRGBToHSV(ColorspaceImage& src);
    ColorspaceImage* convertHSVToRGB(ColorspaceImage& src);

};

#endif // IMAGETRANSFORMER_H
