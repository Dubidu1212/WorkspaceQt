#include "updater.h"
#include "structs.h"
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
    if(pl->boundingRect().intersects(pl->scene()->sceneRect())){// hier anstelle der scene ein item erestellen
        qDebug() << "djd";
    }

}

