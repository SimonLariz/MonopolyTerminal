#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "utilSquare.h"

using namespace std;
//utilSquare constructor
utilSquare::utilSquare(int position, string tileName, int cost) : propertySquare(position, tileName, cost)
{
	this->utilRent = 25;
	this->utilMulti = 1;
}
//Getters and setters
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
//Gets actions at current utilSquare
vector<string> utilSquare::getActions(player& player)
{
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
//Required actions at current utilSquare
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
//Purchases current utilSquare
void utilSquare::purchaseUtilSquare(player& player) {
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
int utilSquare::getPlayerSelection(vector<string>actions) {
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
void utilSquare::replyToPlayerSelection(vector<string>& actions, int selection, player& player) {
	if (actions[selection] == "Buy Property") {
		purchaseUtilSquare(player);
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