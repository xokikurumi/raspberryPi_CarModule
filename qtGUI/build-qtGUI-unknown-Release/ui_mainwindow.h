/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionendButton;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *tripLabel;
    QLabel *odoLabel;
    QLabel *tripTitle;
    QLabel *hymLabel;
    QLabel *odoTitle;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *tempLabel;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *fanL;
    QPushButton *usbR;
    QPushButton *usbL;
    QPushButton *fanR;
    QPushButton *tripA;
    QPushButton *tripReset;
    QPushButton *tripB;
    QPushButton *hazard;
    QPushButton *endBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setCursor(QCursor(Qt::BlankCursor));
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"border: solid 1px #000000;"));
        actionendButton = new QAction(MainWindow);
        actionendButton->setObjectName(QStringLiteral("actionendButton"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 0, 781, 231));
        gridLayoutWidget->setCursor(QCursor(Qt::BlankCursor));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tripLabel = new QLabel(gridLayoutWidget);
        tripLabel->setObjectName(QStringLiteral("tripLabel"));
        QFont font;
        font.setPointSize(15);
        tripLabel->setFont(font);
        tripLabel->setCursor(QCursor(Qt::BlankCursor));
        tripLabel->setLayoutDirection(Qt::LeftToRight);
        tripLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tripLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(tripLabel, 1, 1, 1, 1);

        odoLabel = new QLabel(gridLayoutWidget);
        odoLabel->setObjectName(QStringLiteral("odoLabel"));
        odoLabel->setFont(font);
        odoLabel->setCursor(QCursor(Qt::BlankCursor));
        odoLabel->setLayoutDirection(Qt::LeftToRight);
        odoLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        odoLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(odoLabel, 0, 1, 1, 1);

        tripTitle = new QLabel(gridLayoutWidget);
        tripTitle->setObjectName(QStringLiteral("tripTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tripTitle->sizePolicy().hasHeightForWidth());
        tripTitle->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        tripTitle->setFont(font1);
        tripTitle->setCursor(QCursor(Qt::BlankCursor));
        tripTitle->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tripTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(tripTitle, 1, 0, 1, 1);

        hymLabel = new QLabel(gridLayoutWidget);
        hymLabel->setObjectName(QStringLiteral("hymLabel"));
        hymLabel->setFont(font);
        hymLabel->setCursor(QCursor(Qt::BlankCursor));
        hymLabel->setLayoutDirection(Qt::LeftToRight);
        hymLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        hymLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(hymLabel, 3, 1, 1, 1);

        odoTitle = new QLabel(gridLayoutWidget);
        odoTitle->setObjectName(QStringLiteral("odoTitle"));
        sizePolicy.setHeightForWidth(odoTitle->sizePolicy().hasHeightForWidth());
        odoTitle->setSizePolicy(sizePolicy);
        odoTitle->setFont(font1);
        odoTitle->setCursor(QCursor(Qt::BlankCursor));
        odoTitle->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        odoTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(odoTitle, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font1);
        label_4->setCursor(QCursor(Qt::BlankCursor));
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);
        label_3->setCursor(QCursor(Qt::BlankCursor));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        tempLabel = new QLabel(gridLayoutWidget);
        tempLabel->setObjectName(QStringLiteral("tempLabel"));
        tempLabel->setFont(font);
        tempLabel->setCursor(QCursor(Qt::BlankCursor));
        tempLabel->setLayoutDirection(Qt::LeftToRight);
        tempLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tempLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(tempLabel, 2, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setFont(font1);
        label_9->setCursor(QCursor(Qt::BlankCursor));
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_9, 0, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setFont(font1);
        label_10->setCursor(QCursor(Qt::BlankCursor));
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_10, 1, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setFont(font1);
        label_11->setCursor(QCursor(Qt::BlankCursor));
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_11, 2, 2, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setFont(font1);
        label_12->setCursor(QCursor(Qt::BlankCursor));
        label_12->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_12, 3, 2, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 230, 781, 191));
        gridLayoutWidget_2->setCursor(QCursor(Qt::BlankCursor));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        fanL = new QPushButton(gridLayoutWidget_2);
        fanL->setObjectName(QStringLiteral("fanL"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fanL->sizePolicy().hasHeightForWidth());
        fanL->setSizePolicy(sizePolicy2);
        fanL->setFont(font1);
        fanL->setCursor(QCursor(Qt::BlankCursor));
        fanL->setStyleSheet(QLatin1String("background-color: rgb(63, 63, 63);\n"
"border: solid 1-x #FFFFFF;\n"
"color: #FFFFFF;"));

        gridLayout_2->addWidget(fanL, 3, 1, 1, 1);

        usbR = new QPushButton(gridLayoutWidget_2);
        usbR->setObjectName(QStringLiteral("usbR"));
        sizePolicy2.setHeightForWidth(usbR->sizePolicy().hasHeightForWidth());
        usbR->setSizePolicy(sizePolicy2);
        usbR->setFont(font1);
        usbR->setCursor(QCursor(Qt::BlankCursor));
        usbR->setStyleSheet(QLatin1String("background-color: rgb(63, 63, 63);\n"
"border: solid 1-x #FFFFFF;\n"
"color: #FFFFFF;"));

        gridLayout_2->addWidget(usbR, 3, 4, 1, 1);

        usbL = new QPushButton(gridLayoutWidget_2);
        usbL->setObjectName(QStringLiteral("usbL"));
        sizePolicy2.setHeightForWidth(usbL->sizePolicy().hasHeightForWidth());
        usbL->setSizePolicy(sizePolicy2);
        usbL->setFont(font1);
        usbL->setCursor(QCursor(Qt::BlankCursor));
        usbL->setStyleSheet(QLatin1String("background-color: rgb(63, 63, 63);\n"
"border: solid 1-x #FFFFFF;\n"
"color: #FFFFFF;"));

        gridLayout_2->addWidget(usbL, 3, 0, 1, 1);

        fanR = new QPushButton(gridLayoutWidget_2);
        fanR->setObjectName(QStringLiteral("fanR"));
        sizePolicy2.setHeightForWidth(fanR->sizePolicy().hasHeightForWidth());
        fanR->setSizePolicy(sizePolicy2);
        fanR->setFont(font1);
        fanR->setCursor(QCursor(Qt::BlankCursor));
        fanR->setStyleSheet(QLatin1String("background-color: rgb(63, 63, 63);\n"
"border: solid 1-x #FFFFFF;\n"
"color: #FFFFFF;"));

        gridLayout_2->addWidget(fanR, 3, 3, 1, 1);

        tripA = new QPushButton(gridLayoutWidget_2);
        tripA->setObjectName(QStringLiteral("tripA"));
        sizePolicy2.setHeightForWidth(tripA->sizePolicy().hasHeightForWidth());
        tripA->setSizePolicy(sizePolicy2);
        tripA->setFont(font1);
        tripA->setCursor(QCursor(Qt::BlankCursor));
        tripA->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"background-color: rgb(68, 68, 68);\n"
"border-color: solid 1px #FFFFFF;"));

        gridLayout_2->addWidget(tripA, 2, 3, 1, 1);

        tripReset = new QPushButton(gridLayoutWidget_2);
        tripReset->setObjectName(QStringLiteral("tripReset"));
        sizePolicy2.setHeightForWidth(tripReset->sizePolicy().hasHeightForWidth());
        tripReset->setSizePolicy(sizePolicy2);
        tripReset->setFont(font1);
        tripReset->setCursor(QCursor(Qt::BlankCursor));
        tripReset->setAutoFillBackground(false);
        tripReset->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"background-color: rgb(68, 68, 68);\n"
