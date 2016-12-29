#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int x = 0;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void buttonPressed(int);
    void on_progressBar_valueChanged(int value);

signals:
    void buttonPressed(int);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
