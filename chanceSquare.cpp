#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "chanceSquare.h"
using namespace std;

chanceSquare::chanceSquare()
{
}

chanceSquare::chanceSquare(int tilePosition, string tileName) : boardTile(tilePosition, tileName)
{
}

chanceSquare::~chanceSquare()
{
}

vector<string> chanceSquare::getActions(player& player)
{
    vector<string> actionsVector;
	required(player);
	if (player.getPlayerProperty().size() > 0) {
		actionsVector.push_back("Buy Houses / Hotels");
	}
	actionsVector.push_back("End Turn");
	return actionsVector;
}

void chanceSquare::required(player& player) {
	int max = 400, min = -400;
	int randomInt = rand() % (max - min + 1) + min;
	cout << "Chance has chosen your fate\n";
	if (randomInt >= 0) {
		cout << "You have won $" << randomInt << "\n";
	}
	else {
		cout << "You lost $" << randomInt << "\n";
	}
	player.setPlayerMoney(player.getPlayerMoney() + randomInt);
}
