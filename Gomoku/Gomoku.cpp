#include "stdafx.h"
#include "Gomoku.h"
#include "ui_Gomoku.h"
#include "Board.h"

GomokuClass::GomokuClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//setMouseTracking(true);
	mPix = QPixmap(670, 800);
	mPix.fill(Qt::white);
	board = Board();
}
