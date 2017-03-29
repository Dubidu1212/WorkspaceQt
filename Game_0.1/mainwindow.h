#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "viewo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent *event);


    Ui::MainWindow *ui;


    viewo* View();

    void AddItem(QGraphicsItem *item, int scene);

protected:

};

#endif // MAINWINDOW_H
