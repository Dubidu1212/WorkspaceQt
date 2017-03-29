#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <QObject>
#include "enemy.h"
#include "structs.h"
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
#include <QtGlobal>

class GameMaster: public QObject{
    Q_OBJECT
public:
    GameMaster(QApplication * app);
    void tilecreator();
    void spawn();
    void control();
public slots:
    void update();
private:
    int time= 0;
    int Enemys = 0;
};
extern QList<Enemy*> UpdaterEnemy;

#endif // GAMEMASTER_H
