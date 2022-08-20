#pragma once
#include "Deck.h"
#include <vector>
#include "Player.h"
#include "GameSettings.h"
class GameSettings;
enum GameState;

class GameManager {
private:
	bool isActive = false;
	GameSettings *gS;
	vector<Player*>* players;
	Deck deck;
	GameState gameState;
	vector<int> getPlayersToBet();
public:
	enum GameState {
		NONE,
		BET,
		INSURANCE,
		SPLIT,
		PLAY
	};

	bool getIsActive() { return isActive; }
	bool startGame(GameSettings* gs);

	vector<int> getPlayersForAction();
	


};