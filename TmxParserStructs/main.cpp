#include "handler.h"
#include <QtGui>

layer l;
map mp;
tileset t;
tile ti;

int main(int argc, char **argv)
{





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
        int items = names.count();

        int durchgang = 0;

        for (int i = 0; i < items; ++i) {
            for (int j = 0; j < indentations[i]; ++j){
                std::cout << " ";
            }
            std::cout << names[i].toLocal8Bit().constData() << " " ;
            //weitere attribute printen(so viele wie vorhanden

            for(int y = 0; y < anzahl[i] ; y++){
                std::cout << attributeName[durchgang].toLocal8Bit().constData() << " = "<< attributes[durchgang].toLocal8Bit().constData() << "   ";
                durchgang++;
            }
            std::cout << std::endl;

        }

        imageloader il;
        QStringList sources;
        for(int x = 0; x < mp.tilesets.length();x++){
            sources.append(mp.tilesets[x].source);
        }
        QList <QImage> images;
       images = il.Loadtilesets(mp.tilesets.length(),sources);

       //Nur zum Testen       von
       for(int x = 0; x < sources.length();x++){
           qDebug() <<  QString("qrc:/") + sources.at(x);
       }
       //bis



    }
    std::cout << "Beendet"<<std::endl;
    return 0;
}
