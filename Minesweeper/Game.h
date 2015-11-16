#pragma once

#include "Board.h"
#include <iostream>

class Game {   	
	enum difficulty { EASY, MEDIUM, HARD, LUDICROUS_SPEED };
	Board gameBoard;
	int menuSelect;
	int boardSize;
	int uncoveredSquares;
	int minePercent;
public:
	void printMenu();
	void setDifficulty(int a);
	int getDifficulty();
	void setMinePercent(int	minePercent);
	void setBoardSize(int boardSize);
	int getBoardSize();
	bool start();
	bool exit();
	bool checkWin();
};