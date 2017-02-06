#include "tile.h"


Dtile::Dtile(QPixmap Image, QPoint pos, QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent){
    setParentItem(parent);

    setPixmap(Image);
    setPos(pos);
    setVisible(true);
}
