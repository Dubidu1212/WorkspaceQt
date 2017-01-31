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


           int rows = mp.tilesets.at(x).tilecount /  mp.tilesets.at(x).columns;//fehler weil nicht richtig eingelesen

           for(int z = 0; z< rows; z++){

               int varX = 0;
               for(int y = 0; y < mp.tilesets.at(x).columns;y++){

                   gid.append(TempImage.copy(varX,varY,tileheight,tileheight));
                   varX += tileheight;
               }
               varY += tileheight;

           }





       }









       QPixmap * pixmap = new QPixmap();
       QGraphicsScene * scene = new QGraphicsScene();
       QGraphicsView * view = new QGraphicsView();
       QGraphicsPixmapItem * pixmapItem = new QGraphicsPixmapItem();

        scene->setSceneRect(0,0,1000,1000);
      // pixmapItem->setPixmap(pixmap->fromImage(images.at(0)));

       for(int x = 0; x < 10;x++){//nur zum test

           QPoint point(x*gid.at(0).height(), x*gid.at(0).height());

           Dtile * dt = new Dtile(gid.at(x),point);
           scene->addItem(dt);

       }





       QBrush brush;
       brush.setColor(QColor(200,10,10,255));

       scene->setBackgroundBrush(brush);
       view->setScene(scene);
       view->setWindowTitle("Game");//!gamename
       view->show();
       //view->showFullScreen();//funktioniert nur wenn kein anderes programm fullscreen ist


    }


    std::cout << "Beendet"<<std::endl;
    return app.exec();
}
