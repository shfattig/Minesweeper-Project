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
	bool Flag;


public:
	Square(int x, int y, int w, int h) : Fl_Button(x, y, w, h) {};
	void setState(State state);
	State getState();
	bool checkIfCovered();
	bool checkFlag();
	void Square::checkPics(Fl_JPEG_Image* hellboy, Fl_JPEG_Image* one, Fl_JPEG_Image* two, Fl_JPEG_Image* three, Fl_JPEG_Image* four, Fl_JPEG_Image* five,
		Fl_JPEG_Image* six, Fl_JPEG_Image* seven, Fl_JPEG_Image* eight);
	int handle(int event) {
		if (event == Fl::event_clicks()) {
			
		}
		else if (event == FL_PUSH) {
			if (Fl::event_button() == FL_LEFT_MOUSE) {
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

				if (checkFlag()) {   //prevent uncover if flagged
					return 1;
				}

				switch (getState()) {
				case OPEN:
					deactivate();
					redraw();
					break;
				case ONE:
					image(one);
					redraw();
					break;
				case TWO:
					image(two);
					redraw();
					break;
				case THREE:
					image(three);
					redraw();
					break;
				case FOUR:
					image(four);
					redraw();
					break;
				case FIVE:
					image(five);
					redraw();
					break;
				case SIX:
					image(six);
					redraw();
					break;
				case SEVEN:
					image(seven);
					redraw();
					break;
				case EIGHT:
					image(eight);
					redraw();
					break;
				case MINE:
					image(hellboy);
					redraw();
					break;
				}

				cout << "A square has been uncovered" << endl;
			}
			if (Fl::event_button() == FL_RIGHT_MOUSE) {
				switch (getState()) {

				}
			}
		}
		return 1;
	};


};
