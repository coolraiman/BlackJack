#pragma once
#include <vector>
#include "Player.h"
#include "stdlib.h"
#include <string>
#include <fstream>

using namespace std;


class PlayerManager
{
private:
	 vector<Player*> players;

public:

	 const vector<Player*> getAllPlayers()
	{
		return players;
	}

	 vector<Player*> getPlayers(vector<int> ids)
	{
		vector<Player*> p;

		for (int i = 0; i < ids.size(); i++)
		{
			for (int j = 0; j < players.size(); j++)
			{
				if(ids[i] == players[j]->getId())
					p.push_back(players[ids[i]]);
			}
		}
		return p;
	}

	 Player* getPlayer(int id)
	 {
		 for (int i = 0; i < players.size(); i++)
		 {
			 if (id == players[i]->getId())
				 return players[i];
		 }

		 return NULL;
	 }

	 void createPlayer(string name, double money)
	{
		if(players.size() != 0)
			players.push_back(new Player(players[players.size() - 1]->getId(), name, money));
		else
			players.push_back(new Player(0, name, money));
	}

	 bool deletePlayer(int id)
	 {
		 if (id >= players.size())
			 return false;

		 players.erase(players.begin() + id);
		 return true;
	 }

	 void loadPlayers()
	{
		players.clear();

		ifstream file;
		file.open("save", ios::in);

		if (file.fail())
		{
			return;
		}

		while (true)
		{
			Player* p = new Player();
			file.read((char*)&(*p), sizeof(*p));
			if (file.eof())
			{
				delete p;
				break;
			}
			players.push_back(p);
		}
		file.close();

		file.open("save", std::ios::out | std::ios::trunc); // clear contents
		file.close();
	}

	void savePlayers()
	{
		ofstream file;

		file.open("save", ios::app);
		for (int i = 0; i < players.size(); i++)
		{
			file.write((char*)players[i], sizeof(*players[i]));
		}
		file.close();
	}
};