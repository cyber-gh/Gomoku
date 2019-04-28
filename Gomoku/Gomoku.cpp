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
	connect(ui.btnSkipTurn, SIGNAL(clicked()), this, SLOT(onBtnSkipTurnClicked()));
	connect(ui.btnResetGame, SIGNAL(clicked()), this, SLOT(onResetGameClicked()));
	connect(ui.btnSwapMode, SIGNAL(clicked()), this, SLOT(onBtnSwapModeClicked()));
	connect(ui.btnSwap2Mode, SIGNAL(clicked()), this, SLOT(onBtnSwapMode2Clicked()));
}
