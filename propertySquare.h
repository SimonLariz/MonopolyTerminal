#pragma once
#include <iostream>
#include <vector>
#include "boardTile.h"
using namespace std;

class propertySquare : public boardTile
{
private:
	typedef boardTile inherited;
	int propertyCost;
	player* propertyOwner;
	bool propertyAvailable;
public:
	propertySquare(int position, string tileName, int cost);

	int getPropertyCost();
	player* getPropertyOwner();
	bool getPropertyAvailable();

	void setPropertyCost(int cost);
	void setPropertyOwner(player* owner);
	void setPropertyAvailable(bool available);

	vector<string> getActions(player& player);
};