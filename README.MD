
# Summary

A CLI tool that allows a user to change the saturation of an image and save it. Just specify a file path and a saturation % change. Values less than a 100 will decrease the saturation and values greater than 100 will increase the saturation. Colorspaces are automatically converted in the underlying source. 

Written in C++ using OpenCV.

# Installation/Build Instructions

## Prerequisites

**OpenCV**

If you already have openCV, ensure that the library include locations as well as the header include locations are set to your installation.

*Source includes for opencv points to usr/local/include/opencv4 which then contains the #included <opencv2/opencv.hpp>*

*Source library includes for opencv points to usr/local/lib*

If you do not have openCV installed, then follow these instructions to build from source.

### Install minimal prerequisites (Ubuntu 18.04 as reference)
`sudo apt update && sudo apt install -y cmake g++ wget unzip`
### Download and unpack sources
`wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip`
Might need to include ` --no-check-certificate` for unverified github certificate.
`unzip opencv.zip`
### Create build directory
`mkdir -p build && cd build`
### Configure
`cmake  ../opencv-master`
### Build
`cmake --build .` don't forget the '.' (Can take very long, upwards of half an hour).
### Installing to /usr/local/
`sudo make install` 

**QMake**

### Install QMake
`sudo apt install qt5-qmake qt5-default`

## Building Source
Navigate to source directory PSChallenge-Console-Linux/
### Build the makefile
`qmake PSChallenge-Console-Linux.pro`
### Build output
`make`

#### Get an image to use. Some are already provided in /assets/: tiger.jpeg , colors.png

### Run with filename as 2nd argument.
`./PSChallenge-Console-Linux assets/tiger.jpeg`


