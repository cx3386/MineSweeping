#include "stdafx.h"
#include "MineButton.h"

MineButton::MineButton(QWidget *parent)
	: QPushButton(parent), opened(false), marked(false)
{
	connect(this, &QPushButton::clicked, this, [&]
	{
		if (!opened && !marked)
		{
			switch (number)
			{
			case -1:
				this->setIcon(QIcon(":/minesweeper/Resources/mine.png"));
				emit boom();
				break;
			case 0:
				emit zeroClick();
			default:
				this->setText(QString::number(number));
				break;
			}
			opened = true;
		}
	});
}

MineButton::~MineButton()
= default;

void MineButton::contextMenuEvent(QContextMenuEvent *event)
{
	if (opened)
		return;
	static int state = 0;
	++state;
	if (state == 3)
	{
		state = 0;
	}
	switch (state)
	{
	case 0:
		this->setIcon(QIcon());
		marked = false;
		break;
	case 1:
		this->setIcon(QIcon(":/minesweeper/Resources/flag.png"));
		marked = true;
		break;
	case 2:
		this->setIcon(QIcon(":/minesweeper/Resources/question.png"));
		marked = true;
		break;
	}
}