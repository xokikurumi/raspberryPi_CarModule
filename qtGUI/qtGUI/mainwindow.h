#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtGui>
#include <iostream>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_hazard_clicked();

    void on_usbL_clicked();

    void on_fanL_clicked();

    void on_fanR_clicked();

    void on_usbR_clicked();

    void on_tripA_clicked();

    void on_tripB_clicked();

    void on_tripReset_clicked();

    void changeTrip();

    void update();

private:
    Ui::MainWindow *ui;
    class QTimer* myTimer;
    QSqlDatabase db;

};

#endif // MAINWINDOW_H
