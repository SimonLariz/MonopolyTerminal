#pragma once
#include <iostream>
#include <vector>
#include "player.h"
#include "boardTile.h"

using namespace std;


class taxSquare : public boardTile
{
private:
	typedef boardTile inherited;
	int taxAmount;
public:
	taxSquare(int position, string tileName, int taxAmount);
	int getTaxAmount();
	void setTaxAmount(int amount);
	vector<string> getActions(player& player);
	void required(player& player);
};
