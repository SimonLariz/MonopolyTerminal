#pragma once
#include <iostream>
#include <vector>
#include "player.h"
#include "boardTile.h"

using namespace std;

//taxSquare inherits from boardTile
class taxSquare : public boardTile
{
private:
	//Private variables
	typedef boardTile inherited;
	int taxAmount;
public:
	//Constructor
	taxSquare(int position, string tileName, int taxAmount);
	//Getters and setters
	int getTaxAmount();
	void setTaxAmount(int amount);
	//Gets actions for taxSquare overrides boardTile
	vector<string> getActions(player& player);
	//Gets player selection from actions vector overrides boardTile
	int getPlayerSelection(vector<string> actionsVect);
	//Responds to player selection for taxSquare overrides boardTile
	void replyToPlayerSelection(vector<string>& actions, int selection, player& player);
	//Required actions for taxSquare
	void required(player& player);
};
