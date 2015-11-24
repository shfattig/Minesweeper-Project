#pragma once

#include <Windows.h>
#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>

using namespace std;

enum State {
	OPEN = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6,
	SEVEN = 7, EIGHT = 8, MINE = 9, FLAG = 10, UNKNOWN = 11
};

class Square : public Fl_Button {
	State state;
	bool covered;

public:
	Square(int x, int y, int w, int h) : Fl_Button(x, y, w, h) {};
	void setState(State state);
	State getState();
	bool checkIfMine();
};