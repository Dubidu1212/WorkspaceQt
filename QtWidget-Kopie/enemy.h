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

class Enemy:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy();
    void animate(char direction);
public slots:
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

};

#endif // ENEMY_H
