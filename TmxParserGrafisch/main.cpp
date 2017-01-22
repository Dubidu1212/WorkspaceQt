
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QPixmap>
#include <QGraphicsPixmapItem>
int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QGraphicsScene * scene = new QGraphicsScene();
  QGraphicsView * view = new QGraphicsView();
  QGraphicsPixmapItem * pixmap = new QGraphicsPixmapItem();

  pixmap->setPixmap(QPixmap(":/tileset/grass-tiles-2-small.png"));


  scene->addItem(pixmap);

  view->setScene(scene);
  view->show();
  return app.exec();
}
