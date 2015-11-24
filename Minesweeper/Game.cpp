#include "Game.h"

void Game::printMenu()
{
	cout << "Let's play a game My Pretty!!" << endl << endl;
	cout << "Enter difficulty: ";
	
	
}

Field Game::getField()
{
	return field;
}

void Game::processSelection() {

	int difficulty;
	cin >> difficulty;
	field.generateField(difficulty);
}

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
