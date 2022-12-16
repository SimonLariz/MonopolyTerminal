#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "lotSquare.h"

using namespace std;

//lotSquare inherits from propertySquare
lotSquare::lotSquare(int position, string tileName, int cost, int rent, string color, int houseCost)
	: propertySquare(position, tileName, cost) {
	this->lotRent = rent;
	this->lotColor = color;
	this->lotHouseCost = houseCost;
	this->lotHotelOwned = false;
}

//Getters and Setters
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
//Gets actions at current square
vector<string> lotSquare::getActions(player& player) {
	vector<string> actionsVector;
	this->required(player);
	if (this->getPropertyAvailable()) {
		actionsVector.push_back("Buy Property");
	}
	if (player.getPlayerProperty().size() > 0) {
		actionsVector.push_back("Buy Houses / Hotels");
		actionsVector.push_back("Trade Property");
	}
	actionsVector.push_back("End Turn");
	return actionsVector;
}
//Required actions at current square
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
//Purchases property at current square
void lotSquare::purchaseLot(player& player) {
	if (this->getPropertyAvailable()) {
		if (player.getPlayerMoney() >= this->getPropertyCost()) {
			player.setPlayerMoney(player.getPlayerMoney() - this->getPropertyCost());
			this->setPropertyAvailable(false);
			this->setPropertyOwner(&player);
			vector<int> currentPlayerProperty = player.getPlayerProperty();
			currentPlayerProperty.push_back(this->getTilePosition());
			player.setPlayerProperty(currentPlayerProperty);
			cout << "You purchased: " << this->getTileName() << endl;
			cout << "You now have: " << player.getPlayerMoney() << endl;
		}
		else {
			cout << "You do not have enough money to purchase this property" << endl;
		}
	}
	else {
		cout << "This property is not available" << endl;
	}
}
//Gets player selection from actions vector
int lotSquare::getPlayerSelection(vector<string> actions) {
	int playerSelection = 0;
	for (string action : actions) {
		cout << "\t" << playerSelection << ": " << action << endl;
		playerSelection++;
	}
	cout << "Please select an action: ";
	cin >> playerSelection;
	if (playerSelection > actions.size() - 1) {
		cout << "Invalid Selection\n";
		return getPlayerSelection(actions);
	}
	return playerSelection;
}
//Responds to player selection
void lotSquare::replyToPlayerSelection(vector<string>& actions, int selection, player& player) {
	if (actions[selection] == "Buy Property") {
		purchaseLot(player);
		actions.erase(actions.begin() + selection);
	}
	else if (actions[selection] == "Buy Houses / Hotels") {
		cout << "Sorry this feature has not been added yet" << endl;
		actions.erase(actions.begin() + selection);
	}
	else if (actions[selection] == "End Turn") {
		cout << "Ending Turn" << endl;
		actions.erase(actions.begin() + selection);
	}
	else {
		cout << "Invalid Selection" << endl;
	}
}