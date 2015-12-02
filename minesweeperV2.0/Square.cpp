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

void Square::setState(State state) {
	this->state = state;
}

State Square::getState() {
	return state;
}

bool Square::checkIfCovered() {
	return false;
}