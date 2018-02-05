#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_minesweeping.h"

class MineSweeping : public QMainWindow
{
	Q_OBJECT

public:
	MineSweeping(QWidget *parent = Q_NULLPTR);

private:
	Ui::MineSweepingClass ui;
};
