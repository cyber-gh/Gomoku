/*
Soltan Gheorhge
Grupa 142
*/

#pragma once
class Board
{
	int M[20][23];
	bool gameEnded = false;
	bool isDraw = false;
	int winningPlayer = -1;
	int moves = 0;
public:
	Board();
	bool inRange(std::pair<int, int> pos);

	bool validPosition(std::pair<int, int> pos);

	bool placeStone(std::pair<int, int> pos, int playerNr);
	void checkIfWin(std::pair<int, int> pos, int playerNr);

	bool gameOver();
	int getWinningPlayer();

	void swapColors();

	bool getIsDraw() {
		return isDraw;
	}

	~Board() {}
};

