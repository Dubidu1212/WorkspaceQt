#include "player.h"


Player::Player(QRect Tsize,QGraphicsItem * parent): QGraphicsPixmapItem(parent){
    this->size = Tsize;

    //box = new colisionbox(this,this->size);//befindet sich immer beim playeyr

    Dspritesheet tempsp;

    tempsp.image = QImage(":/sprites/Magier_back.png");
    tempsp.tilecount = 4;
    tempsp.name = "back";
    sp.append(tempsp);

    tempsp.image = QImage(":/sprites/Magier_front.png");
    tempsp.tilecount = 4;
    tempsp.name = "front";
    sp.append(tempsp);

    tempsp.image = QImage(":/sprites/Magier_left.png");
    tempsp.tilecount = 4;
    tempsp.name = "left";
    sp.append(tempsp);

    tempsp.image = QImage(":/sprites/Magier_right.png");
    tempsp.tilecount = 4;
    tempsp.name = "right";
    sp.append(tempsp);

}

void Player::move(int distance){
   this->animate();
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

    if(controls.up){
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
    else if(controls.down){

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
    else if(controls.left){
        if(left%10 == 0){
            if(left == 40){
                left = 10;
            }
            QRect rect = QRect( (left/10-1) * sp.at(2).image.height(),0,sp.at(2).image.height(), sp.at(2).image.height());
            setPixmap(QPixmap().fromImage(QImage(sp.at(2).image.copy(rect))));
            qDebug() << "l "<< left ;
        }
        left++;
         up = 10;
         down = 10;
         right = 10;

    }
    else if(controls.right){

        if(right%10 == 0){
            if(right == 40){
                right = 10;
            }
            QRect rect = QRect( (right/10-1) * sp.at(3).image.height(),0,sp.at(3).image.height(), sp.at(3).image.height());
            setPixmap(QPixmap().fromImage(QImage(sp.at(3).image.copy(rect))));
            qDebug() << "r "<< right ;

        }
         right++;
         up = 10;
         down = 10;
         left = 10;

    }

}



