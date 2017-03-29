#include "fireball.h"

fireball::fireball(int direction):QObject(){
    //this->setPixmap();
    dir = direction*90;
    col = &colisionList;

    for(int x = 0; x < 4 ; x++){
        QTransform form;
        form.rotate(dir);
        QPixmap pxmp = QPixmap().fromImage(QImage(":/sprites/fireball.png").copy(x*32,0,32,32).transformed(form));
        pixmaps.append(pxmp);
    }
    this->setPos(pl->pos().x() + 7,pl->pos().y() + 10);//in den hintergrund setzen


    firebspos = firebs.length();

    pointerList tm;
    tm.item = this;
    tm.valid = true;
    firebs.append(tm);

    this->setVisible(true);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(animate()));
            timer->start(100);




}

bool fireball::colides(QList<QGraphicsItem *> *colisionObjects){
    for(int x = 0; x < colisionObjects->length(); x++){
        if(colisionObjects->at(x)->collidesWithItem(this)){
            return true;
        }
    }

    return false;

}

void fireball::animate(){
    setZValue(0);
    if(this->ddd > 3){
        ddd = 0;
    }
    this->setPixmap(pixmaps.at(ddd));
    ddd++;  

    if(this->colides(col)){
        //this->scene()->removeItem(this);
        pointerList pl;
        pl.item = this;
        pl.valid = false;
        firebs.replace(firebspos,pl);

        deleteLater();//noch explosion zeichnen

    }
    if(dir == 90){//up
        this->moveBy(0,-25);
    }
    else if(dir == 270){//down
        this->moveBy(0,25);
    }
    else if(dir == 0){//left
        this->moveBy(-25,0);
    }
    else if(dir == 180){//right
        this->moveBy(25,0);
    }
}

