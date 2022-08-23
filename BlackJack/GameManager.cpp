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

vector<PlayerInput> GameManager::getPlayersForAction()
{
	vector<PlayerInput> p;
	switch (gameState)
	{
	case NULL:
		return p;
		break;
	case BET:
		return getPlayersToBet();
		break;
	}
	//return p;
}

vector<PlayerInput> GameManager::getPlayersToBet()
{
	vector<PlayerInput> humans;
	for (int i = 0; i < players->size(); i++)
	{
		if (players->at(i)->getIsHuman() && players->at(i)->getMoney() >= gS->getBetValue())
		{
			PlayerInput p;
			p.pIndex = i;
			p.hand = -1;
			humans.push_back(p);
		}
	}
	return humans;
}

bool GameManager::setBets(vector<int> p) {
	
	
	if (gameState != BET)
		return false;

	inGame.clear();
	for (int i = 0; i < p.size(); i++)
	{
		if (i < 0 || i >= players->size())
			return false;
		if (!players->at(i)->substractMoney(gS->getBetValue()))
			return false;

		inGame.push_back(p[i]);
	}
	initGame();
	distributeCards();
	gameState = CHECK_PLAYER_BLACKJACK;
	return true;
}

void GameManager::initGame()
{
	inGame.clear();
	dealer.clearHand();
	deck.shuffle();
	for (int i = 0; i < players->size(); i++)
	{
		players->at(i)->getHands()[0].clearHand();
		players->at(i)->getHands()[1].clearHand();
	}
}

void GameManager::distributeCards()
{
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < inGame.size(); i++)
		{
			players->at(i)->getHands()[0].addCard(deck.draw());
		}
	}

	dealer.addCard(deck.draw());
	dealer.addCard(deck.draw());
}

vector<int> GameManager::checkPlayerBlackjack() 
{
	vector<int> b;

	for (int i = 0; i < inGame.size(); i++)
	{
		if (players->at(inGame[i])->getHands()[0].calculateHandValue() == 21)
		{

		}
	}
	return b;
}

bool GameManager::playerBlackjackWin(int p)
{
	if (p >= inGame.size())
		return false;

	//players->at(inGame[p])
	return true;
}











