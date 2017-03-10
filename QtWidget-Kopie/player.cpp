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
    bool r = true;
    bool l = true;
    bool u = true;
    bool d = true;


    for(int x = 0; x<colisionList.length();x++){
        qDebug() <<"  dd  "<< this->collides(colisionList.at(x)) ;

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

        }
         right++;
         up = 10;
         down = 10;
         left = 10;

    }
    else{

    }

}

char Player::collides(const QGraphicsItem *other) const
{
    /*
    if(this->pos().x()+ this->boundingRect().width() > other->pos().x() && this->pos().x() < other->pos().x()+ other->boundingRect().width()){//von seite

        if(this->pos().y() + this->boundingRect().height() > other->pos().y() && this->pos().y() < other->pos().y() + other->boundingRect().height()){




            if(this->pos().x()+ this->boundingRect().width() > other->pos().x()){//rechts
                return 'r';
            }
            else if(this->pos().x() < other->pos().x()+ other->boundingRect().width()){//links
                return 'l';
            }
            else if(this->pos().y() < other->pos().y() + other->boundingRect().height()){//oben
                return 'u';
            }
            else if(this->pos().y() + this->boundingRect().height() > other->pos().y()){//unten
                return 'd';
            }


        }

    }
    /**/

/*

    if(this->boundingRect().intersects(other->boundingRect())){


        //hiermit kann ich 2 seiten auschliessen
        if(this->boundingRect().center().x() > other->boundingRect().center().x()){// other befindet sich links

            if(this->boundingRect().center().y() > other->boundingRect().center().y()){//other ist über
                //!hier geht es darum zu bestimmen welches kleiner ist diesen wert dann returnen
               int dy = this->boundingRect().center().y() - other->boundingRect().center().y();

               int dx = this->boundingRect().center().x() - other->boundingRect().center().x();

               if(dx > dy){//dy

                   return 'u';

               }
               else{//dx

                   return 'l';

               }

            }
            else{// other ist unter

                //!hier geht es darum zu bestimmen welches kleiner ist diesen wert dann returnen
                int dy = other->boundingRect().center().y() - this->boundingRect().center().y();

                int dx = this->boundingRect().center().x() - other->boundingRect().center().x();

                if(dx > dy){//dy

                    return 'd';
                }
                else{//dx

                    return 'l';

                }
            }
        }
        else{// other befindet sich rechts

            if(this->boundingRect().center().y() > other->boundingRect().center().y()){// other ist über
                //!hier geht es darum zu bestimmen welches kleiner ist diesen wert dann returnen
                int dy = this->boundingRect().center().y() - other->boundingRect().center().y();

                int dx = other->boundingRect().center().x() - this->boundingRect().center().x();

                if(dx > dy){//dy

                    return 'u';
                }
                else{//dx

                    return 'r';

                }

            }
            else{// other ist unter

                //!hier geht es darum zu bestimmen welches kleiner ist diesen wert dann returnen

                int dy = other->boundingRect().center().y() - this->boundingRect().center().y();

                int dx = other->boundingRect().center().x() - this->boundingRect().center().x();


                if(dx > dy){//dy

                    return 'd';

                }
                else{//dx

                    return 'r';

                }


            }
        }

    }
    return 'n';
    */

    if(this->collidesWithItem(other,Qt::IntersectsItemBoundingRect)){
        //hiermit kann ich 2 seiten auschliessen


        if(this->boundingRect().center().x() + this->pos().x() > other->pos().x() + other->boundingRect().center().x()){// other befindet sich links

            if(this->boundingRect().center().y() + this->pos().y() > other->pos().y() + other->boundingRect().center().y()){//other ist über
                //!hier geht es darum zu bestimmen welches kleiner ist diesen wert dann returnen
               int dy = (this->boundingRect().center().y() + this->pos().y()) - (other->pos().y() + other->boundingRect().center().y());//!center ist der punkt relativ zu seiner echten position

               int dx = (this->boundingRect().center().x() + this->pos().x())  - (other->pos().x() + other->boundingRect().center().x());

               if(dx > dy ){//dy


                   return 'l';

               }
               else{//dx


                   qDebug() << dx <<"jd"<< dy;
                   return 'u';

               }

            }
            else{// other ist unter

                //!hier geht es darum zu bestimmen welches kleiner ist diesen wert dann returnen
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
                //!hier geht es darum zu bestimmen welches kleiner ist diesen wert dann returnen
                //!
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

                //!hier geht es darum zu bestimmen welches kleiner ist diesen wert dann returnen

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





