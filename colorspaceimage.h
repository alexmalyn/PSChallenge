#ifndef COLORSPACEIMAGE_H
#define COLORSPACEIMAGE_H
#include <opencv4/opencv2/opencv.hpp>
#include <vector>
#include <QString>
#include <QImage>

class ColorspaceImage
{
    cv::Mat Image;
    std::vector<cv::Mat> ImageChannels;

public:
    ColorspaceImage() { }
    ColorspaceImage(const QString* filePath);
    ~ColorspaceImage();
    //void operator=(const ColorspaceImage &src);
    //void saveImage();
    //void showImage() const;

    QImage asQImage();

    //getters
    std::vector<cv::Mat> getChannels() const;
    cv::Mat getImage() const;

    //setters
    void setChannels(std::vector<cv::Mat> &src);
    void setImage(cv::Mat &src);

};

#endif // COLORSPACEIMAGE_H
