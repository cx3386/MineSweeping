#include "stdafx.h"
#include "MineSweeper.h"
#include "MineButton.h"

MineSweeper::MineSweeper(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);

	// action
	auto newAction = new QAction(tr("&New"), this);
	newAction->setShortcut(QKeySequence::New);
	connect(newAction, &QAction::triggered, this, &MineSweeper::newGame);
	auto exitAction = new QAction(tr("&Exit"), this);
	exitAction->setShortcuts(QKeySequence::Quit);
	exitAction->setShortcuts(QKeySequence::Cancel);
	connect(exitAction, &QAction::triggered, this, &MineSweeper::close);

	// menu
	auto startMenu = ui.menuBar->addMenu(tr("&Start"));
	startMenu->addAction(newAction);
	startMenu->addAction(exitAction);
}

bool MineSweeper::newGame()
{
	bool ok;
	auto in_w = QInputDialog::getInt(this, tr("input"), tr("width"), 9, 9, 30, 1, &ok);
	auto in_h = QInputDialog::getInt(this, tr("input"), tr("height"), 9, 9, 24, 1, &ok);
	auto in_c = QInputDialog::getInt(this, tr("input"), tr("mine number"), 10, 10, (in_w - 1)*(in_h - 1), 1, &ok);
	if (!setMap(in_w, in_h, in_c))
		return false;
	auto minesMap = newMap();
	auto layout = new QGridLayout;
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			MineButton *btn = new MineButton(this);
			btn->setFixedSize(20, 20);
			btn->setNumber(minesMap.value(i*w + j));
			btn->setObjectName(QString("%1, %2").arg(i).arg(j));
			layout->addWidget(btn, i, j);
		}
	}
	layout->setVerticalSpacing(0);
	layout->setHorizontalSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	ui.centralWidget->setLayout(layout);
}

QMap<int, int> MineSweeper::newMap() const
{
	int area = w * h;
	QMap<int, int> map;

	// add nMine random mines to the map
	while (map.size() != nMine)
	{
		qsrand(QTime::currentTime().msecsSinceStartOfDay());
		int mine = qrand() % area;
		if (map.contains(mine))
		{
			continue;
		}
		map[mine] = -1;
	}

	// calculate the number of each location
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			if (!map.contains(i*w + j))
			{
				/// judge if the around has mine
				int count = 0;
				// up line
				if (i > 0)
				{
					if (j > 0)
					{
						if (map.value((i - 1)*w + j - 1) == -1) count++;
					}
					if (map.value((i - 1)*w + j) == -1) count++;
					if (j < h - 1)
					{
						if (map.value((i - 1)*w + j + 1) == -1) count++;
					}
				}
				// self line
				if (j > 0)
				{
					if (map.value(i*w + j - 1) == -1) count++;
				}
				if (j < h - 1)
				{
					if (map.value(i*w + j + 1) == -1) count++;
				}
				// down line
				if (i < w - 1)
				{
					if (j > 0)
					{
						if (map.value((i + 1)*w + j - 1) == -1) count++;
					}
					if (map.value((i + 1)*w + j) == -1) count++;
					if (j < h - 1)
					{
						if (map.value((i + 1)*w + j + 1) == -1) count++;
					}
				}
				map[i*w + j] = count;
			}
		}
	}
	return map;
}