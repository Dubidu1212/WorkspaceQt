#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <iostream>
#include <QPixmap>
#include <QImage>
#include "structs.h"
#include "player.h"
#include <QGraphicsColorizeEffect>
#include <QColor>


#include <QHash>

class Enemy:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QList<Enemy*> * EnemyList,int pos);
    void animate(char direction);
     void move();
private:
    int lives;
    QList<Dspritesheet> sp;
    int up = 0;
    int down = 0;
    int right = 0;
    int left = 0;
    int verletzt = 0;
    QGraphicsColorizeEffect * effect = new QGraphicsColorizeEffect();
    QList<Enemy*> * EList;
    int lipos;

};

#endif // ENEMY_H
