#include <qfile.h>
#include <qxml.h>
#include "handler.h"

#include <iostream>

/*int allesBisHier(int z, QList <int> *anzahl){
    int alles=0;
    QList <int> LTemp = *anzahl;
    for(int y= 0;y<z;y++){

        alles += LTemp[y];
    }
    return alles;
}
*/
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
        //structs definieren
        /*
        durchgang = 0;
        for (int i = 0; i < items; ++i){
            if (names[i] == "map"){
               for(int x = 0 ;x < anzahl[i]; x++){
                   QList<int> *PtrAnzahl = &anzahl;
                    std::cout << "Beendet"<<std::endl;
                   if(attributeName[((allesBisHier(i,PtrAnzahl) - anzahl[i]) + x)] == "width"){///fehler hier

                       QString temp = attributeName[((allesBisHier(i,PtrAnzahl) - anzahl[i]) + x)];
                       map.width = temp.toInt();
                   }


               }
            }
        }*/






    }
    std::cout << "Beendet"<<std::endl;
    return 0;
}
