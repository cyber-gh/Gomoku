#pragma once

#include <QtWidgets/QWidget>
#include "ui_Gomoku.h"
#include <QtCore\qt_windows.h>
#include <vector>
#include "Board.h"

const int DEFAULT_RADIUS = 10;

class GomokuClass : public QWidget
{
	Q_OBJECT

public:
	GomokuClass(QWidget* parent = Q_NULLPTR);

	bool gameLocked = false;
	bool gameStarted = false;
	bool swapMode = false;
	bool swapMode2 = false;
	bool promptToSwapColorsAfter2Moves = false;
	Board board;
	int playerToMove = 1;
	int moveCnt = 0;


private:
	Ui::GomokuClass ui;

protected:
	void swapPlayer();

	void mousePressEvent(QMouseEvent* event) override;

	void handeSwapMode2Moves(QPoint nextMove);

	void promptSwap2ModeOptions();

	void handeSwapModeMoves(QPoint nextMove);

	void promptToSwapPlayers();

	void handleMove(QPoint nextMove);
	void executeGameOver();

	void paintEvent(QPaintEvent* event) override;
	QPoint getClosestValidPosition(QPoint pos);

	void swapColors();


private slots:
	void onBtnSkipTurnClicked();
	void onResetGameClicked();
	void onBtnSwapModeClicked();
	void onBtnSwapMode2Clicked();


private:
	QPainter painter;
	QPixmap mPix;
	QRect mRect;
	QPoint mPoint;
	std::vector<std::pair<QPoint, Qt::GlobalColor>> points;
};
