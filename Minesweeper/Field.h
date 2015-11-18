#pragma once
#include "Square.h"
#include <vector>
#include <Windows.h>
#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.h>

using namespace std;



class Field {
	vector <vector <Square*> > mineField;
	
public:
	enum Difficulty { EASY = 10, MEDIUM = 15, HARD = 20, LUDICRIS_SPEED = 45 }; //values correspond to field size
	void generateField(int difficulty);
	vector <vector <Square*> > getField();
	void uncoverSquares();
};