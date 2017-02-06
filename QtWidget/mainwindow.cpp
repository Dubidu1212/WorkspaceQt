#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tile.h"
#include "structs.h"
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);











    QPixmap * pixmap = new QPixmap();
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsPixmapItem * pixmapItem = new QGraphicsPixmapItem();


   // pixmapItem->setPixmap(pixmap->fromImage(images.at(0)));
    QGraphicsPixmapItem * item = new QGraphicsPixmapItem();

   /* for(int x = 0; x < 10;x++){//nur zum test
        QPoint point(x*gid.at(0).width(),x*gid.at(0).width());

        Dtile * DiTile = new Dtile(QPixmap().fromImage( gid.at(x)),point, item);

        scene->addItem(DiTile);


    }
    */

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
                //std::cout << durchgang << "   " << mp.layers.at(0).tiles.at( durchgang -1 ).gid << std::endl;
                varX += tileheight;
            }
            varY += tileheight;
        }
    }



    QRectF rect;
    rect.setSize(ui->view->size());
    scene->setSceneRect(rect);
    ui->view->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
