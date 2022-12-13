#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "propertySquare.h"
using namespace std;

propertySquare::propertySquare(int position, string tileName, int cost) :boardTile(position, tileName) {
	this->propertyCost = cost;
	this->propertyOwner = NULL;
	this->propertyAvailable = true;
}

int propertySquare::getPropertyCost() {
	return propertyCost;
}

player* propertySquare::getPropertyOwner() {
	return propertyOwner;
}

bool propertySquare::getPropertyAvailable() {
	return propertyAvailable;
}

void propertySquare::setPropertyCost(int cost) {
	this->propertyCost = cost;
}

void propertySquare::setPropertyOwner(player* owner) {
	this->propertyOwner = owner;
}

void propertySquare::setPropertyAvailable(bool available) {
	this->propertyAvailable = available;
}

vector<string> propertySquare::getActions(player& player) {
	vector<string> actionsVector;
	if (this->getPropertyAvailable()) {
		actionsVector.push_back("Buy Property");
	}
	else {
		if (this->getPropertyOwner() != &player) {
			actionsVector.push_back("Pay Rent");
		}
	}
	return actionsVector;
}