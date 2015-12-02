#pragma once
#include "Field.h"
#include "Square.h"
#include <Windows.h>
#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.h>
#include <FL/Fl_Menu_Bar.H>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

bool DEBUG = false;

void square_cb(Fl_Widget* obj, void* /*mineField, void* i, void* j, void* difficulty*/);
void assignPics(Field mineField, Difficulty difficulty);
void checkPics(Fl_JPEG_Image* hellboy, Fl_JPEG_Image* one, Fl_JPEG_Image* two, Fl_JPEG_Image* three, Fl_JPEG_Image* four, Fl_JPEG_Image* five,
	Fl_JPEG_Image* six, Fl_JPEG_Image* seven, Fl_JPEG_Image* eight);
void quit_cb(Fl_Widget*, void*);
void easy_cb(Fl_Widget* widget, void* );
void med_cb(Fl_Widget* widget, void* mineField);
void hard_cb(Fl_Widget* widget, void* mineField);
void uncoverAdjMines(Field mineField, int i, int j, Difficulty difficulty);



int main(int argc, char **argv) {

	bool restart = false;

	

	
	srand(time(0)); //seed randomizer
	Difficulty difficulty = EASY; //hardcoded for now, eventually will be a menu option
	//Field mineField;
	//Fl_Window *window = new Fl_Window(difficulty * 20 + 10, (difficulty * 20) + 35, "Minesweeper"); //makes window for size of board which is based on difficulty)
	
	Fl_Window *window = new Fl_Window(422, 200, "Poop Sweeper");
	Fl_Box *difficultySelect = new Fl_Box(100, 10, 100, 50, "Select Difficulty");
	Fl_Button *easy = new Fl_Button(50, 75, 100, 50, "Easy");
	Fl_Button *medium = new Fl_Button(151, 75, 100, 50, "Medium");
	Fl_Button *hard = new Fl_Button(252, 75, 100, 50, "Hard");
	easy->callback(easy_cb);
	medium->callback(med_cb);
	hard->callback(hard_cb);
	
	//menu->add("Game/Difficulty/LUDICRIS SPEED", FL_CTRL + 'l', ludicris_speed_cb);

		window->show(argc, argv);
		return Fl::run();
	//}
}

void quit_cb(Fl_Widget* widget, void*) {
	exit(0);
}

void easy_cb(Fl_Widget* widget, void* ) {
	Field mineField;
	mineField.generateField(EASY);
	Fl_Window *win = new Fl_Window((EASY * 20) + 10, (EASY * 20) + 35);
	Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, 400, 25);
	menu->add("Game/Quit", FL_CTRL + 'q', quit_cb);
	menu->add("Game/Difficulty/Easy", FL_CTRL + 'e', easy_cb);
	menu->add("Game/Difficulty/Medium", FL_CTRL + 'm', med_cb); //FIXME
	menu->add("Game/Difficulty/Hard", FL_CTRL + 'h', hard_cb); //FIXME
	for (int i = 0; i < mineField.getMineField().size(); ++i) {
		for (int j = 0; j < mineField.getMineField().size(); ++j) {
			win->add(mineField.getMineField().at(i).at(j));
		}
	}
	
	//assignPics(mineField, EASY);
	
	//makes a callback for each square of the field
	for (int i = 0; i < EASY; ++i) {
		for (int j = 0; j < EASY; ++j) {
			mineField.getMineField().at(i).at(j)->callback(square_cb);
		}
	}

	win->end();
	win->show();
	widget->window()->hide();
}

void med_cb(Fl_Widget* widget, void* ) {
Field mineField;
mineField.generateField(MEDIUM);
Fl_Window *win = new Fl_Window((MEDIUM * 20) + 10, (MEDIUM * 20) + 35);
Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, 400, 25);
menu->add("Game/Quit", FL_CTRL + 'q', quit_cb);
menu->add("Game/Difficulty/Easy", FL_CTRL + 'e', easy_cb);
menu->add("Game/Difficulty/Medium", FL_CTRL + 'm', med_cb); //FIXME
menu->add("Game/Difficulty/Hard", FL_CTRL + 'h', hard_cb); //FIXME

for (int i = 0; i < mineField.getMineField().size(); ++i) {
	for (int j = 0; j < mineField.getMineField().size(); ++j) {
		win->add(mineField.getMineField().at(i).at(j));
	}
}

