#-------------------------------------------------
#
# Project created by QtCreator 2016-12-29T17:55:02
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TiledReader
TEMPLATE = app


SOURCES += main.cpp \
    handler.cpp \
    imageloader.cpp \
    tile.cpp

HEADERS  += \
    handler.h \
    structs.h \
    imageloader.h \
    tile.h


FORMS    +=

RESOURCES += \
    res.qrc

DISTFILES +=
