#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "utilSquare.h"

using namespace std;

utilSquare::utilSquare(int position, string tileName, int cost) : propertySquare(position, tileName, cost)
{
	this->utilRent = 25;
	this->utilMulti = 1;
}

int utilSquare::getUtilRent()
{
	return this->utilRent;
}

int utilSquare::getUtilMulti()
{
	return this->utilMulti;
}

void utilSquare::setUtilRent(int rent)
{
	this->utilRent = rent;
}

void utilSquare::setUtilMulti(int multi)
{
	this->utilMulti = multi;
}

vector<string> utilSquare::getActions(player& player)
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

void utilSquare::required(player& player)
{
	if (!this->getPropertyAvailable()) {
		if (this->getPropertyOwner() != &player) {
			int min = 1, max = 3;
			int randNum = rand() % (max - min + 1) + min;
			int multi = this->getUtilMulti() * randNum;
			int tempRent = this->getUtilRent() * this->getUtilMulti();
			cout << "You paid: " << tempRent << " in Rent to " << this->getPropertyOwner()->getPlayerName() << endl;
			player.setPlayerMoney(player.getPlayerMoney() - tempRent);
			this->getPropertyOwner()->setPlayerMoney(this->getPropertyOwner()->getPlayerMoney() + tempRent);
		}
	}
}
