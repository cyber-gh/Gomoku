#pragma once
class Board
{
	int M[20][23];
	bool gameEnded = false;
	int winningPlayer = -1;
public:
	Board();
	bool inRange(std::pair<int, int> pos);

	bool validPosition(std::pair<int, int> pos);

	bool placeStone(std::pair<int, int> pos, int playerNr);
	void checkIfWin(std::pair<int, int> pos, int playerNr);

	bool gameOver();
	int getWinningPlayer();

	void swapColors();

	~Board() {}
};

