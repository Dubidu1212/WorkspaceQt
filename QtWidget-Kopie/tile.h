#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPoint>
#include <QGraphicsView>
#include "structs.h"

class Dtile: public QGraphicsPixmapItem{

public:
    Dtile(QPixmap, QPoint , QGraphicsPixmapItem *parent);
    void setCol(bool b);
private:
    bool colision;
};

#endif // TILE_H
