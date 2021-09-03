# Installation/Build Instructions

## Prerequisites

**OpenCV**

(From docs.opencv.org instructions for linux install)

### Install minimal prerequisites (Ubuntu 18.04 as reference)
`sudo apt update && sudo apt install -y cmake g++ wget unzip`
### Download and unpack sources
`wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip`
`unzip opencv.zip`
### Create build directory
`mkdir -p build && cd build`
### Configure
`cmake  ../opencv-master`
### Build
`cmake --build .`
### Installing to /usr/local/
`sudo make install`

## Building Source

### Build the makefile
`qmake PSChallenge-Console-Linux.pro`
### Build output
`make`

#### Get an image to use. Some are already provided in /assets/: tiger.jpeg , colors.png

### Run with filename as 2nd argument.
`./PSChallenge-Console-Linux assets/tiger.jpeg`


