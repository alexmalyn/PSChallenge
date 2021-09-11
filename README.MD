
# Summary

A GUI tool that allows a user to change the saturation of an image and save it. Browse for an image, adjust the saturation, and optionally save it. A Value of 100% will double the saturation, while a value of 0% will make the image B/W.

Written in C++ using OpenCV.

# Installation/Build Instructions

Docker Repo has not been updated for use with the GUI tool, it still contains the old CLI format.

IMPORTANT: *If you have Docker and would rather run a container with everything already installed, skip to the Docker section at the end*

## Prerequisites

### OpenCV

If you already have openCV, ensure that the library include locations as well as the header include locations are set to your installation.

*Source includes for opencv points to usr/local/include/opencv4 which then contains the #included <opencv2/opencv.hpp>*

*Source library includes for opencv points to usr/local/lib*

If you do not have openCV installed, then follow these instructions to build from source.

#### Install minimal prerequisites (Ubuntu 18.04 as reference)
`sudo apt update && sudo apt install -y cmake g++ wget unzip`
#### Download and unpack sources
`wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip`

Might need to include ` --no-check-certificate` for unverified github certificate.

`unzip opencv.zip`
#### Create build directory
`mkdir -p build && cd build`
#### Configure
`cmake  ../opencv-master`
#### Build
`cmake --build .` don't forget the '.' (Can take very long, upwards of half an hour).
#### Installing to /usr/local/
`sudo make install` 

### QMake/Qt

#### Install QMake/Qt
`sudo apt install qt5-qmake qt5-default`

## Building Source
Navigate to source directory PSChallenge-GUI-Linux/
### Build the makefile
`qmake PSChallenge-GUI-Linux.pro`
### Build output
`make`

#### Get an image to use. Some are already provided in /assets/: tiger.jpeg , colors.png

### Run with filename as 2nd argument.
`./build/PSChallenge-GUI-Linux`

## Docker 

### Pull the image
`docker pull alexmalyn99/pschallenge`
### Start the container
`docker run -ti -d --name challenge alexmalyn99/pschallenge`
### Access the container
`docker exec -ti challenge sh`
### Run the program
If you would like to use your own local image files, you can copy them over by starting another terminal:

`docker cp "path/to/Image" challenge:"/usr/src/PSChallenge/assets"`

Then run the program in the container terminal:

`./PSChallenge-Console-Linux`

There are also other images in the assets folder by default.

To see these images in a container, you must save them and copy them back to your host machine in the other terminal: (Assuming you saved it in assets/)

`docker cp challenge:"/usr/src/PSChallenge/assets/{imageName.imageEXT}" "destination/path/{imageName.imageEXT}"`

