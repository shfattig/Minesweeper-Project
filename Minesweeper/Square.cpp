#include "Square.h"

void Square::setState(State state)
{
	this->state = state;
}

void Square::square_cb(Fl_Widget* obj, void*) { //square callback. needs to be updated. 
	Square* s = dynamic_cast<Square*>(obj);
	s->deactivate();
	cout << "A square has been uncovered" << endl;
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
