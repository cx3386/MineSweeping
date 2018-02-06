/********************************************************************************
** Form generated from reading UI file 'minesweeping.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINESWEEPING_H
#define UI_MINESWEEPING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MineSweepingClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MineSweepingClass)
    {
        if (MineSweepingClass->objectName().isEmpty())
            MineSweepingClass->setObjectName(QStringLiteral("MineSweepingClass"));
        MineSweepingClass->resize(600, 400);
        menuBar = new QMenuBar(MineSweepingClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MineSweepingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MineSweepingClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MineSweepingClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MineSweepingClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MineSweepingClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MineSweepingClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MineSweepingClass->setStatusBar(statusBar);

        retranslateUi(MineSweepingClass);

        QMetaObject::connectSlotsByName(MineSweepingClass);
    } // setupUi

    void retranslateUi(QMainWindow *MineSweepingClass)
    {
        MineSweepingClass->setWindowTitle(QApplication::translate("MineSweepingClass", "MineSweeping", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MineSweepingClass: public Ui_MineSweepingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINESWEEPING_H
