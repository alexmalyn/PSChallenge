FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y && \
    apt-get install -y \
        cmake \
        g++ \
        wget \
        unzip \
        qt5-qmake \
        qt5-default 

WORKDIR /usr/local

RUN wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip && \
    unzip opencv.zip

WORKDIR /usr/local/build

RUN cmake ../opencv-master && \
    cmake --build . && \
    make install

COPY . /usr/src/PSChallenge

WORKDIR /usr/src/PSChallenge

RUN qmake PSChallenge-Console-Linux.pro && make

CMD ["bash"]
