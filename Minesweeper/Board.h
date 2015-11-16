#pragma once
#include "Square.h"
#include <vector>
using namespace std;

class Board {
	vector <vector <Square> > gameBoard;

public:
	void buildBoard(int difficulty);
	void uncoverSquares();
	bool checkIfMine();
	void printBoard();
};