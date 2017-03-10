#ifndef VIEWO_H
#define VIEWO_H
#include <QGraphicsView>
#include <QDebug>
#include <QList>
class viewo: public QGraphicsView
{
public:
    viewo(QWidget * parent);
    QList<char> events;

protected:
void wheelEvent ( QWheelEvent * event );
void keyPressEvent(QKeyEvent * event);
void keyReleaseEvent(QKeyEvent * event);
};

#endif // VIEWO_H
