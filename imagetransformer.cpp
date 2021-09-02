#include <iostream>
#include <stdexcept>

#include "imagetransformer.h"

using namespace cv;

ImageTransformer::ImageTransformer( char* filepath)
{
    std::cout << "In constructor, filename: " << filepath << std::endl;
    try {
        image = imread(filepath, IMREAD_COLOR); //converted to BGR
        if (image.data == NULL)
            throw "Image could not be read. Adjust path or use a different image.\n";
    }  catch (const char* e) {
        fprintf(stderr,"%s",e);
        exit(1);
    }

}

ImageTransformer::~ImageTransformer()
{

}
