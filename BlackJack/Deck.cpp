#include "Deck.h"

Deck::Deck()
{
	srand(time(NULL));
	cardIndex = 0;
	cards = new Card * [52];
	for (int i = 0; i < 52; i++)
	{
		cards[i] = new Card(i % 4, i / 4 + 1);
	}

}

void Deck::shuffle()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			int index = rand() % 52;
			Card temp = *cards[j];
			*cards[j] = *cards[index];
			*cards[index] = temp;
		}
	}
}

Card* Deck::draw()
{
	return cards[cardIndex++];
}

Deck::~Deck()
{
	delete[] cards;
}