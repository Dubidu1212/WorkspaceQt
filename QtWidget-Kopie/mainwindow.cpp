#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tile.h"
#include "structs.h"
#include "player.h"
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGradient>
#include <iostream>
#include "controler.h"

#include <QGraphicsItem>







MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);






    QPixmap * pixmap = new QPixmap();
    QGraphicsScene * scene = new QGraphicsScene();

    QGraphicsPixmapItem * pixmapItem = new QGraphicsPixmapItem();
    QGraphicsPixmapItem * item = new QGraphicsPixmapItem();
    for(int x = 0; x < mp.layers.length(); x++){

        int varY = 0;
        int durchgang = 0;
        int tileheight = mp.tilesets.at(0).tileheight;

        for(int z = 0; z < mp.layers.at(x).height; z++){

            int varX = 0;
            for(int y = 0; y < mp.layers.at(x).width;y++){//wahrscheinlich x und y vertauscht
                QPoint point(varX,varY);


                    if(!mp.layers.at(x).tiles.at(durchgang).colision){

                        Dtile * DiTile = new Dtile(QPixmap().fromImage( gid.at(mp.layers.at(x).tiles.at(durchgang).gid-1)), point, item);
                        DiTile->setCol(false);

                        scene->addItem(DiTile);

                    }
                    else if(mp.layers.at(x).tiles.at(durchgang).colision && mp.layers.at(x).tiles.at(durchgang).gid != 0){

                        Dtile * DiTile = new Dtile(QPixmap().fromImage(gid.at(1)), point, item);//hier ein durchsichtiges tile auswählen
                        DiTile->setCol(true);

                        scene->addItem(DiTile);

                    }
                    else{



                    }

                     durchgang++;

                //std::cout << durchgang << "   " << mp.layers.at(0).tiles.at( durchgang -1 ).gid << std::endl;
                varX += tileheight;
            }
            varY += tileheight;
        }
    }


    ui->view->scale(1.5,1.5);

    scene->addItem(pl);

    ui->menuGame->setFont(dfont);
    ui->view->setScene(scene);


    QBrush * brush = new QBrush(QColor(17,150,10,255),Qt::SolidPattern);
    ui->view->setBackgroundBrush(*brush);

    //this->setFixedSize(this->size());//TODO das nach fullscreen setzen
}

MainWindow::~MainWindow()
{
    delete ui;


}





void MainWindow::resizeEvent (QResizeEvent *event)
{
    /*
    QRectF rf;
    rf.setSize(ui->centralWidget->size());
    std::cout << "cw" << ui->centralWidget->size().height() << std::endl;

    ui->view->scene()->setSceneRect(rf);
    std::cout << "s" <<ui->view->scene()->sceneRect().height() << std::endl;

    ui->view->setSceneRect(rf);
    std::cout << "v" <<ui->view->sceneRect().height() << std::endl;

*/

}

viewo *MainWindow::View()
{
    return ui->view;
}


void MainWindow::AddItem (QGraphicsItem * item, int scene){
    //muss für jede scene ein elif einrichten
    if(scene == 1){
        ui->view->scene()->addItem(item);
    }
}

