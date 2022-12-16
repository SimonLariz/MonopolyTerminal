#pragma once
#include <iostream>
#include <vector>
#include "boardTile.h"
using namespace std;

//propertySquare inherits from boardTile
class propertySquare : public boardTile
{
private:
	//Private variables
	typedef boardTile inherited;
	int propertyCost;
	player* propertyOwner;
	bool propertyAvailable;
public:
	//Constructor for propertySquare
	propertySquare(int position, string tileName, int cost);
	
	//Getters and Setters
	int getPropertyCost();
	player* getPropertyOwner();
	bool getPropertyAvailable();
	void setPropertyCost(int cost);
	void setPropertyOwner(player* owner);
	void setPropertyAvailable(bool available);
	//Overriden by lotSquare, railRoadSquare, and utilitySquare
	vector<string> getActions(player& player);
};