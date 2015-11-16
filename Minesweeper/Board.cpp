#include "Board.h"

void Board::buildBoard(int difficulty)
{
	switch (difficulty)
		case (1):
	{
		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 15; ++j) {
				//generate object of class Square
			}
		}
	}
		case (2):
		{
			for (int i = 0; i < 12; ++i) {
				for (int j = 0; j < 15; ++j) {
					//generate object of class Square
				}
			}
		}
}

void Board::uncoverSquares()
{
}

bool Board::checkIfMine()
{
	return false;
}

void Board::printBoard()
{
}
