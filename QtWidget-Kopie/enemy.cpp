#include "enemy.h"

Enemy::Enemy(){
    lives = 5;
    this->setVisible(true);

    Dspritesheet tempsp;
    tempsp.image = QImage(":/sprites/Enemy_back.png");
    tempsp.tilecount = 4;
    tempsp.name = "back";
    sp.append(tempsp);

    tempsp.image = QImage(":/sprites/Enemy_front.png");
    tempsp.tilecount = 4;
    tempsp.name = "front";
    sp.append(tempsp);

    tempsp.image = QImage(":/sprites/Enemy_left.png");
    tempsp.tilecount = 4;
    tempsp.name = "left";
    sp.append(tempsp);

    tempsp.image = QImage(":/sprites/Enemy_right.png");
    tempsp.tilecount = 4;
    tempsp.name = "right";
    sp.append(tempsp);

    effect->setColor(QColor(100,0,100));
    this->setGraphicsEffect(effect);
    effect->setEnabled(false);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}


void Enemy::move(){


    for(int x = 0;x < firebs.length();x++){

        if(this->collidesWithItem(firebs.at(x)),Qt::IntersectsItemBoundingRect){
            if(verletzt < 1){
                this->lives -= 3;
                verletzt = 50;
                effect->setEnabled(true);


            }
            else{

            }

        }
        if(lives < 0){
           this->scene()->removeItem(this);

            deleteLater();
        }
    }
    if(verletzt < 0){
        effect->setEnabled(false);
    }
    verletzt--;
    bool r = true;
    bool l = true;
    bool u = true;
    bool d = true;
    QPoint point(pl->pos().toPoint());
    point += pl->boundingRect().center().toPoint();
    if(point.y() == this->boundingRect().center().y()){

    }
    else {


    if(point.x() > (this->pos().x() + this->boundingRect().center().x())){
        this->moveBy(0.5,0);
        animate('r');
    }
    else{
        this->moveBy(-0.5,0);
        animate('l');
    }

    if(point.y() > (this->pos().y() + this->boundingRect().center().y()) ){
        this->moveBy(0,0.5);
        animate('d');
    }
    else{
        this->moveBy(0,-0.5);
        animate('u');
    }
    }
}

void Enemy::animate(char direction){

if(direction =='u'){

    if(up%10 == 0){
        if(up == 40){
            up = 10;
        }
        QRect rect = QRect( (up/10-1) * sp.at(0).image.height(),0,sp.at(0).image.height(), sp.at(0).image.height());

        setPixmap(QPixmap().fromImage(QImage(sp.at(0).image.copy(rect))));

    }
    up++;
     down = 10;
     right = 10;
     left = 10;

}
else if(direction =='d'){

    if(down%10 == 0){
        if(down == 40){
            down = 10;
        }
        QRect rect = QRect( (down/10-1) * sp.at(1).image.height(),0,sp.at(1).image.height(), sp.at(1).image.height());
        setPixmap(QPixmap().fromImage(QImage(sp.at(1).image.copy(rect))));

    }

    down++;
     up = 10;
     left = 10;
     right  = 10;

}
else{

}



}

