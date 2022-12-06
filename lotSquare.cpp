#include <iostream>
#include <vector>
#include "lotSquare.h"
#include "player.h"

using namespace std;

lotSquare::lotSquare(int position, string name, int price, string color, int rent, int housePrice)
	: property(name, price, position) {
	this->lotColor = color;
	this->lotRent = rent;
	this->housePrice = housePrice;
	this->housesOwned = 0;
	this->hotelOwned = false;
}

void lotSquare::setColor(string color) {
	this->lotColor = color;
}

void lotSquare::setRent(int rent) {
	this->lotRent = rent;
}

void lotSquare::setHousePrice(int hPrice) {
	this->housePrice = hPrice;
}

void lotSquare::setHousesOwned(int owned) {
	this->housesOwned = owned;
}

void lotSquare::setHotelOwned(bool owned) {
	this->hotelOwned = owned;
}

string lotSquare::getColor() {
	return this->lotColor;
}

int lotSquare::getRent() {
	return this->lotRent;
}

int lotSquare::getHousePrice() {
	return this->housePrice;
}

int lotSquare::getHousesOwned() {
	return this->housesOwned;
}

bool lotSquare::isHotelOwned() {
	return this->hotelOwned;
}


void lotSquare::calcRent(player& player) {
	int mult = this->getHousesOwned() + 1;
	int rent = this->getRent();

	mult += this->getHousesOwned();
	if (this->isHotelOwned()) {
		mult++;
	}

	rent = rent * mult;

	cout << "You paid $" << rent << " in rent\n";
	player.setPlayerMoney(player.getPlayerMoney() - rent);
}

vector<string> lotSquare::getRequiredActions(player& player) {
	vector<string> playerActions;
	cout << "requiredActions inside lotSquare";
	return playerActions;
}