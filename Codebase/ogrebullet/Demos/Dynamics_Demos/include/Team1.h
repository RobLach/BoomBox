#pragma once
#include <list>
#include <string>
#include <iostream>
#include "Player.h"

using namespace std;



class Team1
{
public:
	Team1();
	~Team1();
	list<string> playerNames;
//	list<Player> playerList;

	void addPlayerNames(string name);
	void deletePlayerNames(string name);

//	void addPlayer(Player player);
//	void deletePlayer(Player player); 
};
