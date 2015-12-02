#pragma once
#include "Field.h"
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

//Fl_JPEG_Image hellboy("hell_boy.jpg");
//Fl_JPEG_Image one("one.jpg");
//Fl_JPEG_Image two("two.jpg");
//Fl_JPEG_Image three("three.jpg");
//Fl_JPEG_Image four("four.jpg");
//Fl_JPEG_Image five("five.jpg");
//Fl_JPEG_Image six("six.jpg");
//Fl_JPEG_Image seven("seven.jpg");
//Fl_JPEG_Image eight("eight.jpg");

void Field::setDifficulty(int difficulty) {
	this->difficulty = difficulty;
}


void Field::generateField(int difficulty) {
	
	setDifficulty(difficulty);
	totMines = 0;
	
	//generates a 2D vector of objects of class Square
	for (int i = 0; i < difficulty; ++i) {
		vector<Square*> A;
		vectorField.push_back(A);
		for (int j = 0; j < difficulty; ++j) {
			Square *square = new Square((j * 20) + 5, (i * 20) + 30, 20, 20);
			square->type(FL_BORDER_BOX);
			vectorField.at(i).push_back(square);
		}
	}

	//randomly assigns mines
	for (int i = 0; i < difficulty; ++i) {
		for (int j = 0; j < difficulty; ++j) {
			if ((rand() % 100) < 15) { // %15 probability of being a mine
				vectorField.at(i).at(j)->setState(MINE);
				totMines++;    //increment total number of mines
			}
		}
	}
	squaresLeft = difficulty*difficulty - totMines;    //calculate number of open squares

	//sets non-mine squares to state of the number of adjacent mines. 
	for (int i = 0; i < difficulty; ++i) { //first loops go through each square
		for (int j = 0; j < difficulty; ++j) {
			if (vectorField.at(i).at(j)->getState() == MINE) { //if it is a mine
				for (int m = -1; m <= 1; ++m) { //these loops go through every square around a mine
					for (int n = -1; n <= 1; ++n) {
						if ((m == 0 && n == 0) || (m == -1 && i == 0) || (n == -1 && j == 0) || (m == 1 && i == (difficulty - 1)) || (n == 1 && j == (difficulty - 1))) { //exceptions/border cases
						}
						else {
							if (vectorField.at(i + m).at(j + n)->getState() == MINE) { //do not want to make a mine into something else
							}
							else {
								//increment square state. We choose the next state instead of addition becasuse cannot add to enums
								vectorField.at(i + m).at(j + n)->setState(State(vectorField.at(i + m).at(j + n)->getState() + 1));
							}
						}
					}
				}
			}
		}
	}


}

vector< vector< Square*> > Field::getMineField() {
	return vectorField;
}

void Field::doubleClick(int iColumn, int jRow)
{
	int flagCount = 0;
	
	for (int m = -1; m <= 1; ++m) {												//these loops go through every square around a mine
		for (int n = -1; n <= 1; ++n) {
			if ((m == 0 && n == 0) || (m == -1 && iColumn == 0) || (n == -1 && jRow == 0) || (m == 1 && iColumn == (difficulty - 1)) || (n == 1 && jRow == (difficulty - 1))) { //exceptions/border cases
			}
			else {
				if (vectorField.at(iColumn + m).at(jRow + n)->checkFlag()) {					//count number of adjacent flags
					++flagCount;
				}
			}
		}
	}

	if (flagCount == vectorField.at(iColumn).at(jRow)->getState()) {   //proceed only if flagCount == number of adjacent mines
		for (int m = -1; m <= 1; ++m) {												//these loops go through every square around a mine
			for (int n = -1; n <= 1; ++n) {
				if ((m == 0 && n == 0) || (m == -1 && iColumn == 0) || (n == -1 && jRow == 0) || (m == 1 && iColumn == (difficulty - 1)) || (n == 1 && jRow == (difficulty - 1))) { //exceptions/border cases
				}
				else {
					if (vectorField.at(iColumn + m).at(jRow + n)->getState() == MINE) {
						loseGame();   //game over if mine is uncovered
						return;   //FIXME is this needed?
					}
					else {
						//uncover square if open or a number
						//vectorField.at(iColumn + m).at(jRow + n)->callback(square_cb);
					}
				}
			}
		}
	}
	return;
}

bool Field::checkWin() {
	if (squaresLeft == 0) {  //if all open squares are uncovered
		winGame();
	}
	return false;
}

void Field::loseGame() {
	cout << "You lost" << endl;
}

void Field::winGame() {
	cout << "You won" << endl;
}
