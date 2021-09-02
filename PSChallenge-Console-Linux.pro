QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    imagetransformer.h

SOURCES += \
        imagetransformer.cpp \
        main.cpp

INCLUDEPATH += \
        /usr/local/include/opencv4

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

RESOURCES +=

win32:CONFIG(release, debug|release): LIBS += -Lusr/local/lib/release/ -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs
else:win32:CONFIG(debug, debug|release): LIBS += -Lusr/local/lib/debug/ -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs
else:unix: LIBS += -Lusr/local/lib/ -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs


