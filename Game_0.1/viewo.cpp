#include "viewo.h"
#include <iostream>
#include <qevent.h>
#include <QThread>
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

    else if((event->key() == Qt::Key_Right)||(event->key() == Qt::Key_D)){//right
        controls.right = true;
    }

    else if((event->key() == Qt::Key_Down)||(event->key() == Qt::Key_S)){//down
        controls.down = true;
    }

    else if((event->key() == Qt::Key_Up)||(event->key() == Qt::Key_W)){//up
        controls.up = true;
    }

    else if(event->key() == Qt::Key_Space){

        controls.space = true;
        /*Enemy * en = new Enemy();
        this->scene()->addItem(en);*/

    }



}

void viewo::keyReleaseEvent(QKeyEvent *event)//hier entfernen
{


    if((event->key() == Qt::Key_Left)||(event->key() == Qt::Key_A)){//left
        controls.left = false;

    }

     else if((event->key() == Qt::Key_Right)||(event->key() == Qt::Key_D)){//right
        controls.right = false;
    }

    else if((event->key() == Qt::Key_Down)||(event->key() == Qt::Key_S)){//down
        controls.down = false;
    }

    else if((event->key() == Qt::Key_Up)||(event->key() == Qt::Key_W)){//up
        controls.up = false;
    }

    else if(event->key() == Qt::Key_Space){
        controls.space = false;
    }
}


void viewo::mousePressEvent(QMouseEvent *event){

    //1 = links      2 = rechts
    int y;
    if(pl->mausCool < 1){
        pl->mausCool = 100;
        if(event->button() == Qt::LeftButton){
             y = 1;
        }
        else if(event->button() == Qt::RightButton){
             y = 2;
        }

        for(int x = 0; x < 6 ;x++){
            pl->attack(event->pos(),y,x);


        }
    }
    else{


    }
}



viewo::viewo(QWidget *parent):QGraphicsView(parent){
    this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );



}



