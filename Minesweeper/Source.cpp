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

int main(int argc, char **argv) {

	Game game;
	game.printMenu();
	game.processSelection();

	Fl_JPEG_Image hellboy("hell_boy.jpg");
	if (hellboy.w() == 0 || hellboy.h() == 0 || hellboy.d() == 0) { //check to see if image opened.
		cerr << "ERROR loading \"hell_boy.jpg\"" << endl;
	}

	srand(time(0)); //seed randomizer
	Difficulty difficulty = EASY; //hardcoded for now, eventually will be a menu option
	Field mineField;
	Fl_Window *window = new Fl_Window(difficulty * 20, difficulty * 20);

	mineField.generateField(difficulty);

	for (int i = 0; i < difficulty; ++i) { //makes a callback for each square of the field
		for (int j = 0; j < difficulty; ++j) {
			mineField.getField().at(i).at(j)->callback(square_cb);
		}
	}


	window->show(argc, argv);
	return Fl::run();
}