#include "updater.h"
#include "player.h"
#include "mainwindow.h"
#include <QChildEvent>




updater::updater(int time):QObject(){
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
            timer->start(time);
}

void updater::update()
{
    pl->move(1);
    pl->mausCool--;

    Dvi->centerOn(pl);




}

