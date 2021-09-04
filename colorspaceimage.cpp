#include <vector>
#include <string>
#include "colorspaceimage.h"
using namespace cv;

ColorspaceImage::ColorspaceImage(char* filepath)
{
    std::cout << "In ColorspaceImage constructor, filename: " << filepath << std::endl;
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
}

void ColorspaceImage::saveImage()
{
    std::cout << "Would you like to save your adjustments? [y/n]?" << std::endl;
    char ans;
    bool result = false;
    std::cin >> ans;
    if (ans == 'y' || ans == 'Y')
    {
        Mat img = getImage();
        img.convertTo(img,CV_8U);

        std::string location;

        do {
            std::cout << "Specify a full path to the file with the extension.\n" \
                        "Type 'exit' at any time to continue without saving." \
                        << std::endl;
            std::cin >> location;
            if (location == "exit")
                break;
            try {
                result = imwrite(location,img);
            }  catch (const Exception& ex) {
                fprintf(stderr, "Something went wrong saving the file.\n\n");
            }
        } while(result == false);
    }
    if (result == true)
        std::cout << "Image saved. Goodbye." << std::endl;
    else
        std::cout << "Goodbye." << std::endl;
}

void ColorspaceImage::showImage() const
{
    Mat tempImg;
    Image.convertTo(tempImg, CV_8U);
    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image",tempImg);
    std::cout << "Image Displayed." << std::endl;
}

//void ColorspaceImage::operator=(const ColorspaceImage& src)
//{
//    this->Image = src.Image.clone();
//    this->ImageChannels = src.ImageChannels;
//}

std::vector<Mat> ColorspaceImage::getChannels() const
{
    return ImageChannels;
}

Mat ColorspaceImage::getImage() const
{
    return Image;
}

void ColorspaceImage::setChannels(std::vector<Mat> &src)
{
    this->ImageChannels = src;
}

void ColorspaceImage::setImage(cv::Mat &src)
{
    this->Image = src;
}

ColorspaceImage::~ColorspaceImage()
{

}
