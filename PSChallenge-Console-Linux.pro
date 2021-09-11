QT += \
    gui \
    widgets \
    core

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    colorspaceimage.h \
    imagetransformer.h \
    mainwindow.h

FORMS += \
    mainwindow.ui


SOURCES += \
        colorspaceimage.cpp \
        imagetransformer.cpp \
        main.cpp \
        mainwindow.cpp

INCLUDEPATH += \
        /usr/local/include/opencv4

RESOURCES +=

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

unix: LIBS += -Lusr/local/lib/ -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs




