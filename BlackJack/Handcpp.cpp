#include "Hand.h"

void Hand::addCard(Card* card)
{
	cards.push_back(card);
}

int Hand::calculateHandValue()
{
	int hVal[] = { 0,0 };
	bool as = false;

	for (int i = 0; i < cards.size(); i++)
	{
		hVal[0] += cards[i]->getCardValue();
		hVal[1] += cards[i]->getCardValue();

		if (cards[i]->getCardValue() == 1 && !as)
		{
			hVal[1] += 10;
			as = true;
		}
	}

	if (hVal[1] < 22 && hVal[1] > hVal[0])
	{
		return hVal[1];
	}

	return hVal[0];
}

void Hand::drawHand()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < cards.size(); j++)
		{
			cards[j]->drawCardLine(i);
			cout << " ";
		}
		cout << endl;
	}
}