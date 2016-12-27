#ifndef TMXVIEWER_H
#define TMXVIEWER_H

#include <QGraphicsView>

namespace Tiled {
class Map;
class MapRenderer;
}

class TmxViewer : public QGraphicsView
{
    Q_OBJECT

public:
    explicit TmxViewer(QWidget *parent = nullptr);
    ~TmxViewer();

    bool viewMap(const QString &fileName);

private:
    QGraphicsScene *mScene;
    Tiled::Map *mMap;
    Tiled::MapRenderer *mRenderer;
};

#endif // TMXVIEWER_H
