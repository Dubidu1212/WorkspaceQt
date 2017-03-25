#include "player.h"


Player::Player(QRect Tsize,QGraphicsItem * parent): QGraphicsPixmapItem(parent){
    this->size = Tsize;
    setZValue(1);
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



    tempsp.image = QImage(":/sprites/Magier_back_spell.png");
    tempsp.tilecount = 6;
    tempsp.name = "back_spell";
    sp.append(tempsp);

    tempsp.image = QImage(":/sprites/Magier_front_spell.png");
    tempsp.tilecount = 6;
    tempsp.name = "front_spell";
    sp.append(tempsp);

    tempsp.image = QImage(":/sprites/Magier_left_spell.png");
    tempsp.tilecount = 6;
    tempsp.name = "left_spell";
    sp.append(tempsp);

    tempsp.image = QImage(":/sprites/Magier_right_spell.png");
    tempsp.tilecount = 6;
    tempsp.name = "right_spell";
    sp.append(tempsp);

}

void Player::move(int distance){
   this->animate();
    bool r = true;
    bool l = true;
    bool u = true;
    bool d = true;


    for(int x = 0; x<colisionList.length();x++){


        if(this->collides(colisionList.at(x) ) == 'u'){
            u = false;
        }
        else if(this->collides(colisionList.at(x) ) == 'd'){
            d = false;
        }
        else if(this->collides(colisionList.at(x) ) == 'l'){
            l = false;
        }
        else if(this->collides(colisionList.at(x) ) == 'r'){
            r = false;
        }

    }




   if(controls.up && u){
       this->moveBy(0,0-distance);

   }
   else if(controls.down && d){
       this->moveBy(0,distance);

   }
   else if(controls.left && l){
       this->moveBy(0-distance,0);

   }
   else if(controls.right && r){
       this->moveBy(distance,0);

   }
 //  else if()

}

void Player::animate(){

    if(controls.up){
        lookDirection = 1;
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
        lookDirection =3;
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
        lookDirection = 0;
        if(left%10 == 0){
            if(left == 40){
                left = 10;
            }
            QRect rect = QRect( (left/10-1) * sp.at(2).image.height(),0,sp.at(2).image.height(), sp.at(2).image.height());
            setPixmap(QPixmap().fromImage(QImage(sp.at(2).image.copy(rect))));
        }
        left++;
         up = 10;
         down = 10;
         right = 10;

    }
    else if(controls.right){
        lookDirection = 2;

        if(right%10 == 0){
            if(right == 40){
                right = 10;
            }
            QRect rect = QRect( (right/10-1) * sp.at(3).image.height(),0,sp.at(3).image.height(), sp.at(3).image.height());
            setPixmap(QPixmap().fromImage(QImage(sp.at(3).image.copy(rect))));

        }
         right++;
         up = 10;
         down = 10;
         left = 10;

    }
    else{

    }

}

void Player::attack(QPoint p, int button,  int count){
    int temp;
    if(lookDirection == 1){
        temp = 4;
    }
    else if(lookDirection == 3){
        temp = 5;
    }
    else if(lookDirection == 2){
        temp = 7;
    }
    else{
        temp = 6;
    }

    QRect rect = QRect( count * sp.at(temp).image.height(),0,sp.at(temp).image.height(), sp.at(temp).image.height());
    setPixmap(QPixmap().fromImage(QImage(sp.at(temp).image.copy(rect))));
    if(count > 4){
        fireball * fb = new fireball(lookDirection);
        this->scene()->addItem(fb);
    }

}

char Player::collides(const QGraphicsItem *other) const
{
    if(this->collidesWithItem(other,Qt::IntersectsItemBoundingRect)){
        if(this->boundingRect().center().x() + this->pos().x() > other->pos().x() + other->boundingRect().center().x()){// other befindet sich links
            if(this->boundingRect().center().y() + this->pos().y() > other->pos().y() + other->boundingRect().center().y()){//other ist über
                //!hier geht es darum zu bestimmen welches kleiner ist diesen wert dann returnen
               int dy = (this->boundingRect().center().y() + this->pos().y()) - (other->pos().y() + other->boundingRect().center().y());//!center ist der punkt relativ zu seiner echten position
               int dx = (this->boundingRect().center().x() + this->pos().x())  - (other->pos().x() + other->boundingRect().center().x());
               if(dx > dy ){//dy
                   return 'l';
               }
               else{//dx
                   return 'u';
               }
            }
            else{// other ist unter
                int dy = (other->boundingRect().center().y() + other->pos().y() ) - (this->pos().y() +this->boundingRect().center().y());
                int dx = (this->pos().x() + this->boundingRect().center().x() ) -  (other->pos().x() + other->boundingRect().center().x());
                if(dx > dy){//dy
                    return 'l';
                }
                else{//dx
                    return 'd';
                }
            }
        }
        else{// other befindet sich rechts
            if(this->boundingRect().center().y() + this->pos().y() > other->pos().y() + other->boundingRect().center().y()){// other ist über
                int dy = (this->boundingRect().center().y() + this->pos().y()) - (other->pos().y() + other->boundingRect().center().y());//!center ist der punkt relativ zu seiner echten position
                int dx = (other->boundingRect().center().x() + other->pos().x()) - (this->pos().x() + this->boundingRect().center().x());
                if(dx > dy){//dy
                    return 'r';
                }
                else{//dx
                    return 'u';
                }
            }
            else{// other ist unter
                int dy = (other->boundingRect().center().y() + other->pos().y() ) - (this->pos().y() +this->boundingRect().center().y());
                int dx = (other->boundingRect().center().x() + other->pos().x()) - (this->pos().x() + this->boundingRect().center().x());
                if(dx > dy){//dy
                    return 'r';
                }
                else{//dx
                    return 'd';
                }
            }
        }
    }
    return 'n';
}





