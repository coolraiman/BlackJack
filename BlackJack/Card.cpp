#include "Card.h"


string Card::toString()
{
	//♠♥♦♣
	string text = "";

	switch (number)
	{
	case 1:
		text += "As";
		break;
	case 11:
		text += "Valet";
		break;
	case 12:
		text += "Reine";
		break;
	case 13:
		text += "Roi";
		break;
	default:
		text += to_string(number);
		break;
	}

	text += " de ";

	switch (symbole)
	{
	case 0:
		text += "Pique";
		break;
	case 1:
		text += "Coeur";
		break;
	case 2:
		text += "Carreau";
		break;
	case 3:
		text += "Trefle";
		break;
	}

	return text;
}

string Card::cardValueToString()
{
	switch (number)
	{
	case 1:
		return "A";
		break;
	case 11:
		return "J";
		break;
	case 12:
		return "Q";
		break;
	case 13:
		return "K";
		break;
	default:
		return to_string(number);
		break;
	}
}

string Card::symbolToString()
{
	switch (symbole)
	{
	case 0:
		return "V";
		break;
	case 1:
		return "O";
		break;
	case 2:
		return "^";
		break;
	case 3:
		return "&";
		break;
	default:
		return "error";
		break;
	}
}

int Card::calculateCardValue(int val)
{
	if (val > 10)
	{
		return 10;
	}
	else
	{
		return val;
	}
}

int Card::getCardValue()
{
	return cardValue;
}

void Card::drawCardLine(int line)
{
	switch (line)
	{
	case 0:
		cout << " _____";
		break;
	case 1:
	{
		string t = cardValueToString();
		cout << "|" << t << ((t.size() == 1) ? " " : "") << "   |";
	}
	case 2:
	{
		cout << "|  " << symbolToString() << "  |";
	}
	case 3:
	{
		string t = cardValueToString();
		cout << "|___|" << ((t.size() == 1) ? "_" : "") << "|";
	}
	}
}

//		     _____    
//			|2    | 
//			|  ^  |
//			|____2|