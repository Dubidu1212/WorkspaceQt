#include "imageloader.h"


QList<QImage> imageloader::Loadtilesets(int tilesets,QStringList source){
    QList<QImage> imagesl;
    for(int x = 0; x < tilesets; x++){
        QImage image;
        image.load(QString(":/") + source.at(x));
        imagesl.append(image);
    }
    return imagesl;
}


// Qimage zum auseinanderschneiden und Qpixmap zum anzeigen
