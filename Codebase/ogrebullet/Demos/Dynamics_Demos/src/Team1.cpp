#include "Team1.h"
#include <iostream>
#include <list>
using namespace std;


Team1::Team1(void)
{
}

Team1::~Team1(void)
{
}


void Team1::addPlayerNames(string name)
{
     playerNames.push_front(name);
}


//
//void Team1::addPlayer(Player player)
//{
//	 playerList.push_front(player);
//}

