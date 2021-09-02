#include <iostream>
#include "imagetransformer.h"

ImageTransformer::ImageTransformer( char* filename[])
{
    std::cout << "In constructor, filename: " << filename << std::endl;
//    std::cout << "ImageTransformer is running.\nPlease specify an image filename with the extension.\n";
//    std::cin >> filename;
//    std::cout << filename << std::endl;

}

ImageTransformer::~ImageTransformer()
{

}
