#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsRectItem>
#include <QDebug>
#include "colisionbox.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <iostream>
#include <QPixmap>
#include <QImage>
#include "structs.h"

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QRect Tsize,QGraphicsItem * parent=0);
    void move(int distance);
    void animate();


private:
    QRect size;
    int up = 0;
    int down = 0;
    int right = 0;
    int left = 0;
    //QList<spritesheet> sp;//hier ist ein fehler
};
extern Player * pl;

#endif // PLAYER_H
