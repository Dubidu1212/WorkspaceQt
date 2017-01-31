#include "tile.h"


Dtile::Dtile(QImage Image, QPoint pos) : QGraphicsPixmapItem(){
    QPixmap pixmap;
    pixmap.fromImage(Image);
    setPixmap(pixmap);
    setPos(pos);
    setVisible(true);
}
