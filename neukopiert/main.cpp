#include <qfile.h>
#include <qxml.h>
#include "handler.h"

#include <iostream>
struct tileset{
    int firstgid;
    QString name;
    int tilewidth;
    int tileheight;
    int tilecount;
    int columns;

};

struct map{


};
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
                std::cout << attributes[durchgang].toLocal8Bit().constData() << "   ";
                durchgang++;
            }
            std::cout << std::endl;

        }
    }

    return 0;
}
