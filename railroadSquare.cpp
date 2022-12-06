#include <iostream>
#include <vector>
#include "railroadSquare.h"
#include "player.h"

using namespace std;

railroadSquare::railroadSquare(int position, string name, int cost)
	: property(name, cost, position) {
}

int railroadSquare::getRent() {
	return this->railroadRent;
}

int railroadSquare::getMult() {
	return this->railroadMult;
}

void railroadSquare::setRent(int rent) {
	this->railroadRent = rent;
}

void railroadSquare::setMult(int mult) {
	this->railroadMult = mult;

}

void railroadSquare::calcRent(player& player) {
	int rent = this->getRent() * this->getMult();
	cout << "You paid $" << rent << " in rent\n";
	player.setPlayerMoney(player.getPlayerMoney() - rent);
}

vector<string> railroadSquare::getRequiredActions(player& player) {
	vector<string> playerActions;
	cout << "requiredActions inside railroad";
	return playerActions;
}