#-------------------------------------------------
#
# Project created by QtCreator 2017-02-06T17:54:24
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtWidget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ditile.cpp \
    imageloader.cpp \
    handler.cpp \
    player.cpp \
    viewo.cpp \
    colisionbox.cpp \
    updater.cpp \
    level.cpp \
    levelhandler.cpp \
    fireball.cpp \
    enemy.cpp \
    gamemaster.cpp


HEADERS  += mainwindow.h \
    tile.h \
    structs.h \
    imageloader.h \
    handler.h \
    player.h \
    viewo.h \
    colisionbox.h \
    updater.h \
    level.h \
    levelhandler.h \
    fireball.h \
    enemy.h \
    gamemaster.h


FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
