#pragma once
#include <iostream>
#include <vector>
#include "property.h"

using namespace std;

class utilSquare : public property {
private:
	typedef property inherited;
	bool bothUtilOwned;
public:
	utilSquare(int position, string name, int cost);

	void calcRent(player& player);

	vector<string> getRequiredActions(player& player);
};