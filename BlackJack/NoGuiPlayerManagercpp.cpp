#include "NoGuiPlayerManager.h"

NoGuiPlayerManager::NoGuiPlayerManager(PlayerManager* pM, GameSettings *gS)
{
	this->pM = pM;
	this->gS = gS;
}

void NoGuiPlayerManager::main()
{
	string input = "-1";

	while (input != "0")
	{
		cout << "0: exit Player Manager" << endl;
		cout << "1: get all players" << endl;
		cout << "2: get players in game lobby" << endl;

		cin >> input;

		if (input == "1")
			getAllPlayers();
		else if (input == "2")
			getPlayersInLobby();
	}
}

void NoGuiPlayerManager::getPlayersInLobby() 
{
	vector<Player*>* players = gS->getPlayers();

	for (int i = 0; i < players->size(); i++)
	{
		cout << players->at(i)->getId() << ": " << players->at(i)->getNom() << "   Balance: " << players->at(i)->getMoney() <<
			"  in lobby: " << (gS->playerInLobby(players->at(i)->getId()) ? "yes" : "no") << endl;
	}
	manipulatePlayer();
}

void NoGuiPlayerManager::getAllPlayers()
{
	vector<Player*>* players = pM->getAllPlayers();
	cout << "size: " << players->size() << endl;
	for (int i = 0; i < players->size(); i++)
	{
		cout << players->at(i)->getId() << ": " << players->at(i)->getNom() << "   Balance: " << players->at(i)->getMoney() <<
			"  in lobby: " << (gS->playerInLobby(players->at(i)->getId()) ? "yes" : "no") << endl;
	}

	manipulatePlayer();

}

void NoGuiPlayerManager::manipulatePlayer() 
{
	string input = "-1";
	while (input != "0")
	{
		cout << "0: back" << endl;
		cout << "1: create player" << endl;
		cout << "2: delete player" << endl;
		cout << "3: add player to lobby" << endl;
		cout << "4: remove player to lobby" << endl;
		cout << "5: set player as human or bot" << endl;


		cin >> input;

		if (input == "1")
		{
			createPlayer();
		}
		else if (input == "2")
		{
			deletePlayer();
		}
		else if (input == "3")
		{
			addPlayerToLobby();
		}
		else if (input == "4")
		{
			removePlayerFromLobby();
		}
		else if (input == "5")
		{
			setPlayerAsHumanOrBot();
		}
	}
}

void NoGuiPlayerManager::createPlayer()
{
	string input = "-1";
	string name;
	double money;
	cout << "Name: ";
	cin >> name;
	cout << endl << "Money: ";
	cin >> money;
	cout << endl;
	pM->createPlayer(name, money);
}

void NoGuiPlayerManager::deletePlayer()
{
	int id;
	cout << "player ID: ";
	cin >> id;
	cout << endl;

	if (pM->deletePlayer(id))
	{
		cout << "player deleted" << endl;
	}
	else
	{
		cout << "player not found" << endl;
	}
}

void NoGuiPlayerManager::addPlayerToLobby()
{
	int id;
	cout << "player ID: ";
	cin >> id;
	cout << endl;
	if (gS->addPlayer(id))
	{
		cout << "player added to lobby" << endl;
	}
	else
	{
		cout << "player not found or already in lobby" << endl;
	}
}
void NoGuiPlayerManager::removePlayerFromLobby()
{
	int id;
	cout << "player ID: ";
	cin >> id;
	cout << endl;
	if (gS->removePlayer(id))
	{
		cout << "player removed from lobby" << endl;
	}
	else
	{
		cout << "player id not found in lobby" << endl;
	}
}

void NoGuiPlayerManager::setPlayerAsHumanOrBot()
{
	int id;
	cout << "player ID: ";
	cin >> id;
	cout << endl;

	Player* p = pM->getPlayer(id);
	if (!p)
	{
		cout << "player not found" << endl;
		return;
	}

	bool h;
	cout << "0 = human, 1 = bot" << endl;
	cin >> h;

	p->setIsHuman(h);
}