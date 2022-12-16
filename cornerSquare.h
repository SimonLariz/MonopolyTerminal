#pragma once
#include <iostream>
#include <vector>
#include "player.h"
#include "boardTile.h"

using namespace std;

//cornerSquare inherits from boardTile
class cornerSquare :public boardTile
{
private:
	//Inherited from boardTile
	typedef boardTile inherited;
public:
	//Constructor for cornerSquare
	cornerSquare(int tilePosition, string tileName);

	//Gets actions for cornerSquare overrides boardTile
	vector<string> getActions(player& player);
	//Gets player selection for cornerSquare overrides boardTile
	int getPlayerSelection(vector<string> actionsVect);
	//Responds to player selection for cornerSquare overrides boardTile
	void replyToPlayerSelection(vector<string>& actions, int selection, player& player);
	//Require actions for cornerSquare
	void required(player& player);
};

