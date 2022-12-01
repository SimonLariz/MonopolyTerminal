#pragma once
#include <iostream>
#include <vector>
using namespace std;

class property : public boardSquare {
private:
	string propertyName;
	int propertyCost;
	player propertyOwner;
	bool propertyAvail;
public:
	property(string name, int cost, int spacesFromStart);

};