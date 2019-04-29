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

void GomokuClass::swapPlayer() {
	if (playerToMove == 1) playerToMove = 2;
	else playerToMove = 1;
}

void GomokuClass::mousePressEvent(QMouseEvent* event) {

	if (event->pos().x() <= 670 && event->pos().y() <= 610) {

		if (!gameLocked) {
			handleMove(getClosestValidPosition(event->pos()));
			moveCnt++;
			if (moveCnt == 2 && promptToSwapColorsAfter2Moves) {
				promptToSwapColorsAfter2Moves = false;
				promptToSwapPlayers();
			}
		}
		else if (swapMode) {
			handeSwapModeMoves(getClosestValidPosition(event->pos()));
		}
		else if (swapMode2) {
			handeSwapMode2Moves(getClosestValidPosition(event->pos()));
		}
		if (!gameStarted && !swapMode) gameStarted = true;
		update();
	}
}

void GomokuClass::handeSwapMode2Moves(QPoint nextMove) {// TODO code dubplication, should use handeSwapModeMoves here 
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
		promptSwap2ModeOptions();
	}
}

void GomokuClass::promptSwap2ModeOptions() {
	QMessageBox::StandardButton reply;

	reply = QMessageBox::question(this, "Swap", "Do you want to swap colors(Yes), continue(cancel) or put 2 more stones(apply)?",
		QMessageBox::Yes | QMessageBox::Apply | QMessageBox::Cancel);

	if (reply == QMessageBox::Yes) {
		board.swapColors();
		this->swapColors();
		swapPlayer();
		update();
	}
	if (reply == QMessageBox::Cancel) {
		qDebug() << "Cancel clicked";
	}
	if (reply == QMessageBox::Apply) {
		promptToSwapColorsAfter2Moves = true;
		moveCnt = 0;
	}
}

void GomokuClass::handeSwapModeMoves(QPoint nextMove) {
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

void GomokuClass::promptToSwapPlayers() {
	QMessageBox::StandardButton reply;

	reply = QMessageBox::question(this, "Swap", "Do you want to swap colors?",
		QMessageBox::Yes | QMessageBox::Cancel);

	if (reply == QMessageBox::Yes) {
		board.swapColors();
		this->swapColors();
		swapPlayer();
		update();
	}
	if (reply == QMessageBox::Cancel) {
		qDebug() << "cancel clicked";
	}

}

void GomokuClass::handleMove(QPoint nextMove) {
	std::pair<int, int> move;
	move.first = nextMove.x() / 30;
	move.second = nextMove.y() / 30;
	if (board.placeStone(move, playerToMove)) {
		points.push_back(std::make_pair(nextMove, (playerToMove == 1 ? Qt::black : Qt::red)));
		swapPlayer();
		if (board.gameOver()) executeGameOver();
	}
}

void GomokuClass::executeGameOver() {
	QMessageBox msg;
	msg.setFixedWidth(200);//TODO needs fixing 

	int winningPlayer = board.getWinningPlayer();
	std::string toShow = "----  Winning Player ";
	toShow += std::to_string(winningPlayer);
	toShow += " --------";
	msg.setText(QString::fromStdString(toShow));
	msg.exec();
	gameLocked = true;
}

void GomokuClass::paintEvent(QPaintEvent* event) {
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

QPoint GomokuClass::getClosestValidPosition(QPoint pos) {
	pos.setX(pos.x() - 10);
	pos.setY(pos.y() - 10);
	double x = 1.0 * pos.x() / 30;
	double y = 1.0 * pos.y() / 30;
	int roundedX = round(x) * 30;
	int roundedY = round(y) * 30;

	return QPoint(roundedX + 10, roundedY + 10);
}

void GomokuClass::swapColors() {
	for (auto& it : points) {
		if (it.second == Qt::black) it.second = Qt::red;
		else it.second = Qt::black;
	}
}

void GomokuClass::onBtnSkipTurnClicked() {
	swapPlayer();
}

void GomokuClass::onResetGameClicked() {
	playerToMove = 1;
	board = Board();
	points.clear();
	update();
	gameLocked = false;
	gameStarted = false;
	swapMode = false;
	swapMode2 = false;
	promptToSwapColorsAfter2Moves = false;
	moveCnt = 0;
}
void GomokuClass::onBtnSwapModeClicked() {
	if (!gameStarted) {
		swapMode = true;
		gameLocked = true;
		gameStarted = false;
	}
}
void GomokuClass::onBtnSwapMode2Clicked() {
	if (!gameStarted) {
		swapMode2 = true;
		gameLocked = true;
		gameStarted = false;
	}
}
