#include "stdafx.h"
#include "minesweeping.h"

MineSweeping::MineSweeping(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);

	// action
	auto newAction = new QAction(tr("&New"), this);
	newAction->setShortcut(QKeySequence::New);
	connect(newAction, &QAction::triggered, this, &MineSweeping::newGame);
	auto exitAction = new QAction(tr("&Exit"), this);
	exitAction->setShortcuts(QKeySequence::Quit);
	exitAction->setShortcuts(QKeySequence::Cancel);
	connect(exitAction, &QAction::triggered, this, &MineSweeping::close);

	// menu
	auto startMenu = ui.menuBar->addMenu(tr("&Start"));
	startMenu->addAction(newAction);
	startMenu->addAction(exitAction);
}

bool MineSweeping::newGame()
{
	bool ok;
	auto in_w = QInputDialog::getInt(this, tr("input"), tr("width"), 10, 1, 100, 1, &ok);
	auto in_h = QInputDialog::getInt(this, tr("input"), tr("height"), 10, 1, 100, 1, &ok);
	auto in_c = QInputDialog::getInt(this, tr("input"), tr("mine number"), 10, 1, 10000, 1, &ok);
	if (!setMap(in_w, in_h, in_c))
		return false;
	auto map = generateMap();
	auto layout = new QGridLayout;
	layout->setVerticalSpacing(0);
	layout->setHorizontalSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	for (int i = 0; i < map.size(); ++i)
	{
		QPushButton *btn = new QPushButton(this);
		btn->setFixedSize(20, 20);
		btn->setText(QString::number(map.value(i)));
		layout->addWidget(btn, i / w, i%w);
	}
	ui.centralWidget->setLayout(layout);
}

QMap<int, int> MineSweeping::generateMap() const
{
	int area = w * h;
	QMap<int, int> map;  //if value is -1, the place has mine;
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
	auto mines = map.keys();  // mines' list
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