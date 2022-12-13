#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "propertySquare.h"

using namespace std;

class railroadSquare :public propertySquare
{
private:
	typedef propertySquare inherited;
	int railroadRent;
	int railroadMulti;
public:
	railroadSquare(int position, string tileName, int cost);
	int getRailroadRent();
	int getRailroadMulti();
	void setRailroadRent(int rent);
	void setRailroadMulti(int multi);
	vector<string> getActions(player& player);
	void required(player& player);
};

