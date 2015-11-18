#pragma once

#include "Field.h"
#include <iostream>

class Game {   	
	enum difficulty { EASY, MEDIUM, HARD, LUDICROUS_SPEED };
	Field gameBoard;
	int menuSelect;
	int boardSize;
	int uncoveredSquares;
	int minePercent;
public:
	void processSelection();
	void printMenu();
	int getDifficulty();
	void setMinePercent(int	minePercent);
	void setBoardSize(int boardSize);
	int getBoardSize();
	bool start();
	bool exit();
	bool checkWin();
};