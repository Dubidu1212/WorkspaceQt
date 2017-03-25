#ifndef PLAYER_H
#define PLAYER_H

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
#include "fireball.h"


class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QRect Tsize,QGraphicsItem * parent=0);
    void move(int distance);
    void animate();
    char collides(const QGraphicsItem * other) const;

    int mausCool = 0;
private:

    QRect size;
    int up = 0;
    int down = 0;
    int right = 0;
    int left = 0;
    int lookDirection;
    QList<Dspritesheet> sp;
public slots:
    void attack(QPoint p, int button, int count);
};
extern Player * pl;
extern QList<QGraphicsItem*> firebs;


#endif // PLAYER_H
