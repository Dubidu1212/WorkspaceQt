#include "updater.h"
#include "structs.h"

updater::updater(int time):QObject(){
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
            timer->start(time);
}

void updater::update()
{
    pl->move(1);
}

