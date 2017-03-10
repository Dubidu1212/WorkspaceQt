#ifndef COLISIONBOX_H
#define COLISIONBOX_H
#include <QGraphicsItem>
#include <QObject>
#include "player.h"

class colisionbox:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    colisionbox(QGraphicsItem * parent,QRect size);

};

#endif // COLISIONBOX_H
