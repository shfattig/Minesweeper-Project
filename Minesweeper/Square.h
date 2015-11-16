#pragma once

class Square {
	enum state { OPEN, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, MINE, FLAG, UNKNOWN };

public:
	void setState();
	int getState(Square s);
};