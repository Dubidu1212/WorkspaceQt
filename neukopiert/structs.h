#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
struct frame{
    int tileid;//das selbe wie gid
    int duration;//milisekunden
};

struct animation{
    QList<frame> frames;//bilder
};

struct terain{//eine art von terain
    QString name;
    int tileid;
};

struct teraintypes{//ansamlung aller terains
    QList<terain> terains;
};

struct tile{//eine einzelne kachel auf einer bestimmten ebenen
    int gid;
    terain tileTerain;
};


struct tileset{//speicher der
    int firstgid;
    QString source;
    QString name;
    int tilewidth;
    int tileheight;
    int tilecount;
    int columns;

};
struct data{
    QList<tile> tiles;
};

struct layer{//schicht der map
    QString name;
    int width;
    int height;
    data datas;

};
struct property{
    QString name;
    QString type;//function templates(sololearn)
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

};




#endif // STRUCTS_H
