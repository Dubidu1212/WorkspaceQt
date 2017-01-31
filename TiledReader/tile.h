#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPoint>

class Dtile: public QGraphicsPixmapItem{

public:
    Dtile(QImage,QPoint);

};

#endif // TILE_H
