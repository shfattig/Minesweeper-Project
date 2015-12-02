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
bool Square::checkFlag()
{
	return Flag;
}

bool Square::checkQ()
{
	return Q;
}

void Square::checkPics(Fl_JPEG_Image* hellboy, Fl_JPEG_Image* one, Fl_JPEG_Image* two, Fl_JPEG_Image* three, Fl_JPEG_Image* four, Fl_JPEG_Image* five,
	Fl_JPEG_Image* six, Fl_JPEG_Image* seven, Fl_JPEG_Image* eight) {
		{
			if (one->w() == 0 || one->h() == 0 || one->d() == 0) { //check to see if image opened.
				cerr << "ERROR loading \"one.jpg\"" << endl;
			}
			if (two->w() == 0 || two->h() == 0 || two->d() == 0) { //check to see if image opened.
				cerr << "ERROR loading \"two.jpg\"" << endl;
			}
			if (three->w() == 0 || three->h() == 0 || three->d() == 0) { //check to see if image opened.
				cerr << "ERROR loading \"three.jpg\"" << endl;
			}
			if (four->w() == 0 || four->h() == 0 || four->d() == 0) { //check to see if image opened.
				cerr << "ERROR loading \"four.jpg\"" << endl;
			}
			if (five->w() == 0 || five->h() == 0 || five->d() == 0) { //check to see if image opened.
				cerr << "ERROR loading \"five.jpg\"" << endl;
			}
			if (six->w() == 0 || six->h() == 0 || six->d() == 0) { //check to see if image opened.
				cerr << "ERROR loading \"six.jpg\"" << endl;
			}
			if (seven->w() == 0 || seven->h() == 0 || seven->d() == 0) { //check to see if image opened.
				cerr << "ERROR loading \"seven.jpg\"" << endl;
			}
			if (eight->w() == 0 || eight->h() == 0 || eight->d() == 0) { //check to see if image opened.
				cerr << "ERROR loading \"eight.jpg\"" << endl;
			}
			if (hellboy->w() == 0 || hellboy->h() == 0 || hellboy->d() == 0) { //check to see if image opened.
				cerr << "ERROR loading \"hell_boy.jpg\"" << endl;
			}
		}
}
