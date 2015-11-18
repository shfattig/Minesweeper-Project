#include "Field.h"

void Field::generateField(int difficulty) { //builds the minefield

	int size = 0;
	switch (difficulty) {
	case 1:
		size = EASY;
		break;
	case 2:
		size = MEDIUM;
	case 3:
		size = HARD;
	case 4:
		size = LUDICRIS_SPEED;
	}

	Fl_JPEG_Image hellboy("hell_boy.jpg");
	for (int i = 0; i < size; ++i) { //generates a 2D vector of objects of class Square
		vector<Square*> A;
		mineField.push_back(A);
		for (int j = 0; j < size; ++j) {
			Square *square = new Square((j * 20), (i * 20), 20, 20);
			mineField.at(i).push_back(square);
		}
	}

	for (int i = 0; i < size; ++i) { //randomly assigns mines
		for (int j = 0; j < size; ++j) {
			if ((rand() % 100) < 15) {
				mineField.at(i).at(j)->setState(MINE);
				mineField.at(i).at(j)->deimage(hellboy);
			}
		}
	}

	for (int i = 0; i < size; ++i) { //sets non-mine squares to state of the number of adjacent mines
		for (int j = 0; j < size; ++j) {
			if (mineField.at(i).at(j)->getState() == MINE) {
				for (int m = -1; m <= 1; ++m) {
					for (int n = -1; n <= 1; ++n) {
						if (m == 0 && n == 0) {
						}
						else {
							//mineField.at(i + m).at(j + n)->setState(State(mineField.at(i + m).at(j + n)->getState() + 1));
						}
					}
				}
			}
		}
	}

}

vector<vector<Square*>> Field::getField()
{
	return mineField;
}


void Field::uncoverSquares()
{
}

