/********************************************************************************
** Form generated from reading UI file 'mapwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWIDGET_H
#define UI_MAPWIDGET_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mapWidget
{
public:
    QGridLayout *gridLayout;
    QAxWidget *axWidget;

    void setupUi(QWidget *mapWidget)
    {
        if (mapWidget->objectName().isEmpty())
            mapWidget->setObjectName(QStringLiteral("mapWidget"));
        mapWidget->resize(788, 534);
        gridLayout = new QGridLayout(mapWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        axWidget = new QAxWidget(mapWidget);
        axWidget->setControl(QStringLiteral("{d27cdb6e-ae6d-11cf-96b8-444553540000}"));
        axWidget->setObjectName(QStringLiteral("axWidget"));

        gridLayout->addWidget(axWidget, 0, 0, 1, 1);


        retranslateUi(mapWidget);

        QMetaObject::connectSlotsByName(mapWidget);
    } // setupUi

    void retranslateUi(QWidget *mapWidget)
    {
        mapWidget->setWindowTitle(QApplication::translate("mapWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mapWidget: public Ui_mapWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWIDGET_H
