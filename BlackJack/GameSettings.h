#pragma once
#include "PlayerManager.h"
#include <fstream>
#include "GameManager.h";
class GameManager;

//manage everything outside the game
class GameSettings {
private:
	PlayerManager* pM;
	GameManager* gM;
	vector<Player*> players;

	bool inGame = false;
	double betValue = 5;
	bool allowSplit = true;
	bool allowInsurance = true;
	
	struct GameSettingData {
		vector<int> playersId;
		double betValue;
		bool allowSplit;
		bool allowInsurance;
	};
public:
	GameSettings(PlayerManager* pM, GameManager* gM) { this->pM = pM; this->gM = gM; }
	vector<Player*>* getPlayers(){return &players;}
	bool playerInLobby(int id);

	bool canStartGame();
	bool startGame();

	double getBetValue() { return betValue; }
	bool getAllowSplit() { return allowSplit; }
	bool getAllowInsurance() { return allowInsurance; }


	void createPlayer(string name, double money);
	bool deletePlayer(int id);

	bool addPlayer(int id);
	void addPlayers(vector<int>& ids);
	bool removePlayer(int id);

	void saveGameSettings();
	bool loadGameSettings(bool add_players);
	void resetGameSettings(bool rem_players);

	void removeAllPlayers();
};