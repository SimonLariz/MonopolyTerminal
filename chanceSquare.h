#pragma once
#include <iostream>
#include <vector>
#include "boardTile.h"
using namespace std;

class chanceSquare : public boardTile
{
private:
    typedef boardTile inherited;

public:
    chanceSquare();
    chanceSquare(int tilePosition, string tileName);
    ~chanceSquare();

    vector<string> getActions(player& player);

	void required(player& player);
};
