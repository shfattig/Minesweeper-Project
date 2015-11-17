#include "Game.h"

void Game::printMenu()
{
	int a;
	cout << "Let's play a game My Pretty!!" << endl << endl;
	cout << "Enter difficulty: ";
	cin >> a;
	setDifficulty(a);
	
}

void Game::setDifficulty(int a)
{


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
