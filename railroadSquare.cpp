#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "railroadSquare.h"

using namespace std;

railroadSquare::railroadSquare(int position, string tileName, int cost) : propertySquare(position, tileName, cost)
{
	this->railroadRent = 25;
	this->railroadMulti = 1;
}

int railroadSquare::getRailroadRent()
{
	return railroadRent;
}

int railroadSquare::getRailroadMulti()
{
	return railroadMulti;
}

void railroadSquare::setRailroadRent(int rent)
{
	this->railroadRent = rent;
}

void railroadSquare::setRailroadMulti(int multi)
{
	this->railroadMulti = multi;
}

vector<string> railroadSquare::getActions(player& player)
{
	vector<string> actionsVector;
	this->required(player);
	if (this->getPropertyAvailable()) {
		actionsVector.push_back("Buy Property");
	}
	if (player.getPlayerProperty().size() > 0) {
		actionsVector.push_back("Buy Houses / Hotels");
	}
	actionsVector.push_back("End Turn");
	return actionsVector;
}

void railroadSquare::required(player& player)
{
	//Pay rent if property is owned and player != owner
	if (!this->getPropertyAvailable()) {
		if (this->getPropertyOwner() != &player) {
			int min = 1, max = 3;
			int randNum = rand() % (max - min + 1) + min;
			int multi = this->getRailroadMulti() * randNum;
			int tempRent = this->getRailroadRent() * this->getRailroadMulti();
			cout << "You paid: " << tempRent << " in Rent to " << this->getPropertyOwner()->getPlayerName() << endl;
			player.setPlayerMoney(player.getPlayerMoney() - tempRent);
			this->getPropertyOwner()->setPlayerMoney(this->getPropertyOwner()->getPlayerMoney() + tempRent);
		}
	}
}
