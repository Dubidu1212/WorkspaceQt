#include "mainwindow.h"
#include <QApplication>
#include <QpushButton>
#include <string>
#include <QProgressBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton button ("Klick mich");
    button.setToolTip("Alda");


    button.show();
    return a.exec();
}
