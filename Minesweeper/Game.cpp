#pragma once
#include "Game.h"

void Game::printMenu()
{
	cout << "Let's play a game My Pretty!!" << endl << endl;
	cout << "Enter difficulty: ";
	
	
}


/*
void Game::getField(Difficulty difficulty)
{
	for (int i = 0; i < difficulty; ++i) { //makes a callback for each square of the field
		for (int j = 0; j < difficulty; ++j) {
			mineField.getField().at(i).at(j)->callback(square_cb);
		}
	}
}
*/

/*
void Game::processSelection() {

	int difficulty;
	cin >> difficulty;
	mineField.generateField(difficulty);
}
*/

int Game::getDifficulty()
{
	return 0;
}

void Game::setMinePercent(int minePercent)
{
}

void Game::setBoardSize(int boardSize)
{
}

int Game::getBoardSize()
{
	return 0;
}

bool Game::start()
{
	return false;
}

bool Game::exit()
{
	return false;
}

bool Game::checkWin()
{
	return false;
}
