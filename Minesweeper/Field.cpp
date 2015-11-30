#pragma once
#include "Field.h"
#include "Square.h"

//Fl_JPEG_Image hellboy("hell_boy.jpg");


/*builds the minefield
void Field::generateField(int difficulty) {
	//generates a 2D vector of objects of class Square
	for (int i = 0; i < difficulty; ++i) {
		vector<Square*> A;
		mineField.push_back(A);
		for (int j = 0; j < difficulty; ++j) {
			Square *square = new Square((j * 20), (i * 20), 20, 20);
			mineField.at(i).push_back(square);
		}
	}

	//randomly assigns mines
	for (int i = 0; i < difficulty; ++i) {
		for (int j = 0; j < difficulty; ++j) {
			if ((rand() % 100) < 15) { // %15 probability of being a mine
				mineField.at(i).at(j)->setState(MINE);
				mineField.at(i).at(j)->deimage(hellboy);
			}
		}
	}

	//sets non-mine squares to state of the number of adjacent mines. 
	for (int i = 0; i < difficulty; ++i) { //first loops go through each square
		for (int j = 0; j < difficulty; ++j) {
			if (mineField.at(i).at(j)->getState() == MINE) { //if it is a mine
				for (int m = -1; m <= 1; ++m) { //these loops go through every square around a mine
					for (int n = -1; n <= 1; ++n) {
						if ((m == 0 && n == 0) || (m == -1 && i == 0) || (n == -1 && j == 0) || (m == 1 && i == (difficulty - 1)) || (n == 1 && j == (difficulty - 1))) { //exceptions/border cases
						}
						else {
							if (mineField.at(i + m).at(j + n)->getState() == MINE) { //do not want to make a mine into something else
							}
							else {
								//increment square state. We choose the next state instead of addition becasuse cannot add to enums
								mineField.at(i + m).at(j + n)->setState(State(mineField.at(i + m).at(j + n)->getState() + 1));
							}
						}
					}
				}
			}
		}
	}

	//assign number pictures to number states
	for (int i = 0; i < difficulty; ++i) {
		for (int j = 0; j < difficulty; ++j) {
			switch (mineField.at(i).at(j)->getState()) {
			case ONE:
				mineField.at(i).at(j)->deimage(one);
				break;
			case TWO:
				mineField.at(i).at(j)->deimage(two);
				break;
			case THREE:
				mineField.at(i).at(j)->deimage(three);
				break;
			case FOUR:
				mineField.at(i).at(j)->deimage(four);
				break;
			case FIVE:
				mineField.at(i).at(j)->deimage(five);
				break;
			case SIX:
				mineField.at(i).at(j)->deimage(six);
				break;
			case SEVEN:
				mineField.at(i).at(j)->deimage(seven);
				break;
			case EIGHT:
				mineField.at(i).at(j)->deimage(eight);
				break;
			}
		}
	}

}

*/
vector< vector< Square*> > Field::getMineField() {
	return mineField;
}
