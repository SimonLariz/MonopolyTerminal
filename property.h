#pragma once
#include <iostream>
#include <vector>
#include "boardSquare.h"

using namespace std;

class property : public boardSquare {
private:
	typedef boardSquare inherited;
	string propertyName;
	int propertyCost;
	player* propertyOwner;
	bool propertyAvail;
public:
	property(string name, int cost, int spacesFromStart);

	vector<string> getRequiredActions(player& player);
	string getName();
	int getCost();
	player* getOwner();
	bool isAvail();

	void setName(string name);
	void setCost(int cost);
	void setOwner(player* player);
	void setAvail(bool avail);

};