#include "Square.h"

void Square::setState(State state)
{
	this->state = state;
}

State Square::getState()
{
	return this->state;
}

bool Square::checkIfMine()
{
	if (this->state = MINE) {
		return true;
	}
	else
		return false;
}
