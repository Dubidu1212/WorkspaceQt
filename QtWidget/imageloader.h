#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QPixmap>
#include <QImage>
#include <QFile>
#include <QStringList>
class imageloader{
public:
    QList<QImage> Loadtilesets(int,QStringList);
};


#endif // IMAGELOADER_H
