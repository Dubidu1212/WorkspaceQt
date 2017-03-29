#ifndef VIEWO_H
#define VIEWO_H
#include <QGraphicsView>
#include <QDebug>
#include <QList>
#include <QObject>
#include "enemy.h"
#include <QColor>
class viewo: public QGraphicsView
{

public:
    viewo(QWidget * parent);
    QList<char> events;


protected:
    void wheelEvent ( QWheelEvent * event );
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void mousePressEvent(QMouseEvent * event);


};

#endif // VIEWO_H
