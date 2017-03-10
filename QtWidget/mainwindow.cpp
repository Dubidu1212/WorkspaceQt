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
    for(int x = 0; x < mp.layers.length(); x++){//jedes tileset durchläuft diesen prozess
        int varY = 0;
        int durchgang = 0;
        int tileheight = mp.tilesets.at(x).tileheight;
        for(int z = 0; z < mp.layers.at(x).width; z++){
            int varX = 0;
            for(int y = 0; y < mp.layers.at(x).height;y++){
                QPoint point(varX,varY);

                    Dtile * DiTile = new Dtile(QPixmap().fromImage( gid.at(mp.layers.at(x).tiles.at( durchgang ).gid -1)), point, item);
                    scene->addItem(DiTile);
                     durchgang++;

                //std::cout << durchgang << "   " << mp.layers.at(0).tiles.at( durchgang -1 ).gid << std::endl;
                varX += tileheight;
            }
            varY += tileheight;
        }
    }


    ui->view->scale(1.25,1.25);

    scene->addItem(pl);

    ui->menuGame->setFont(dfont);
    ui->view->setScene(scene);
    //ui->view->scene()->setItemIndexMethod(QGraphicsScene::NoIndex);

    //ui->view->centerOn(pl);
    QBrush * brush = new QBrush(QColor(10,30,0,255),Qt::SolidPattern);
    ui->view->setBackgroundBrush(*brush);

    //this->setFixedSize(this->size());//TODO das nach fullscreen setzen
}

MainWindow::~MainWindow()
{
    delete ui;


}





void MainWindow::resizeEvent (QResizeEvent *event)
{
    QRectF rf;
    rf.setSize(ui->centralWidget->size());
    std::cout << "cw" << ui->centralWidget->size().height() << std::endl;

    ui->view->scene()->setSceneRect(rf);
    std::cout << "s" <<ui->view->scene()->sceneRect().height() << std::endl;

    ui->view->setSceneRect(rf);
    std::cout << "v" <<ui->view->sceneRect().height() << std::endl;



}


void MainWindow::AddItem (QGraphicsItem * item, int scene){
    //muss für jede scene ein elif einrichten
    if(scene == 1){
        ui->view->scene()->addItem(item);
    }
}

