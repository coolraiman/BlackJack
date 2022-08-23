#pragma once
#include "GameSettings.h"
#include "NoGuiPlayerManager.h"

class NoGuiMain {
private:
	GameManager gM;
	PlayerManager pM;
	GameSettings *gs;
public:

	void main()
	{
		pM.loadPlayers();
		gs = new GameSettings(&pM, &gM);
		gs->loadGameSettings(true);

		string input;
		cout << "0: Player Manager" << endl;
		if (gs->canStartGame())
		{
			cout << "1: Start Game" << endl;
		}
		cout << (gs->canStartGame() ? "2: " : "1: ") << "exit program" << endl;

		cin >> input;

		if (input == "0")
		{
			NoGuiPlayerManager ngPM(&pM,gs);
			ngPM.main();
		}

		pM.savePlayers();
		
	}

};
