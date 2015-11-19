#include "Field.h"
#include "Game.h"
#include "Square.h"
#include <ctime>
#include <iostream>



int main(int argc, char **argv) {

	Game game;
	
	Fl_JPEG_Image hellboy("hell_boy.jpg");
	if (hellboy.w() == 0 || hellboy.h() == 0 || hellboy.d() == 0) { //check to see if image opened.
		cerr << "ERROR loading \"hell_boy.jpg\"" << endl;
	}

	srand(time(0)); //seed randomizer
	Difficulty difficulty = EASY; //hardcoded for now, eventually will be a menu option
	Field mineField;
	Fl_Window *window = new Fl_Window(difficulty * 20, difficulty * 20);
	
	game.printMenu();
	game.processSelection();

	


	window->show(argc, argv);
	return Fl::run();
}