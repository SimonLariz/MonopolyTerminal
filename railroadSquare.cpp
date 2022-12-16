#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "railroadSquare.h"

using namespace std;
//railroadSquare constructor 
railroadSquare::railroadSquare(int position, string tileName, int cost) : propertySquare(position, tileName, cost)
{
	this->railroadRent = 25;
	this->railroadMulti = 1;
}
//Getters and Setters
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
//Gets actions at current square
vector<string> railroadSquare::getActions(player& player)
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
//Required actions at current square
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
//Purchase current railraod property
void railroadSquare::purchaseRailroad(player& player) {
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
int railroadSquare::getPlayerSelection(vector<string> actions) {
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
void railroadSquare::replyToPlayerSelection(vector<string>& actions, int selection, player& player) {
	if (actions[selection] == "Buy Property") {
		purchaseRailroad(player);
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