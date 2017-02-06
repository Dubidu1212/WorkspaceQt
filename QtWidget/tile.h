#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPoint>
#include <QGraphicsView>

class Dtile: public QGraphicsPixmapItem{

public:
    Dtile(QPixmap, QPoint , QGraphicsPixmapItem *parent);

};

#endif // TILE_H
