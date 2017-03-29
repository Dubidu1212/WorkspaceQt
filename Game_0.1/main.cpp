
#include "mainwindow.h"
#include "handler.h"
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <vector>
#include "tile.h"
#include <QFontDatabase>
#include "player.h"
#include <QGraphicsItem>
#include <thread>
#include <updater.h>
#include "viewo.h"
#include "gamemaster.h"



QList<Enemy*> UpdaterEnemy;
QList<QGraphicsItem*> spawner;
QList<pointerList> firebs;
QList<QGraphicsItem *> updatelist;
map mp;
tileset t;
QList <QImage> gid;
QFont dfont;
pressed controls;
Player * pl;
QList  <QGraphicsItem*> colisionList;
QList<Action> TLA;









int main(int argc, char **argv)
{
    std::cout <<"gestartet"<<std::endl;
    //Problem ist beim einlesen
    QApplication app(argc,argv);

    GameMaster * master = new GameMaster(&app);

    return app.exec();


}
