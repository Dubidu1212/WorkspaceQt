#include "tile.h"


Dtile::Dtile(QPixmap Image, QPoint pos, QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent){
    setParentItem(parent);



    setPixmap(Image);
    setPos(pos);
}

void Dtile::setCol(bool b)
{
    this->colision = b;
    if(colision){

        colisionList.append(this);
        setVisible(false);
    }
    else{

        setVisible(true);
    }
}
