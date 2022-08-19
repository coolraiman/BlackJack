#pragma once
#include <vector>
#include "Card.h"

using namespace std;

class Hand
{
private:
	vector<Card*> cards;
public:
	Hand() {};
	void addCard(Card* card);
	int calculateHandValue();

	void drawHand();

	~Hand()
	{
		for (auto p : cards)
		{
			delete p;
		}
		cards.clear();
	}
};