"border-color: solid 1px #FFFFFF;"));

        gridLayout_2->addWidget(tripReset, 2, 2, 1, 1);

        tripB = new QPushButton(gridLayoutWidget_2);
        tripB->setObjectName(QStringLiteral("tripB"));
        sizePolicy2.setHeightForWidth(tripB->sizePolicy().hasHeightForWidth());
        tripB->setSizePolicy(sizePolicy2);
        tripB->setFont(font1);
        tripB->setCursor(QCursor(Qt::BlankCursor));

        gridLayout_2->addWidget(tripB, 2, 4, 1, 1);

        hazard = new QPushButton(gridLayoutWidget_2);
        hazard->setObjectName(QStringLiteral("hazard"));
        sizePolicy2.setHeightForWidth(hazard->sizePolicy().hasHeightForWidth());
        hazard->setSizePolicy(sizePolicy2);
        hazard->setFont(font1);
        hazard->setCursor(QCursor(Qt::BlankCursor));
        hazard->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"background-color: rgb(63, 63, 63);\n"
"border: solid 1-x #FFFFFF;"));

        gridLayout_2->addWidget(hazard, 2, 0, 1, 1);

        endBtn = new QPushButton(gridLayoutWidget_2);
        endBtn->setObjectName(QStringLiteral("endBtn"));
        endBtn->setEnabled(false);
        sizePolicy2.setHeightForWidth(endBtn->sizePolicy().hasHeightForWidth());
        endBtn->setSizePolicy(sizePolicy2);
        endBtn->setCursor(QCursor(Qt::BlankCursor));

        gridLayout_2->addWidget(endBtn, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(endBtn, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionendButton->setText(QApplication::translate("MainWindow", "endButton", nullptr));
        tripLabel->setText(QApplication::translate("MainWindow", "00,000", nullptr));
        odoLabel->setText(QApplication::translate("MainWindow", "00,000", nullptr));
        tripTitle->setText(QApplication::translate("MainWindow", "Trip", nullptr));
        hymLabel->setText(QApplication::translate("MainWindow", "000", nullptr));
        odoTitle->setText(QApplication::translate("MainWindow", "Odo", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Humidity", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Temperature", nullptr));
        tempLabel->setText(QApplication::translate("MainWindow", "00.00", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "km", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "km", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "C", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "%", nullptr));
        fanL->setText(QApplication::translate("MainWindow", "FAN", nullptr));
        usbR->setText(QApplication::translate("MainWindow", "USB", nullptr));
        usbL->setText(QApplication::translate("MainWindow", "USB", nullptr));
        fanR->setText(QApplication::translate("MainWindow", "FAN", nullptr));
        tripA->setText(QApplication::translate("MainWindow", "TripA", nullptr));
        tripReset->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        tripB->setStyleSheet(QApplication::translate("MainWindow", "color: rgb(255, 0, 0);\n"
"background-color: rgb(68, 68, 68);\n"
"border-color: solid 1px #FFFFFF;", nullptr));
        tripB->setText(QApplication::translate("MainWindow", "TripB", nullptr));
        hazard->setText(QApplication::translate("MainWindow", "Hazard", nullptr));
        endBtn->setText(QApplication::translate("MainWindow", "end", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
