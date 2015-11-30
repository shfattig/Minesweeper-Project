#pragma once
#include "Field.h"
#include "Game.h"
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
#include <iostream>



void square_cb(Fl_Widget* obj, void*) { //square callback. needs to be updated. 
	Square* s = dynamic_cast<Square*>(obj);
	s->deactivate();
	cout << "A square has been uncovered" << endl;
}



int main(int argc, char **argv) {

	/*check images */ {
		if (one.w() == 0 || one.h() == 0 || one.d() == 0) { //check to see if image opened.
			cerr << "ERROR loading \"one.jpg\"" << endl;
		}
		if (two.w() == 0 || two.h() == 0 || two.d() == 0) { //check to see if image opened.
			cerr << "ERROR loading \"two.jpg\"" << endl;
		}
		if (three.w() == 0 || three.h() == 0 || three.d() == 0) { //check to see if image opened.
			cerr << "ERROR loading \"three.jpg\"" << endl;
		}
		if (four.w() == 0 || four.h() == 0 || four.d() == 0) { //check to see if image opened.
			cerr << "ERROR loading \"four.jpg\"" << endl;
		}
		if (five.w() == 0 || five.h() == 0 || five.d() == 0) { //check to see if image opened.
			cerr << "ERROR loading \"five.jpg\"" << endl;
		}
		if (six.w() == 0 || six.h() == 0 || six.d() == 0) { //check to see if image opened.
			cerr << "ERROR loading \"six.jpg\"" << endl;
		}
		if (seven.w() == 0 || seven.h() == 0 || seven.d() == 0) { //check to see if image opened.
			cerr << "ERROR loading \"seven.jpg\"" << endl;
		}
		if (eight.w() == 0 || eight.h() == 0 || eight.d() == 0) { //check to see if image opened.
			cerr << "ERROR loading \"eight.jpg\"" << endl;
		}
		if (hellboy.w() == 0 || hellboy.h() == 0 || hellboy.d() == 0) { //check to see if image opened.
			cerr << "ERROR loading \"hell_boy.jpg\"" << endl;
		}
	}

	srand(time(0)); //seed randomizer
	Difficulty difficulty = EASY; //hardcoded for now, eventually will be a menu option
	Field mineField;
	Fl_Window *window = new Fl_Window(difficulty * 20, difficulty * 20, "Minesweeper"); //makes window for size of board which is based on difficulty)

	//mineField.generateField(difficulty);

	//makes a callback for each square of the field
	for (int i = 0; i < difficulty; ++i) {
		for (int j = 0; j < difficulty; ++j) {
			mineField.getMineField().at(i).at(j)->callback(square_cb);
		}
	}

	window->show(argc, argv);
	return Fl::run();
}