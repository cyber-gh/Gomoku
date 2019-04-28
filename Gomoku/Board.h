#pragma once
class Board
{
	int M[20][23];
	bool gameEnded = false;
	int winningPlayer = -1;
public:
	Board() {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 23; j++) {
				M[i][j] = 0;
			}
		}
	}
	bool inRange(std::pair<int, int> pos) {
		return  (pos.first >= 0 && pos.first < 20 && pos.second >= 0 && pos.second < 23);
	}

	bool validPosition(std::pair<int, int> pos) {
		if (inRange(pos)) {
			return M[pos.first][pos.second] == 0;
		}
		return false;
	}

	bool placeStone(std::pair<int, int> pos, int playerNr) {
		if (!validPosition(pos)) return false;
		int x = pos.first;
		int y = pos.second;
		M[x][y] = playerNr;
		checkIfWin(pos, playerNr);
		return true;

	}
	void checkIfWin(std::pair<int, int> pos, int playerNr) {
		int dx[] = { 1,1,-1,-1 };
		int dy[] = { 1, -1, -1, 1 };
		for (int k = 0; k < 4; k++) {
			int steps = 0;
			std::pair<int, int> it = pos;
			while (inRange(it) && M[it.first][it.second] == playerNr) {
				steps++;
				it.first += dx[k];
				it.second += dy[k];
			}
			if (steps == 5) {
				gameEnded = true;
				winningPlayer = playerNr;
				return;
			}
		}
	}

	bool gameOver() {
		return gameEnded;
	}
	int whoWon() {
		return winningPlayer;
	}

	void swapColors() {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 23; j++) {
				if (M[i][j] == 1) M[i][j] = 2;
				if (M[i][j] == 2) M[i][j] = 1;
			}
		}
	}

	~Board() {}
};

