#include "viewo.h"
#include <iostream>
#include <qevent.h>
//#include "structs.h"
#include "player.h"

void  viewo::wheelEvent ( QWheelEvent * event )
{
    //pro einrastung 2mal


}

void viewo::keyPressEvent(QKeyEvent *event)//hier zur events liste hinzufügen
{



    if((event->key() == Qt::Key_Left)||(event->key() == Qt::Key_A)){//left
        controls.left = true;

    }

    if((event->key() == Qt::Key_Right)||(event->key() == Qt::Key_D)){//right
        controls.right = true;
    }

    if((event->key() == Qt::Key_Down)||(event->key() == Qt::Key_S)){//down
        controls.down = true;
    }

    if((event->key() == Qt::Key_Up)||(event->key() == Qt::Key_W)){//up
        controls.up = true;
    }

    if(event->key() == Qt::Key_Space){

        controls.space = true;


    }


}

void viewo::keyReleaseEvent(QKeyEvent *event)//hier entfernen
{


    if((event->key() == Qt::Key_Left)||(event->key() == Qt::Key_A)){//left
        controls.left = false;

    }

    if((event->key() == Qt::Key_Right)||(event->key() == Qt::Key_D)){//right
        controls.right = false;
    }

    if((event->key() == Qt::Key_Down)||(event->key() == Qt::Key_S)){//down
        controls.down = false;
    }

    if((event->key() == Qt::Key_Up)||(event->key() == Qt::Key_W)){//up
        controls.up = false;
    }

    if(event->key() == Qt::Key_Space){
        controls.space = false;
    }
}

viewo::viewo(QWidget *parent):QGraphicsView(parent){
    this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

}

