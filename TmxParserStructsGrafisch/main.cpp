#include "handler.h"
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <vector>


layer l;
map mp;
tileset t;
tile ti;

int main(int argc, char **argv)
{


    int höhe = 500; //!blidschirmgrösse
    QApplication app(argc,argv);
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsView * view = new QGraphicsView();
    QGraphicsPixmapItem * pixmapItem = new QGraphicsPixmapItem();



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
        //ddd

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


           /*
           for(int y = 0; y < mp.tilesets.at(x).tilecount; y++){//für jedes tile
               //tiles auseinanderschneiden und in gid liste eintragen

           }
*/

           int varY = 0;
           int tileheight = mp.tilesets.at(x).tileheight;
           std::cout << mp.tilesets.at(0).tilecount;
           //std::cout << mp.layers.at(0).tiles.at(0).gid << std::endl;
            //std::cout << mp.tilesets.at(x).name;
          // std::cout << mp.tilesets.at(x).tilecount /  mp.tilesets.at(x).columns;//fehler weil nicht richtig eingelesen
/*
           for(int z = 0; z< mp.tilesets.at(x).tilecount / mp.tilesets.at(x).columns; z++){

               int varX = 0;
               for(int y = 0; y < mp.tilesets.at(x).columns;y++){

                   gid.append(TempImage.copy(varX,varY,tileheight,tileheight));
                   varX += tileheight;
               }
               varY += tileheight;
           }

*/


       }









       QPixmap * pixmap = new QPixmap();
       pixmapItem->setPixmap(pixmap->fromImage(images.at(0)));

       scene->addItem(pixmapItem);

       //view->setSceneRect(0,0,höhe*16/9,höhe);
       view->setScene(scene);
       view->setWindowTitle("Game");//!gamename
       view->showFullScreen();//funktioniert nur wenn kein anderes programm fullscreen ist


    }


    std::cout << "Beendet"<<std::endl;
    return app.exec();
}
