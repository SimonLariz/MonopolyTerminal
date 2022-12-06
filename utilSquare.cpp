#include <iostream>
#include <vector>
#include "utilSquare.h"
#include "player.h"

using namespace std;

utilSquare::utilSquare(int position, string name, int cost)
	: property(name, cost, position) {
}

void utilSquare::calcRent(player& player) {
	int max = 6, min = 1;
	int randomInt = rand() % (max - min + 1) + min;
	int rent = 4 * randomInt;
	cout << "You paid $" << rent << " in rent\n";
	player.setPlayerMoney(player.getPlayerMoney() - rent);
	this->getOwner()->setPlayerMoney(this->getOwner()->getPlayerMoney() + rent);
} 

vector<string> utilSquare::getRequiredActions(player& player) {
	vector<string> playerActions;
	cout << "requiredActions inside util";
	return playerActions;
}