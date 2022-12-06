#pragma once
#include <iostream>
#include <vector>
#include "property.h"

using namespace std;

class railroadSquare : public property {
private:
	typedef property inherited;
	int railroadRent = 25;
	int railroadMult = 1;
public:
	railroadSquare(int position, string name, int cost);

	int getRent();
	int getMult();

	void setRent(int rent);
	void setMult(int mult);

	void calcRent(player& player);

	vector<string> getRequiredActions(player& player);
};