//assignPics(mineField, MEDIUM);

//makes a callback for each square of the field
for (int i = 0; i < MEDIUM; ++i) {
	for (int j = 0; j < MEDIUM; ++j) {
		mineField.getMineField().at(i).at(j)->callback(square_cb);
	}
}

win->end();
win->show();
widget->window()->hide();
}

void hard_cb(Fl_Widget* widget, void* ) {
Field mineField;
mineField.generateField(HARD);
Fl_Window *win = new Fl_Window((HARD * 20) + 10, (HARD * 20) + 35);
Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, 400, 25);
menu->add("Game/Quit", FL_CTRL + 'q', quit_cb);
menu->add("Game/Difficulty/Easy", FL_CTRL + 'e', easy_cb);
menu->add("Game/Difficulty/Medium", FL_CTRL + 'm', med_cb); //FIXME
menu->add("Game/Difficulty/Hard", FL_CTRL + 'h', hard_cb); //FIXME

for (int i = 0; i < mineField.getMineField().size(); ++i) {
	for (int j = 0; j < mineField.getMineField().size(); ++j) {
		win->add(mineField.getMineField().at(i).at(j));
	}
}

//assignPics(mineField, HARD);

//makes a callback for each square of the field
for (int i = 0; i < HARD; ++i) {
	for (int j = 0; j < HARD; ++j) {
		mineField.getMineField().at(i).at(j)->callback(square_cb);
	}
}

win->end();
win->show();
widget->window()->hide();
}

void square_cb(Fl_Widget* obj, void* ) { //square callback. needs to be updated. 
	Fl_JPEG_Image *hellboy = new Fl_JPEG_Image("hell_boy.jpg");
	Fl_JPEG_Image *one = new Fl_JPEG_Image("one.jpg");
	Fl_JPEG_Image *two = new Fl_JPEG_Image("two.jpg");
	Fl_JPEG_Image *three = new Fl_JPEG_Image("three.jpg");
	Fl_JPEG_Image *four = new Fl_JPEG_Image("four.jpg");
	Fl_JPEG_Image *five = new Fl_JPEG_Image("five.jpg");
	Fl_JPEG_Image *six = new Fl_JPEG_Image("six.jpg");
	Fl_JPEG_Image *seven = new Fl_JPEG_Image("seven.jpg");
	Fl_JPEG_Image *eight = new Fl_JPEG_Image("eight.jpg");

	/*check images */
	checkPics(hellboy, one, two, three, four, five, six, seven, eight);
	
	Square* s = dynamic_cast<Square*>(obj);
	
	switch (s->getState()) {
	case OPEN: 
		s->deactivate();
		break;
	case ONE:
		s->image(one);
		break;
	case TWO:
		s->image(two);
		break;
	case THREE:
		s->image(three);
		break;
	case FOUR:
		s->image(four);
		break;
	case FIVE:
		s->image(five);
		break;
	case SIX:
		s->image(six);
		break;
	case SEVEN:
		s->image(seven);
		break;
	case EIGHT:
		s->image(eight);
		break;
	case MINE:
		s->image(hellboy);
		break;
	}
	
	cout << "A square has been uncovered" << endl;
}


void checkPics(Fl_JPEG_Image* hellboy, Fl_JPEG_Image* one, Fl_JPEG_Image* two, Fl_JPEG_Image* three, Fl_JPEG_Image* four, Fl_JPEG_Image* five,
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

void uncoverAdjMines(Field mineField, int i, int j, Difficulty difficulty) {
	for (int m = -1; m <= 1; ++m) { //these loops go through every square around a mine
		for (int n = -1; n <= 1; ++n) {
			if ((m == 0 && n == 0) || (m == -1 && i == 0) || (n == -1 && j == 0) || (m == 1 && i == (difficulty - 1)) || (n == 1 && j == (difficulty - 1))) { //exceptions/border cases
			}
			else {
				mineField.getMineField().at(i + m).at(j + n)->deactivate();
				if (mineField.getMineField().at(i + m).at(j + n)->getState() == OPEN) {
					uncoverAdjMines(mineField, i + m, j + n, difficulty);
				}
			}
		}
	}
}
