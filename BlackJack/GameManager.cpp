#include "GameManager.h"

bool GameManager::startGame(GameSettings* gS)
{
	this->gS = gS;
	if (isActive)
		return false;

	isActive = true;
	players = gS->getPlayers();
	return true;
}

vector<int> GameManager::getPlayersForAction()
{
	vector<int> p;
	switch (gameState)
	{
	case NULL:
		return p;
		break;
	case BET:
		return getPlayersToBet();
		break;
	}
	return p;
}

vector<int> GameManager::getPlayersToBet()
{
	vector<int> humans;
	for (int i = 0; i < players->size(); i++)
	{
		if (players->at(i)->getIsHuman() && players->at(i)->getMoney() >= gS->getBetValue())
		{
			humans.push_back(i);
		}
	}
	return humans;
}