#pragma once
#include <iostream>
#include <vector>
#include "propertySquare.h"

using namespace std;

class utilSquare : public propertySquare
{
private:
	typedef propertySquare inherited;
	int utilRent;
	int utilMulti;
public:
	utilSquare(int position, string tileName, int cost);
	int getUtilRent();
	int getUtilMulti();
	void setUtilRent(int rent);
	void setUtilMulti(int multi);
	vector<string> getActions(player& player);
	void required(player& player);
};

