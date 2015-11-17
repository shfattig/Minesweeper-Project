#pragma once
#include "Square.h"
#include <vector>
using namespace std;

enum Difficulty { EASY = 10, MEDIUM = 15, HARD = 20, LUDICRIS_SPEED = 45 }; //values correspond to field size

class Field {
	vector <vector <Square*> > mineField;

public:
	void generateField(int difficulty);
	vector <vector <Square*> > getField();
	void uncoverSquares();
	void printBoard();
};