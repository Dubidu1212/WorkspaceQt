#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T14:33:59
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTutorial
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    score.cpp \
    game.cpp \
    health.cpp \
    player.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    score.h \
    game.h \
    health.h \
    player.h

FORMS    +=

RESOURCES += \
    res.qrc

