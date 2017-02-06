TEMPLATE = app
TARGET = QtQuickTest

QT += qml quick core xml gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += main.cpp \
    handler.cpp \
    imageloader.cpp \
    tile.cpp \
    form.cpp

RESOURCES += \
    res.qrc


HEADERS += \
    handler.h \
    imageloader.h \
    tile.h \
    structs.h \
    form.h

FORMS += \
    form.ui
