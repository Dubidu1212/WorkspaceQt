#ifndef LEVEL_H
#define LEVEL_H

#include "structs.h"
#include <QGraphicsScene>

class Level: public QGraphicsScene{
public:
    Level();
    map Tmap;
    int id;
    QString name;
    QList<Action> LevelAction;
    void setUp();//hier das xml welches bei der erstellung gegeben wurde parsen
};

#endif // LEVEL_H
