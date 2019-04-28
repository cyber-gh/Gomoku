#include "stdafx.h"
#include "Gomoku.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GomokuClass w;
	w.show();
	return a.exec();
}
