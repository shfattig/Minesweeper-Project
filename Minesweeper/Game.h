#pragma once

#include "Field.h"
#include <iostream>
#include <Windows.h>
#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.h>

class Game {   	
	Field mineField;
	int menuSelect;
	int boardSize;
	int uncoveredSquares;
	int minePercent;
public:
	//void getField(Difficulty difficulty);
	//void processSelection();
	void printMenu();
	int getDifficulty();
	void setMinePercent(int	minePercent);
	void setBoardSize(int boardSize);
	int getBoardSize();
	bool start();
	bool exit();
	bool checkWin();
};