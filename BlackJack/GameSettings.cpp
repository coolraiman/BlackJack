#include "GameSettings.h"

void GameSettings::createPlayer(string nom, double money)
{
	pM->createPlayer(nom, money);
}

bool GameSettings::playerInLobby(int id)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (id == players.at(i)->getId())
		{
			return true;
		}
	}

	return false;
}

bool GameSettings::deletePlayer(int id) {
	return pM->deletePlayer(id);
}

void GameSettings::addPlayers(vector<int> &ids)
{
	for (int i = 0; i < ids.size(); i++)
	{
		addPlayer(ids[i]);
	}
}

bool GameSettings::addPlayer(int id)
{// is player already in game
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->getId() == id)
		{
			return false;
		}
	}

	Player* p = pM->getPlayer(id);
	if (p != NULL)
	{
		players.push_back(p);
		return true;
	}

	return false;
}

bool GameSettings::removePlayer(int id) {
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->getId() == id)
		{
			return true;
		}
	}

	return false;
}

void GameSettings::saveGameSettings()
{
	GameSettingData data;
	data.allowInsurance = this->allowInsurance;
	data.allowSplit = this->allowSplit;
	data.betValue = this->betValue;
	for (int i = 0; i < players.size(); i++)
	{
		data.playersId.push_back(players[i]->getId());
	}

	ofstream file;

	file.open("gameSettings", ios::app);
	for (int i = 0; i < players.size(); i++)
	{
		file.write((char*)&data, sizeof(data));
	}
	file.close();
}

bool GameSettings::loadGameSettings(bool add_players)
{
	GameSettingData data;

	ifstream file;
	file.open("gameSettings", ios::in);

	if (file.fail())
	{
		return false;
	}

	file.read((char*)&data, sizeof(data));

	this->allowInsurance = data.allowInsurance;
	this->allowSplit = data.allowSplit;
	this->betValue = data.betValue;
	if (add_players)
		addPlayers(data.playersId);
	
	file.close();

	file.open("gameSettings", std::ios::out | std::ios::trunc); // clear contents
	file.close();
	return true;
}

void GameSettings::resetGameSettings(bool rem_players) 
{
	this->allowInsurance = true;
	this->allowSplit = true;
	this->betValue = 5;
	if (rem_players)
		removeAllPlayers();
}

void GameSettings::removeAllPlayers()
{
	players.clear();
}

bool GameSettings::startGame()
{
	if (!canStartGame())
	{
		return false;
	}

	return gM->startGame(this);
}

bool GameSettings::canStartGame()
{
	if (this->gM->getIsActive() || !(this->players.size() > 0))
	{
		return false;
	}

	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->getMoney() < this->betValue)
		{
			return false;
		}
	}

	return true;
}