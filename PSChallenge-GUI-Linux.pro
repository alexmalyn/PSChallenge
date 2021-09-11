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

RESOURCES += \
    res.qrc

unix: LIBS += -Lusr/local/lib/ -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

DESTDIR = build
OBJECTS_DIR = build/.obj
MOC_DIR = build/.moc
RCC_DIR = build/.rcc
UI_DIR = build/.ui
