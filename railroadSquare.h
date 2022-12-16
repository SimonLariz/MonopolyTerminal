#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "propertySquare.h"

using namespace std;

//railroadSquare inherits from propertySquare
class railroadSquare :public propertySquare
{
private:
	//Private variables
	typedef propertySquare inherited;
	int railroadRent;
	int railroadMulti;
public:
	//Constructor for railroadSquare
	railroadSquare(int position, string tileName, int cost);
	//Getters and Setters
	int getRailroadRent();
	int getRailroadMulti();
	void setRailroadRent(int rent);
	void setRailroadMulti(int multi);
	//purchases railroadSquare
	void purchaseRailroad(player& player);
	//Gets actions for railroadSquare overrides propertySquare
	vector<string> getActions(player& player);
	//Gets player selection for railroadSquare overrides propertySquare
	int getPlayerSelection(vector<string> actionsVect);
	//Responds to player selection for railroadSquare overrides propertySquare
	void replyToPlayerSelection(vector<string>& actions, int selection, player& player);
	//Require actions for railroadSquare
	void required(player& player);
};

