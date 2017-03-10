
#include "mainwindow.h"
#include "handler.h"
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <vector>
#include "tile.h"
#include <QFontDatabase>
#include "player.h"
#include <QGraphicsItem>
#include <thread>
#include <updater.h>
#include "viewo.h"

map mp;
tileset t;
QList <QImage> gid;
QFont dfont;
pressed controls;
Player * pl;
QList  <QGraphicsItem*> colisionList;

//!habe bei .pro controler.h und .cpp entfernt
void tilecreator(){
    imageloader il;
    QStringList sources;
    for(int x = 0; x < mp.tilesets.length();x++){
        sources.append(mp.tilesets[x].source);
    }

    QList <QImage> images;
   images = il.Loadtilesets(mp.tilesets.length(),sources);
    for(int x = 0; x < mp.tilesets.length(); x++){//jedes tileset durchläuft diesen prozess
        QImage TempImage = images.at(x); //sind source
        int varY = 0;
        int tileheight = mp.tilesets.at(x).tileheight;


        int rows = mp.tilesets.at(x).tilecount /  mp.tilesets.at(x).columns;

        for(int z = 0; z < rows; z++){

            int varX = 0;
            for(int y = 0; y < mp.tilesets.at(x).columns ;y++){

                gid.append(TempImage.copy(varX,varY,tileheight,tileheight));
                //std::cout << tileheight << std::endl;
                varX += tileheight;
            }
            varY += tileheight;

        }





    }
}







int main(int argc, char **argv)
{
    std::cout <<"gestartet"<<std::endl;
    //Problem ist beim einlesen
    int höhe = 500; //!blidschirmgrösse
    QApplication app(argc,argv);
    QFontDatabase::addApplicationFont(":/fonts/ENDOR___.ttf");

    dfont.setFamily("ENDOR");
    app.setFont(dfont);




    QFile *file = new QFile(":/xml/qqdd.tmx");


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

        //liste mit allen tiles erstellen ( gid )
       tilecreator();

    }
    controls.down = false;
    controls.up = false;
    controls.left = false;
    controls.right = false;


    pl = new Player(QRect(0,0,64,64));

    //pl->setPixmap(QPixmap().fromImage( QImage(":/sprites/Arm_front.png").copy(0,0,64,64)));

    pl->setVisible(true);

    updater * updat = new updater(10);
    pl->setPos(50,50);
    pl->setScale(1);

    MainWindow w;
    updat->Dvi = w.View();
    w.show();









    std::cout << "Beendet"  <<std::endl;


    return app.exec();


}
