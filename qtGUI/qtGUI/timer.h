#ifndef TIMER_H
#define TIMER_H
#include<QtWidgets/QMainWindow>
#include "mainwindow.h"

class Timer: public QMainWindow
{
    Q_OBJECT

public:
    Timer(QWidget *parent = Q_NULLPTR);
    ~Timer();

private:
    Ui::MainWindow ui;
    class QTimer* timer;

};

#endif // TIMER_H
