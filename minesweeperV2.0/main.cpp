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


void assignPics(Field mineField, Difficulty difficulty);
void quit_cb(Fl_Widget*, void*);
void easy_cb(Fl_Widget* widget, void* );
void med_cb(Fl_Widget* widget, void* mineField);
void hard_cb(Fl_Widget* widget, void* mineField);
//void uncoverAdjMines(Field mineField, Square* s, Difficulty difficulty, Fl_JPEG_Image* hellboy, Fl_JPEG_Image* one, Fl_JPEG_Image* two, Fl_JPEG_Image* three, Fl_JPEG_Image* four, Fl_JPEG_Image* five,
//	Fl_JPEG_Image* six, Fl_JPEG_Image* seven, Fl_JPEG_Image* eight);



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


win->end();
win->show();
widget->window()->hide();
}


/*
void uncoverAdjMines(Field mineField, Square* s, Difficulty difficulty, Fl_JPEG_Image* hellboy, Fl_JPEG_Image* one, Fl_JPEG_Image* two, Fl_JPEG_Image* three, Fl_JPEG_Image* four, Fl_JPEG_Image* five,
	Fl_JPEG_Image* six, Fl_JPEG_Image* seven, Fl_JPEG_Image* eight) {
	int i = s->get_iColumn();
	int j = s->get_jRow();
	
	for (int m = -1; m <= 1; ++m) { //these loops go through every square around a mine
		for (int n = -1; n <= 1; ++n) {
			if ((m == 0 && n == 0) || (m == -1 && i == 0) || (n == -1 && j == 0) || (m == 1 && i == (difficulty - 1)) || (n == 1 && j == (difficulty - 1))) { //exceptions/border cases
			}
			else {
				/*
				switch (mineField.getMineField().at(i + m).at(j + n)->getState()) {
				case OPEN:
					uncoverAdjMines(mineField, s, EASY, hellboy, one, two, three, four, five, six, seven, eight);
					break;
				case ONE:
					mineField.getMineField().at(i + m).at(j + n)->image(one);
					break;
				case TWO:
					mineField.getMineField().at(i + m).at(j + n)->image(two);
					break;
				case THREE:
					mineField.getMineField().at(i + m).at(j + n)->image(three);
					break;
				case FOUR:
					mineField.getMineField().at(i + m).at(j + n)->image(four);
					break;
				case FIVE:
					mineField.getMineField().at(i + m).at(j + n)->image(five);
					break;
				case SIX:
					mineField.getMineField().at(i + m).at(j + n)->image(six);
					break;
				case SEVEN:
					mineField.getMineField().at(i + m).at(j + n)->image(seven);
					break;
				case EIGHT:
					mineField.getMineField().at(i + m).at(j + n)->image(eight);
					break;
				case MINE:
					mineField.getMineField().at(i + m).at(j + n)->image(hellboy);
					break;
				} 
				s->deactivate();
				}
			}
		}
	}
*/
