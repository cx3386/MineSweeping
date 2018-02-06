#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_minesweeping.h"

class MineSweeping : public QMainWindow
{
	Q_OBJECT

public:
	MineSweeping(QWidget *parent = Q_NULLPTR);
	inline bool setMap(int mapWidth, int mapHeight, int mineCount)
	{
		if (mapWidth < 1 || mapHeight < 1 || mineCount >= mapHeight * mapWidth) return false;
		w = mapWidth; h = mapHeight; nMine = mineCount; return true;
	}
private:
	Ui::MineSweepingClass ui;
	bool newGame();
	QMap<int, int> generateMap() const;
	int w;
	int h;
	int nMine;
};
