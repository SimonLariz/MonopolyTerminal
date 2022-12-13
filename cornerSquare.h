#pragma once
#include <iostream>
#include <vector>
#include "player.h"
#include "boardTile.h"

using namespace std;

class cornerSquare :public boardTile
{
private:
	typedef boardTile inherited;
public:
	cornerSquare(int tilePosition, string tileName);

	vector<string> getActions(player& player);

	void required(player& player);
};

