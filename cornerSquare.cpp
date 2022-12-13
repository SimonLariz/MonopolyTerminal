#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "cornerSquare.h"

using namespace std;

cornerSquare::cornerSquare(int tilePosition, string tileName) : inherited(tilePosition, tileName)
{
}

vector<string> cornerSquare::getActions(player& player)
{
	vector<string> actionsVector;
	if (player.getPlayerProperty().size() > 0) {
		actionsVector.push_back("Buy Houses / Hotels");
	}
	actionsVector.push_back("End Turn");
	return actionsVector;
}

void cornerSquare::required(player& player)
{
}
