#ifndef CONTROLER_H
#define CONTROLER_H


#include "QGraphicsItem"
#include "mainwindow.h"
#include  <QKeyEvent>
#include <iostream>
#include <QGraphicsItem>

class Controler: public QGraphicsRectItem{


public:
    Controler();
    void keyPressEvent(QKeyEvent * event);


protected:



};

#endif // CONTROLER_H
