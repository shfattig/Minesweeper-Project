#pragma once
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




/*
-OPEN means not a mine and no mines near it
-ONE - EIGHT indicates how many mines are near it
-MINE is a mine
-FLAG is a flag
-UNKNOWN is a question mark
*/

enum State {
	OPEN = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6,
	SEVEN = 7, EIGHT = 8, MINE = 9, FLAG = 10, UNKNOWN = 11
};

enum Difficulty { EASY = 10, MEDIUM = 15, HARD = 20, LUDICRIS_SPEED = 45 }; //values correspond to field size

class Square : public Fl_Button {
private: 
	State state;
	bool cover;


public:
	Square(int x, int y, int w, int h) : Fl_Button(x, y, w, h) {};
	void setState(State state);
	State getState();
	bool checkIfCovered();

	

};