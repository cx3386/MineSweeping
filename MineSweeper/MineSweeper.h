#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_minesweeper.h"

class MineSweeper : public QMainWindow
{
	Q_OBJECT

public:
	MineSweeper(QWidget *parent = Q_NULLPTR);
	inline bool setMap(int mapWidth, int mapHeight, int mineCount)
	{
		if (mapWidth < 1 || mapHeight < 1 || mineCount >= mapHeight * mapWidth) return false;
		w = mapWidth; h = mapHeight; nMine = mineCount; return true;
	}
private:
	Ui::minesweeperClass ui;
	bool newGame();
	/**
	 * \brief generate a random mines map.
	 * key is the location, value is the number; if number=-1, this location has mine;
	 *
	 */
	QMap<int, int> newMap() const;
	int w;
	int h;
	int nMine;
};
