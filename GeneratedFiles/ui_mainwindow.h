/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "WidgetPFD.h"
#include "videosdk_widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPID;
    QAction *action;
    QAction *actionhelp;
    QAction *actionsetCenter;
    QAction *actionstartRuler;
    QAction *actionclearRuler;
    QAction *actionmanual;
    QAction *actionAnto;
    QAction *actionswitch;
    QAction *actioneasy;
    QAction *actionhard;
    QAction *actioninit;
    QWidget *centralWidget;
    QPushButton *swtichButton;
    VideoSDK_Widget *widgetVideo;
    WidgetPFD *widgetPFD;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *temperature;
    QLabel *humidity;
    QLabel *voltage;
    QLabel *current;
    QLabel *pressure;
    QLabel *heading;
    QLabel *roll;
    QLabel *pitch;
    QLabel *led;
    QLabel *pantile;
    QLabel *lg;
    QLabel *la;
    QAxWidget *axWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_3;
    QMenu *menu_6;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1366, 769);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setStyleSheet(QStringLiteral("#MainWindow{border-image: url(:/images/background3.jpg);}"));
        actionPID = new QAction(MainWindow);
        actionPID->setObjectName(QStringLiteral("actionPID"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        actionhelp = new QAction(MainWindow);
        actionhelp->setObjectName(QStringLiteral("actionhelp"));
        actionsetCenter = new QAction(MainWindow);
        actionsetCenter->setObjectName(QStringLiteral("actionsetCenter"));
        actionstartRuler = new QAction(MainWindow);
        actionstartRuler->setObjectName(QStringLiteral("actionstartRuler"));
        actionclearRuler = new QAction(MainWindow);
        actionclearRuler->setObjectName(QStringLiteral("actionclearRuler"));
        actionmanual = new QAction(MainWindow);
        actionmanual->setObjectName(QStringLiteral("actionmanual"));
        actionAnto = new QAction(MainWindow);
        actionAnto->setObjectName(QStringLiteral("actionAnto"));
        actionswitch = new QAction(MainWindow);
        actionswitch->setObjectName(QStringLiteral("actionswitch"));
        actioneasy = new QAction(MainWindow);
        actioneasy->setObjectName(QStringLiteral("actioneasy"));
        actionhard = new QAction(MainWindow);
        actionhard->setObjectName(QStringLiteral("actionhard"));
        actioninit = new QAction(MainWindow);
        actioninit->setObjectName(QStringLiteral("actioninit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        swtichButton = new QPushButton(centralWidget);
        swtichButton->setObjectName(QStringLiteral("swtichButton"));
        swtichButton->setGeometry(QRect(0, 0, 51, 23));
        widgetVideo = new VideoSDK_Widget(centralWidget);
        widgetVideo->setObjectName(QStringLiteral("widgetVideo"));
        widgetVideo->setGeometry(QRect(960, 54, 383, 231));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetVideo->sizePolicy().hasHeightForWidth());
        widgetVideo->setSizePolicy(sizePolicy1);
        widgetVideo->setMinimumSize(QSize(200, 200));
        widgetVideo->setAutoFillBackground(false);
        widgetVideo->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 127);"));
        widgetPFD = new WidgetPFD(centralWidget);
        widgetPFD->setObjectName(QStringLiteral("widgetPFD"));
        widgetPFD->setGeometry(QRect(960, 310, 381, 311));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 10, 821, 22));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        temperature = new QLabel(horizontalLayoutWidget);
        temperature->setObjectName(QStringLiteral("temperature"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        temperature->setFont(font);
        temperature->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(temperature);

        humidity = new QLabel(horizontalLayoutWidget);
        humidity->setObjectName(QStringLiteral("humidity"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        humidity->setFont(font1);
        humidity->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(humidity);

        voltage = new QLabel(horizontalLayoutWidget);
        voltage->setObjectName(QStringLiteral("voltage"));
        voltage->setFont(font1);
        voltage->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(voltage);

        current = new QLabel(horizontalLayoutWidget);
        current->setObjectName(QStringLiteral("current"));
        current->setFont(font1);
        current->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(current);

        pressure = new QLabel(horizontalLayoutWidget);
        pressure->setObjectName(QStringLiteral("pressure"));
        pressure->setFont(font1);
        pressure->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pressure);

        heading = new QLabel(horizontalLayoutWidget);
        heading->setObjectName(QStringLiteral("heading"));
        heading->setFont(font1);
        heading->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(heading);

        roll = new QLabel(horizontalLayoutWidget);
        roll->setObjectName(QStringLiteral("roll"));
        roll->setFont(font1);
        roll->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(roll);

        pitch = new QLabel(horizontalLayoutWidget);
        pitch->setObjectName(QStringLiteral("pitch"));
        pitch->setFont(font1);
        pitch->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pitch);

        led = new QLabel(horizontalLayoutWidget);
        led->setObjectName(QStringLiteral("led"));
        led->setFont(font1);
        led->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(led);

        pantile = new QLabel(horizontalLayoutWidget);
        pantile->setObjectName(QStringLiteral("pantile"));
        pantile->setFont(font1);
        pantile->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pantile);

        lg = new QLabel(horizontalLayoutWidget);
        lg->setObjectName(QStringLiteral("lg"));
        lg->setFont(font1);
        lg->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(lg);

        la = new QLabel(horizontalLayoutWidget);
        la->setObjectName(QStringLiteral("la"));
        la->setFont(font1);
        la->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(la);

        axWidget = new QAxWidget(centralWidget);
        axWidget->setControl(QStringLiteral("{d27cdb6e-ae6d-11cf-96b8-444553540000}"));
        axWidget->setObjectName(QStringLiteral("axWidget"));
        axWidget->setProperty("geometry", QVariant(QRect(10, 50, 931, 621)));
        MainWindow->setCentralWidget(centralWidget);
        swtichButton->raise();
        widgetPFD->raise();
        widgetVideo->raise();
        horizontalLayoutWidget->raise();
        axWidget->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1366, 23));
        menuBar->setStyleSheet(QStringLiteral("background-color: rgb(128, 159, 197);"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_3 = new QMenu(menu_5);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_6 = new QMenu(menuBar);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QStringLiteral("background-color: rgb(143, 178, 220);"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menuBar->addAction(menu_6->menuAction());
        menu_2->addAction(actionhelp);
        menu_2->addAction(actionmanual);
        menu_2->addAction(actionAnto);
        menu_4->addAction(actionsetCenter);
        menu_4->addAction(actionstartRuler);
        menu_4->addAction(actionclearRuler);
        menu_4->addAction(actioninit);
        menu_5->addAction(actionswitch);
        menu_5->addAction(menu_3->menuAction());
        menu_3->addAction(actioneasy);
        menu_3->addAction(actionhard);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RoboFish-GCS 1.0", Q_NULLPTR));
        actionPID->setText(QApplication::translate("MainWindow", "PID", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\345\234\260\345\233\276", Q_NULLPTR));
        actionhelp->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256", Q_NULLPTR));
        actionsetCenter->setText(QApplication::translate("MainWindow", "\344\270\255\345\277\203\347\202\271", Q_NULLPTR));
        actionstartRuler->setText(QApplication::translate("MainWindow", "startRuler", Q_NULLPTR));
        actionclearRuler->setText(QApplication::translate("MainWindow", "clearRuler", Q_NULLPTR));
        actionmanual->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\346\250\241\345\274\217\357\274\210\351\273\230\350\256\244\357\274\211", Q_NULLPTR));
        actionAnto->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\250\241\345\274\217\357\274\210\350\247\204\345\210\222\350\267\257\345\276\204\357\274\211", Q_NULLPTR));
        actionswitch->setText(QApplication::translate("MainWindow", "\345\210\207\346\215\242", Q_NULLPTR));
        actioneasy->setText(QApplication::translate("MainWindow", "\347\256\200\346\230\223\346\216\247\344\273\266", Q_NULLPTR));
        actionhard->setText(QApplication::translate("MainWindow", "\345\244\215\346\235\202\346\216\247\344\273\266", Q_NULLPTR));
        actioninit->setText(QApplication::translate("MainWindow", "init", Q_NULLPTR));
        swtichButton->setText(QApplication::translate("MainWindow", "\345\210\207\346\215\242", Q_NULLPTR));
        temperature->setText(QApplication::translate("MainWindow", "temp", Q_NULLPTR));
        humidity->setText(QApplication::translate("MainWindow", "hum", Q_NULLPTR));
        voltage->setText(QApplication::translate("MainWindow", "voltage", Q_NULLPTR));
        current->setText(QApplication::translate("MainWindow", "current", Q_NULLPTR));
        pressure->setText(QApplication::translate("MainWindow", "pressure", Q_NULLPTR));
        heading->setText(QApplication::translate("MainWindow", "heading", Q_NULLPTR));
        roll->setText(QApplication::translate("MainWindow", "roll", Q_NULLPTR));
        pitch->setText(QApplication::translate("MainWindow", "pitch", Q_NULLPTR));
        led->setText(QApplication::translate("MainWindow", "led", Q_NULLPTR));
        pantile->setText(QApplication::translate("MainWindow", "pantile", Q_NULLPTR));
        lg->setText(QApplication::translate("MainWindow", "lg", Q_NULLPTR));
        la->setText(QApplication::translate("MainWindow", "la", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\345\234\260\345\233\276", Q_NULLPTR));
        menu_5->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\247\277\346\200\201\346\216\247\344\273\266", Q_NULLPTR));
        menu_6->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
