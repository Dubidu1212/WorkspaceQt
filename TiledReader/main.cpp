#include "handler.h"
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <vector>
#include "tile.h"
#include <QBrush> //test
#include <QColor> //test

map mp;
tileset t;


int main(int argc, char **argv)
{
    std::cout <<"gestartet"<<std::endl;
    //Problem ist beim einlesen
    int höhe = 500; //!blidschirmgrösse
    QApplication app(argc,argv);




    QFile *file = new QFile(":/xml/example.tmx");


    QXmlSimpleReader xmlReader;
    QXmlInputSource *source = new QXmlInputSource(file);



    Handler *handler = new Handler;
    xmlReader.setContentHandler(handler);
    xmlReader.setErrorHandler(handler);



    bool ok = xmlReader.parse(source);

    if (!ok)
        std::cout << "Parsing failed." << std::endl;

    else {
        QStringList names = handler->names();
        QStringList attributes = handler->attributes();
        QStringList attributeName = handler->attributeName();
        QList<int> indentations = handler->indentations();
        QList<int> anzahl = handler->anzahl();


        imageloader il;
        QStringList sources;
        for(int x = 0; x < mp.tilesets.length();x++){
            sources.append(mp.tilesets[x].source);
        }

        QList <QImage> images;
       images = il.Loadtilesets(mp.tilesets.length(),sources);
        //liste mit allen tiles erstellen ( gid )

       QList <QImage> gid;
       

       for(int x = 0; x < mp.tilesets.length(); x++){//jedes tileset durchläuft diesen prozess
           QImage TempImage = images.at(x); //sind source
           int varY = 0;
           int tileheight = mp.tilesets.at(x).tileheight;


           int rows = mp.tilesets.at(x).tilecount /  mp.tilesets.at(x).columns;

           for(int z = 0; z < rows; z++){

               int varX = 0;
               for(int y = 0; y < mp.tilesets.at(x).columns ;y++){

                   gid.append(TempImage.copy(varX,varY,tileheight,tileheight));
                   std::cout << tileheight << std::endl;
                   varX += tileheight;
               }
               varY += tileheight;

           }





       }









       QPixmap * pixmap = new QPixmap();
       QGraphicsScene * scene = new QGraphicsScene();
       QGraphicsView * view = new QGraphicsView();
       QGraphicsPixmapItem * pixmapItem = new QGraphicsPixmapItem();
        view->setScene(scene);
        scene->setSceneRect(0,0,800,600);
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

       view->setWindowTitle("Game");//!gamename
       //view->setFixedSize(800,600);
       //view->show();
       view->showFullScreen();//funktioniert nur wenn kein anderes programm fullscreen ist


    }


    std::cout << "Beendet"<<std::endl;
    return app.exec();
}
