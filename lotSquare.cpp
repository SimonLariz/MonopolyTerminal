#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "lotSquare.h"

using namespace std;

lotSquare::lotSquare(int position, string tileName, int cost, int rent, string color, int houseCost)
	: propertySquare(position, tileName, cost) {
	this->lotRent = rent;
	this->lotColor = color;
	this->lotHouseCost = houseCost;
	this->lotHotelOwned = false;
}

int lotSquare::getLotRent() {
	return lotRent;
}

string lotSquare::getLotColor() {
	return lotColor;
}

int lotSquare::getLotHouseCost() {
	return lotHouseCost;
}

bool lotSquare::getLotHotelOwned() {
	return lotHotelOwned;
}

void lotSquare::setLotRent(int rent) {
	this->lotRent = rent;
}

void lotSquare::setLotColor(string color) {
	this->lotColor = color;
}

void lotSquare::setLotHouseCost(int houseCost) {
	this->lotHouseCost = houseCost;
}

void lotSquare::setLotHotelOwned(bool hotelOwned) {
	this->lotHotelOwned = hotelOwned;
}

vector<string> lotSquare::getActions(player& player) {
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

void lotSquare::required(player& player) {
	//Pay rent if property is owned and player != owner
	if (!this->getPropertyAvailable()) {
		if (this->getPropertyOwner() != &player) {
			cout << "You paid: " << this->getLotRent() << " in Rent to " << this->getPropertyOwner()->getPlayerName() << endl;
			player.setPlayerMoney(player.getPlayerMoney() - this->getLotRent());
			this->getPropertyOwner()->setPlayerMoney(this->getPropertyOwner()->getPlayerMoney() + this->getLotRent());
		}
	}
}


