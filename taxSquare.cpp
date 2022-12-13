#include <iostream>
#include <vector>
#include "player.h"
#include "taxSquare.h"

using namespace std;

taxSquare::taxSquare(int position, string tileName, int taxAmount) : boardTile(position, tileName)
{
	this->taxAmount = taxAmount;
}

int taxSquare::getTaxAmount()
{
	return taxAmount;
}

void taxSquare::setTaxAmount(int amount)
{
	this->taxAmount = amount;
}

vector<string> taxSquare::getActions(player& player)
{
	vector<string> actionsVector;
	this->required(player);
	if (player.getPlayerProperty().size() > 0) {
		actionsVector.push_back("Buy Houses / Hotels");
	}
	actionsVector.push_back("End Turn");
	return actionsVector;
}

void taxSquare::required(player& player)
{
	cout << "You paid " << this->getTaxAmount() << " in tax" << endl;
	player.setPlayerMoney(player.getPlayerMoney() - this->getTaxAmount());
}

