#pragma once
#include "Square.h"
#include <Windows.h>
#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class Field {
private:
	vector< vector<Square*> > vectorField;
	int difficulty;
	int squaresLeft;
	int totMines;

public:
	void setDifficulty(int difficulty);
	void generateField(int difficulty);
	vector< vector< Square*> > getMineField();
	void doubleClick(int iColumn, int jRow);
	void loseGame();
	void winGame();
	bool checkWin();
};
