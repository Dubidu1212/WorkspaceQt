#include "player.h"


Player::Player(QRect Tsize,QGraphicsItem * parent): QGraphicsPixmapItem(parent){
    this->size = Tsize;

    colisionbox * box = new colisionbox(this,this->size);//befindet sich immer beim playeyr

    spritesheet tempsp;
/*
    tempsp.image = QPixmap(":/sprites/Magier_front.png");
    tempsp.tilecount = 4;
    tempsp.name = "front";
    sp.append(tempsp);

    tempsp.image = QPixmap(":/sprites/Magier_back.png");
    tempsp.tilecount = 4;
    tempsp.name = "back";
    sp.append(tempsp);

    tempsp.image = QPixmap(":/sprites/Magier_left.png");
    tempsp.tilecount = 4;
    tempsp.name = "left";
    sp.append(tempsp);

    tempsp.image = QPixmap(":/sprites/Magier_right.png");
    tempsp.tilecount = 4;
    tempsp.name = "right";
    sp.append(tempsp);
*/
}

void Player::move(int distance){

   if(controls.up ){
       this->moveBy(0,0-distance);

   }
   else if(controls.down){
       this->moveBy(0,distance);

   }
   else if(controls.left){
       this->moveBy(0-distance,0);

   }
   else if(controls.right){
       this->moveBy(distance,0);

   }

}

void Player::animate(){
/*
    if(controls.up){
        up++;
        int down = 10;
        int right = 10;
        int left = 10;

    }
    else if(controls.down){
        down++;
        int up = 10;
        int left = 10;
        int right  = 10;

    }
    else if(controls.left){
        left++;
        int up = 10;
        int down = 10;
        int left = 10;

    }
    else if(controls.right){

        if(right%10 == 0){
            QRect rect = QRect(right/10 * sp.at(4).image.height(),0,sp.at(4).image.height(), sp.at(4).image.height());
            setPixmap(QPixmap().fromImage(QImage(sp.at(4).copy()));

        }
        right++;
        int up = 10;
        int down = 10;
        int right = 10;

    }
*/
}



