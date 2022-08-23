#pragma once
#include "GameSettings.h"

class NoGuiPlayerManager
{
private:
	PlayerManager* pM;
	GameSettings* gS;

public:
	NoGuiPlayerManager(PlayerManager* pM, GameSettings *gS);

	void main();
private:
	void getAllPlayers();
	void getPlayersInLobby();
	void manipulatePlayer();
	void createPlayer();
	void deletePlayer();
	void addPlayerToLobby();
	void removePlayerFromLobby();
	void setPlayerAsHumanOrBot();
};