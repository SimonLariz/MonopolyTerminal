#include <iostream>
#include <vector>
#include "property.h"
#include "player.h"

using namespace std;

property::property(string name, int cost, int spacesFromStart) : boardSquare(spacesFromStart) {
		this ->propertyName = name;
		this->propertyCost = cost;
		this->propertyOwner = nullptr;
		this->propertyAvail = true;
}

vector<string> property::getRequiredActions(player& player) {
	vector<string>actionsVect;
	//Pay rent
	if ((this->propertyOwner->getPlayerName() != player.getPlayerName()) && this->propertyAvail == false) {
		//Call calcRent()
	}
	return actionsVect;
}

string property::getName() {
	return this->propertyName;
}

int property::getCost() {
	return this->propertyCost;
}

player* property::getOwner() {
	return this->propertyOwner;
}

bool property::isAvail() {
	return this->propertyAvail;
}

void property::setName(string name) {
	this->propertyName = name;
}
void property::setCost(int cost) {
	this->propertyCost = cost;
}
void property::setOwner(player* player) {
	this->propertyOwner = player;
}
void property::setAvail(bool avail) {
	this->propertyAvail = avail;
}

