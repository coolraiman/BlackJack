#pragma once
#include <string>
#include "Hand.h"

using namespace std;

class Player
{
protected:
	int id;
	string nom;
	Hand hand[2];
	int nWins = 0;
	int nLost = 0;
	bool hasSplit = false;
	double money;
	double totalGains = 0;
	int action[2] = { -1,-1 };
public: 
	Player() {}
	Player(int id,string nom, double money) { this->nom = nom; this->money = money; };
	Player(int id, string nom, double money, int nWins, int nLost, double totalGains) 
	{
		this->id = id; this->nom = nom; this->money = money; this->nWins = nWins; this->nLost = nLost; this->totalGains = totalGains;
	};


	int getId() { return id; }
	string getNom() { return nom; }

	enum ActionContext {
		INSURANCE,
		SPLIT,
		MAIN
	};
	 void playerAction(ActionContext context, Card& dealerCard, Player* players, int nPlayers);

	 
};
