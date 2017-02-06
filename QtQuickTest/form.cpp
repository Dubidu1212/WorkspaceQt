#include "form.h"
#include "ui_form.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "tile.h"
#include "structs.h"
#include <iostream>
#include <QFontDatabase>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene();



    ui->viewer->setWindowTitle("Game");
    scene->setSceneRect(0,0,800,600);
    QGraphicsPixmapItem * item = new QGraphicsPixmapItem();

    for(int x = 0; x < mp.layers.length(); x++){//jedes tileset durchläuft diesen prozess
        int varY = 0;
        int durchgang = 0;
        int tileheight = mp.tilesets.at(x).tileheight;
        for(int z = 0; z < mp.layers.at(x).width; z++){
            int varX = 0;
            for(int y = 0; y < mp.layers.at(x).height;y++){
                QPoint point(varX,varY);
                    Dtile * DiTile = new Dtile(QPixmap().fromImage( gid.at(mp.layers.at(0).tiles.at( durchgang ).gid -1)),point, item);
                    scene->addItem(DiTile);
                     durchgang++;

                varX += tileheight;
            }
            varY += tileheight;
        }
    }

    //QFontDatabase::addApplicationFont("endor");
    //QFont * font = new QFont(QString("endor"),30,-1,false);//endor
    ui->viewer->setScene(scene);
    ui->viewer->setVisible(true);

}

Form::~Form()
{
    delete ui;
}
