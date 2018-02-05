#include "stdafx.h"
#include "minesweeping.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MineSweeping w;
	w.show();
	return a.exec();
}
