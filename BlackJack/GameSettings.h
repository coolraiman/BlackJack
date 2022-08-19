#pragma once
#include "PlayerManager.h"
#include <fstream>
//manage everything outside the game
class GameSettings {
private:
	PlayerManager* pM;
	vector<Player*> players;

	bool inGame = false;
	double betValue = 5;
	bool allowSplit = true;
	bool allowInsurance = true;
	GameSettings(PlayerManager* pM) { this->pM = pM; }

	struct GameSettingData {
		vector<int> playersId;
		double betValue;
		bool allowSplit;
		bool allowInsurance;
	};
public:

	void createPlayer(string name, double money);
	bool deletePlayer(int id);

	bool addPlayer(int id);
	bool removePlayer(int id);
	bool startGame();

	void saveGameSettings();
	void loadGameSettings();
	void resetGameSettings();

	void removeAllPlayers();
};