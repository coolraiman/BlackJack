#include "GameSettings.h"

void GameSettings::createPlayer(string nom, double money)
{
	pM->createPlayer(nom, money);
}

bool GameSettings::deletePlayer(int id) {
	return pM->deletePlayer(id);
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



