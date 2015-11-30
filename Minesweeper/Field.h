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

enum Difficulty { EASY = 10, MEDIUM = 15, HARD = 20, LUDICRIS_SPEED = 45 }; //values correspond to field size

Fl_JPEG_Image hellboy("hell_boy.jpg");
Fl_JPEG_Image one("one.jpg");
Fl_JPEG_Image two("two.jpg");
Fl_JPEG_Image three("three.jpg");
Fl_JPEG_Image four("four.jpg");
Fl_JPEG_Image five("five.jpg");
Fl_JPEG_Image six("six.jpg");
Fl_JPEG_Image seven("seven.jpg");
Fl_JPEG_Image eight("eight.jpg");

class Field {
private:
	vector< vector<Square*> > mineField;

public:
	void generateField(int difficulty);
	vector< vector< Square*> > getMineField();

};