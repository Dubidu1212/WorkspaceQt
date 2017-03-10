#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QFont>
#include <QPixmap>
#include <QGraphicsItem>

struct frame{
    int tileid;//das selbe wie gid
    int duration;//milisekunden
};

struct animation{
    QList<frame> frames;//bilder
};


struct tile{//eine einzelne kachel auf einer bestimmten ebenen
    int gid;
    bool colision;
};



struct tileset{//speicher der
    int firstgid;//!wird nicht eingelesen
    QString source;
    QString name;
    int tilewidth;
    int tileheight;
    int tilecount;
    int columns;

};
extern tileset t;

struct layer{//schicht der map
    QString name;
    int width;
    int height;
    QList<tile> tiles;

};


struct property{
    QString name;
    QString type;//!function templates(sololearn)
    QString value;
};
struct object{
    int id;
    int x;
    int y;
    int widht;
    int height;
};

struct objectgroup{//zb kolisonsobjekte
    QList<object> objects;
};

struct map{

    QList<tileset> tilesets;
    QList<layer> layers;
    QList<property> propertyes;
    QList<objectgroup> objectgroups;
    int width;
    int height;
};
extern map mp;
extern QList <QImage> gid;
extern QFont dfont;
extern QList  <QGraphicsItem*> colisionList;

struct pressed{
    bool up;
    bool down;
    bool left;
    bool right;
    bool space;

};
extern pressed controls;



struct Dspritesheet{
    QImage image;
    int tilecount;
    QString name;
};
struct Action{
    QString type;
    QList<InfoString> Text;
    QList<InfoInt> ints;

};
struct InfoString{
    QString type;
    QString text;
};
struct InfoInt{
     QString type;
     int number;
};

#endif // STRUCTS_H
