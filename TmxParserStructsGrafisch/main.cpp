#include "handler.h"
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>


layer l;
map mp;
tileset t;
tile ti;

int main(int argc, char **argv)
{



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


        imageloader il;
        QStringList sources;
        for(int x = 0; x < mp.tilesets.length();x++){
            sources.append(mp.tilesets[x].source);
        }
        QList <QImage> images;
       images = il.Loadtilesets(mp.tilesets.length(),sources);



       QPixmap * pixmap = new QPixmap();
       pixmapItem->setPixmap(pixmap->fromImage(images.at(0)));

       scene->addItem(pixmapItem);
       view->setScene(scene);
       view->show();

    }


    std::cout << "Beendet"<<std::endl;
    return app.exec();
}
