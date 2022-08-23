#pragma once
#include "Deck.h"
#include <vector>
#include "Player.h"
#include "GameSettings.h"
class GameSettings;
//struct PlayerInput;

enum GameState {
	NONE,
	BET,
	CHECK_PLAYER_BLACKJACK,
	INSURANCE,
	SPLIT,
	PLAY
};

struct PlayerInput {
	short pIndex;
	short hand;
};
struct PlayerHandStatus {
	short pIndex;
	short handIndex;
	bool active;
};


class GameManager {
protected:
	bool isActive = false;
	GameSettings *gS;
	vector<Player*>* players;
	vector<int> inGame;
	Deck deck;
	GameState gameState;
	Hand dealer;


	vector<PlayerInput> getPlayersToBet(); 
	void distributeCards();
	void initGame();
	bool playerBlackjackWin(int p);

public:
	
	
	bool getIsActive() { return isActive; }
	bool startGame(GameSettings* gs); //step 1

	vector<PlayerInput> getPlayersForAction();
	bool setBets(vector<int> p); //step 2
	
	vector<int> checkPlayerBlackjack(); //step 3

};