#ifndef UPDATER_H
#define UPDATER_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class updater: public QObject{
    Q_OBJECT
public:
    updater(int time);
public slots:
    void update();
};

#endif // UPDATER_H
