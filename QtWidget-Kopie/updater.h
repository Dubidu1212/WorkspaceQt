#ifndef UPDATER_H
#define UPDATER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include "viewo.h"

class updater: public QObject{
    Q_OBJECT
public:
    updater(int time);
    viewo * Dvi;
public slots:
    void update();
};

#endif // UPDATER_H
