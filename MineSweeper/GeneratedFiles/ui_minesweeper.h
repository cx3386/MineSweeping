/********************************************************************************
** Form generated from reading UI file 'minesweeper.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINESWEEPER_H
#define UI_MINESWEEPER_H

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

class Ui_minesweeperClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *minesweeperClass)
    {
        if (minesweeperClass->objectName().isEmpty())
            minesweeperClass->setObjectName(QStringLiteral("minesweeperClass"));
        minesweeperClass->resize(600, 400);
        menuBar = new QMenuBar(minesweeperClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        minesweeperClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(minesweeperClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        minesweeperClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(minesweeperClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        minesweeperClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(minesweeperClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        minesweeperClass->setStatusBar(statusBar);

        retranslateUi(minesweeperClass);

        QMetaObject::connectSlotsByName(minesweeperClass);
    } // setupUi

    void retranslateUi(QMainWindow *minesweeperClass)
    {
        minesweeperClass->setWindowTitle(QApplication::translate("minesweeperClass", "minesweeper", nullptr));
    } // retranslateUi

};

namespace Ui {
    class minesweeperClass: public Ui_minesweeperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINESWEEPER_H
