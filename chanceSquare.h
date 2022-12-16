#pragma once
#include <iostream>
#include <vector>
#include "boardTile.h"
using namespace std;

//chanceSquare inherits from boardTile
class chanceSquare : public boardTile
{
private:
	//Inherited from boardTile
	typedef boardTile inherited;

public:
	//Constructor for chanceSquare
	chanceSquare();
	chanceSquare(int tilePosition, string tileName);
	~chanceSquare();

	//Gets actions for chanceSquare overrides boardTile
	vector<string> getActions(player& player);
	//Gets player selection for chanceSquare overrides boardTile
	int getPlayerSelection(vector<string> actionsVect);
	//Responds to player selection for chanceSquare overrides boardTile
	void replyToPlayerSelection(vector<string>& actions, int selection, player& player);
	//Require actions for chanceSquare
	void required(player& player);
};
