#pragma once
#include <iostream>
#include <vector>
#include "player.h"
#include "lotSquare.h"
#include "property.h"
#include "cardSquarecpp.h"

using namespace std;

class boardSquare {
private:
	int boardSpaces = 40;
	int spacesFromStart;
public:
	boardSquare(int position);

	//Setter
	void setSpacesFromStart(int spaces);


	//Getter
	int getSpacesFromStart();

	vector<string> addDefaultActions(player player, vector<string> actionsVect);

	void purchaseHouses(player player, lotSquare lot, int amount);

};