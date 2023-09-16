//
// Created by xokikurumi on 2023/08/21.
//

#ifndef QT_MAINWINDOW_H
#define QT_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);

    ~mainWindow() override;

private:
    Ui::mainWindow *ui;
};


#endif //QT_MAINWINDOW_H
