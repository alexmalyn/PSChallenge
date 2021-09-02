#ifndef IMAGETRANSFORMER_H
#define IMAGETRANSFORMER_H
#include <stdio.h>
#include <string>
#include <opencv4/opencv2/opencv.hpp>

class ImageTransformer
{
    cv::Mat image;

public:
    ImageTransformer( char* filepath);
    ~ImageTransformer();



};

#endif // IMAGETRANSFORMER_H
