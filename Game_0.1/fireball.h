#ifndef FIREBALL_H
#define FIREBALL_H

#include <QGraphicsItem>
#include <QFile>
#include "player.h"
#include <QImage>
#include <QTimer>
#include <QTransform>
#include "structs.h"
class fireball:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    fireball(int direction);
    void move(int direction);
    QList<QGraphicsItem *> * col;
    QList<QPixmap> pixmaps;
    int ddd = 0;
    int dir;
    bool colides(QList<QGraphicsItem*> * colisionObjects);
public slots:
    void animate();
private:
    int firebspos;

};

#endif // FIREBALL_H
