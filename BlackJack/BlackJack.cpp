// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Deck.h"
#include "Player.h"
#include "PlayerManager.h"
#include "NoGuiMain.h"

void init()
{
    PlayerManager pm;
    pm.loadPlayers();
}

int main()
{
    
    //PlayerManager pM;
    //pM.loadPlayers();
    //pM.createPlayer("bob", 10001);
    //pM.createPlayer("henry", 123551);
    //pM.createPlayer("gon", 199951);
    //cout << pM.getAllPlayers()->size();
    //pM.savePlayers();
    //

    //int pause = 0;
    //cout << "tt" << endl;
    //cin >> pause;
    //cin >> pause;

    NoGuiMain ngM;
    ngM.main();

}

