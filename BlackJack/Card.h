#pragma once
#include <string>
#include <iostream>

using namespace std;

class Card
{
	private:
		int symbole;
		int number;
		int cardValue;
	public:
		Card(int symbole, int number) { this->symbole = symbole; this->number = number; cardValue = calculateCardValue(number); }
		int getCardValue();
		static int calculateCardValue(int val);
		string toString();
		string cardValueToString();
		string symbolToString();

		void drawCardLine(int line);
};