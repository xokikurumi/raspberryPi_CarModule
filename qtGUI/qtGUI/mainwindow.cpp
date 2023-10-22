#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
bool viewTripA = true;
bool hazard = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    changeTrip();
    if(hazard){

        ui->hazard->setStyleSheet(ENABLED_BTN);
    }else {

        ui->hazard->setStyleSheet(DISABLED_BTN);
    }

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/pi/wk/raspberryPi_CarModule/python/carDB.sqlite3");
    myTimer = new QTimer();
    connect(myTimer, SIGNAL(timeout()), SLOT(update()));
    myTimer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hazard_clicked()
{
// Hazard Button
    if(hazard){
        hazard = false;
        ui->hazard->setStyleSheet(DISABLED_BTN);
    }else {
        hazard = true;
        ui->hazard->setStyleSheet(ENABLED_BTN);
    }
}

void MainWindow::on_usbL_clicked()
{
// USB Left Button

}

void MainWindow::on_fanL_clicked()
{
// FAN Left Button
}

void MainWindow::on_fanR_clicked()
{
// FAN Right Button
}

void MainWindow::on_usbR_clicked()
{
// USB Right Button
}

void MainWindow::on_tripA_clicked()
{
// Trip A View Button
// Default: True
    viewTripA = true;
    changeTrip();
}

void MainWindow::on_tripB_clicked()
{
// Trip B View Button
// Default: False
    viewTripA = false;
    changeTrip();
}

void MainWindow::on_tripReset_clicked()
{
// Trip Reset Button
// Viewed Trip Reset.
}
void MainWindow::changeTrip(){
    if(viewTripA){
        ui->tripTitle->setText(UI_TRIP_A_TITLE_LABEL);
        ui->tripA->setStyleSheet(ENABLED_BTN);
        ui->tripB->setStyleSheet(DISABLED_BTN);

    }else{
        ui->tripTitle->setText(UI_TRIP_B_TITLE_LABEL);
        ui->tripA->setStyleSheet(DISABLED_BTN);
        ui->tripB->setStyleSheet(ENABLED_BTN);
    }
}

//UPDATE
void MainWindow::update(){

    db.open();

    QSqlQuery query(db);
    query.exec(ODO_QUERY);
    while(query.next()){
        QString odo = query.value(0).toString();
        ui->odoLabel->setText(odo);

        qDebug() << odo;
    }

    if(viewTripA){
        query.exec(TRIP_A_QUERY);
        while(query.next()){
            QString odo = query.value(0).toString();
            ui->tripLabel->setText(odo);
            qDebug() << odo;
        }
    }else{
        query.exec(TRIP_B_QUERY);
        while(query.next()){
            QString odo = query.value(0).toString();
            ui->tripLabel->setText(odo);
            qDebug() << odo;
        }
    }

    query.exec(TEMP_QUERY);
    while(query.next()){
        QString odo = query.value(0).toString();
        ui->tempLabel->setText(odo);
        qDebug() << odo;
    }

    query.exec(HUM_QUERY);
    while(query.next()){
        QString odo = query.value(0).toString();
        ui->hymLabel->setText(odo);
        qDebug() << odo;
    }

    query.exec(STATUS_LEVEL_QUERY);
    while(query.next()){
        int odo = query.value(0).toInt();
        switch (odo){
            case 5:
            ui->label_3->setStyleSheet(STATUS_LEVEL_5);
            ui->tempLabel->setStyleSheet(STATUS_LEVEL_5);
            ui->label_11->setStyleSheet(STATUS_LEVEL_5);

            ui->label_4->setStyleSheet(STATUS_LEVEL_5);
            ui->hymLabel->setStyleSheet(STATUS_LEVEL_5);
            ui->label_12->setStyleSheet(STATUS_LEVEL_5);
                break;
        case 4:
            ui->label_3->setStyleSheet(STATUS_LEVEL_4);
            ui->tempLabel->setStyleSheet(STATUS_LEVEL_4);
            ui->label_11->setStyleSheet(STATUS_LEVEL_4);

            ui->label_4->setStyleSheet(STATUS_LEVEL_4);
            ui->hymLabel->setStyleSheet(STATUS_LEVEL_4);
            ui->label_12->setStyleSheet(STATUS_LEVEL_4);
            break;
        case 3:
            ui->label_3->setStyleSheet(STATUS_LEVEL_3);
            ui->tempLabel->setStyleSheet(STATUS_LEVEL_3);
            ui->label_11->setStyleSheet(STATUS_LEVEL_3);

            ui->label_4->setStyleSheet(STATUS_LEVEL_3);
            ui->hymLabel->setStyleSheet(STATUS_LEVEL_3);
            ui->label_12->setStyleSheet(STATUS_LEVEL_3);
            break;
        case 2:
            ui->label_3->setStyleSheet(STATUS_LEVEL_2);
            ui->tempLabel->setStyleSheet(STATUS_LEVEL_2);
            ui->label_11->setStyleSheet(STATUS_LEVEL_2);

            ui->label_4->setStyleSheet(STATUS_LEVEL_2);
            ui->hymLabel->setStyleSheet(STATUS_LEVEL_2);
            ui->label_12->setStyleSheet(STATUS_LEVEL_2);
            break;
        case 1:
            ui->label_3->setStyleSheet(STATUS_LEVEL_1);
            ui->tempLabel->setStyleSheet(STATUS_LEVEL_1);
            ui->label_11->setStyleSheet(STATUS_LEVEL_1);

            ui->label_3->setStyleSheet(STATUS_LEVEL_1);
            ui->hymLabel->setStyleSheet(STATUS_LEVEL_1);
            ui->label_12->setStyleSheet(STATUS_LEVEL_1);
            break;
        }
        qDebug() << odo;
    }


    db.close();
}
