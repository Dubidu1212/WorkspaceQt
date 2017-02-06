/*
 *
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}*/

#include "mainwindow.h"
#include "handler.h"
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <vector>
#include "tile.h"


map mp;
tileset t;
QList <QImage> gid;

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




    }
    MainWindow w;
    w.show();

    std::cout << "Beendet"<<std::endl;
    return app.exec();
}
