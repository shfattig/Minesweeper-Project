#include "Field.h"
#include "Game.h"
#include "Square.h"
#include <ctime>
#include <iostream>

void square_cb(Fl_Widget* obj, void*) { //square callback. needs to be updated. 
	Square* s = dynamic_cast<Square*>(obj);
	s->deactivate();
	cout << "A square has been uncovered" << endl;
}

void assignPics(Field mineField, Difficulty difficulty, Fl_JPEG_Image* hellboy, Fl_JPEG_Image* one, Fl_JPEG_Image* two, Fl_JPEG_Image* three, Fl_JPEG_Image* four, Fl_JPEG_Image* five,
	Fl_JPEG_Image* six, Fl_JPEG_Image* seven, Fl_JPEG_Image* eight);

int main(int argc, char **argv) {
	Fl_JPEG_Image *hellboy = new Fl_JPEG_Image("hell_boy.jpg");
	Fl_JPEG_Image *one = new Fl_JPEG_Image("one.jpg");
	Fl_JPEG_Image *two = new Fl_JPEG_Image("two.jpg");
	Fl_JPEG_Image *three = new Fl_JPEG_Image("three.jpg");
	Fl_JPEG_Image *four = new Fl_JPEG_Image("four.jpg");
	Fl_JPEG_Image *five = new Fl_JPEG_Image("five.jpg");
	Fl_JPEG_Image *six = new Fl_JPEG_Image("six.jpg");
	Fl_JPEG_Image *seven = new Fl_JPEG_Image("seven.jpg");
	Fl_JPEG_Image *eight = new Fl_JPEG_Image("eight.jpg");

	/*check images */ {
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
	Game game;

	srand(time(0)); //seed randomizer
	Difficulty difficulty = EASY; //hardcoded for now, eventually will be a menu option
	Field mineField;
	Fl_Window *window = new Fl_Window(difficulty * 40, difficulty * 40);
	
	
	game.printMenu();
	game.processSelection();
	assignPics(game.getField(), game.getField().getDifficulty(), hellboy, one, two, three, four, five, six, seven, eight);

	for (int i = 0; i < difficulty; ++i) { //makes a callback for each square of the field
		for (int j = 0; j < difficulty; ++j) {
			game.getField().getMineField().at(i).at(j)->callback(square_cb);
		}
	}


	window->show(argc, argv);
	return Fl::run();
}

void assignPics(Field mineField, Difficulty difficulty, Fl_JPEG_Image* hellboy, Fl_JPEG_Image* one, Fl_JPEG_Image* two, Fl_JPEG_Image* three, Fl_JPEG_Image* four, Fl_JPEG_Image* five,
	Fl_JPEG_Image* six, Fl_JPEG_Image* seven, Fl_JPEG_Image* eight) {
	//assign number pictures to number states
	for (int i = 0; i < difficulty; ++i) {
		for (int j = 0; j < difficulty; ++j) {
			switch (mineField.getMineField().at(i).at(j)->getState()) {
			case ONE:
				mineField.getMineField().at(i).at(j)->deimage(one);
				break;
			case TWO:
				mineField.getMineField().at(i).at(j)->deimage(two);
				break;
			case THREE:
				mineField.getMineField().at(i).at(j)->deimage(three);
				break;
			case FOUR:
				mineField.getMineField().at(i).at(j)->deimage(four);
				break;
			case FIVE:
				mineField.getMineField().at(i).at(j)->deimage(five);
				break;
			case SIX:
				mineField.getMineField().at(i).at(j)->deimage(six);
				break;
			case SEVEN:
				mineField.getMineField().at(i).at(j)->deimage(seven);
				break;
			case EIGHT:
				mineField.getMineField().at(i).at(j)->deimage(eight);
				break;
			case MINE:
				mineField.getMineField().at(i).at(j)->deimage(hellboy);
			}
		}
	}
}