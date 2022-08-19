#pragma once
#include "Card.h"
#include "time.h"
#include "stdlib.h"
#include <string>

class Deck
{
private:
	Card** cards;
	int cardIndex;
public:
	Deck();
	void shuffle();
	Card* draw();
	~Deck();

};
