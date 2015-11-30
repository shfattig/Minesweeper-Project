#pragma once
#include "Square.h"

void Square::setState(State state) {
	this->state = state;
}

State Square::getState() {
	return state;
}

bool Square::checkIfCovered() {
	return false;
}