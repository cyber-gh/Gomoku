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
	Board board;
	int playerToMove = 1;
	int moveCnt = 0;


private:
	Ui::GomokuClass ui;

protected:
	void swapPlayer() {
		if (playerToMove == 1) playerToMove = 2;
		else playerToMove = 1;
	}

	void mousePressEvent(QMouseEvent * event) override {

		if (event->pos().x() <= 670 && event->pos().y() <= 610) {
			
			if (!gameLocked) handleMove(getClosestValidPosition(event->pos()));
			else if (swapMode) {
				handeSwapModeMoves(getClosestValidPosition(event->pos()));
			}
			if (!gameStarted && !swapMode) gameStarted = true;
			update();
		}
	}

	void handeSwapModeMoves(QPoint nextMove) {
		moveCnt++;

		if (moveCnt == 3) swapPlayer();
		std::pair<int, int> move;
		move.first = nextMove.x() / 30;
		move.second = nextMove.y() / 30;
		if (board.placeStone(move, playerToMove)) {
			points.push_back(std::make_pair(nextMove, (playerToMove == 1 ? Qt::black : Qt::red)));
		}
		if (moveCnt == 3) {
			swapMode = false;
			gameLocked = false;
			gameStarted = true;
			promptToSwapPlayers();
		}
	}

	void promptToSwapPlayers() {
		QMessageBox::StandardButton reply;

		reply = QMessageBox::question(this, "Swap", "Do you want to swap colors?",
			QMessageBox::Yes |QMessageBox::Cancel);

		if (reply == QMessageBox::Yes) {
			board.swapColors();
			this->swapColors();
			swapPlayer();
			update();
		}
		if (reply == QMessageBox::Cancel){
			qDebug() << "cancel clicked";
		}

	}

	void handleMove(QPoint nextMove) {
		std::pair<int, int> move;
		move.first = nextMove.x() / 30;
		move.second = nextMove.y() / 30;
		if (board.placeStone(move, playerToMove)) {
			points.push_back(std::make_pair(nextMove, (playerToMove == 1 ? Qt::black : Qt::red)));
			swapPlayer();
			if (board.gameOver()) executeGameOver();
		}
	}
	void executeGameOver() {
		QMessageBox msg;
		msg.setFixedWidth(200);//TODO needs fixing 
		int winningPlayer = board.whoWon();
		msg.setText("Winning Player: " + winningPlayer);
		msg.exec();
		gameLocked = true;
	}

	void paintEvent(QPaintEvent * event) override {
		QPainter painter(this);
		painter.setPen(QPen(Qt::black, 3));
		for (int x = 10; x <= 670; x += 30) {

			painter.drawLine(x, 10, x, 610);
		}
		for (int y = 10; y <= 610; y += 30) {
			painter.drawLine(10, y, 670, y);
		}

		for (auto it : points) {
			painter.setBrush(it.second);
			painter.drawEllipse(it.first, DEFAULT_RADIUS, DEFAULT_RADIUS);
		}
	}
	QPoint getClosestValidPosition(QPoint pos) {
		pos.setX(pos.x() - 10);
		pos.setY(pos.y() - 10);
		double x = 1.0 * pos.x() / 30;
		double y = 1.0 * pos.y() / 30;
		int roundedX = round(x) * 30;
		int roundedY = round(y) * 30;

		return QPoint(roundedX + 10, roundedY + 10);
	}

	void swapColors() {
		for (auto& it : points) {
			if (it.second == Qt::black) it.second = Qt::red;
			else it.second = Qt::black;
		}
	}


private slots:
	void onBtnSkipTurnClicked() {
		swapPlayer();
	}
	void onResetGameClicked() {
		board = Board();
		points.clear();
		update();
		gameLocked = false;
		gameStarted = false;
		moveCnt = 0;
	}
	void onBtnSwapModeClicked() {
		if (!gameStarted) {
			swapMode = true;
			gameLocked = true;
			gameStarted = false;
		}
	}

private:
	QPainter painter;
	QPixmap mPix;
	QRect mRect;
	QPoint mPoint;
	std::vector<std::pair<QPoint, Qt::GlobalColor>> points;
};
