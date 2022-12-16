#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "propertySquare.h"
using namespace std;
//propertySquare constructor sets inherited variables and private variables
propertySquare::propertySquare(int position, string tileName, int cost) :boardTile(position, tileName) {
	this->propertyCost = cost;
	this->propertyOwner = NULL;
	this->propertyAvailable = true;
}
//Getters and Setters
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
//Gets actions at current propertySquare 
//THIS IS ALWAYS OVERRIDEN BY CHILD CLASSES
vector<string> propertySquare::getActions(player& player) {
	vector<string> actionsVector;
	if (this->getPropertyAvailable()) {
		actionsVector.push_back("Buy Houses / Hotels");
		actionsVector.push_back("Trade Property");
	}
	else {
		if (this->getPropertyOwner() != &player) {
			actionsVector.push_back("Pay Rent");
		}
	}
	actionsVector.push_back("End Turn");
	return actionsVector;
}