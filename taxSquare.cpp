#include <iostream>
#include <vector>
#include "player.h"
#include "taxSquare.h"

using namespace std;
//taxSquare constructor sets position, name, and tax amount
taxSquare::taxSquare(int position, string tileName, int taxAmount) : boardTile(position, tileName)
{
	this->taxAmount = taxAmount;
}
//Getters and setters
int taxSquare::getTaxAmount()
{
	return taxAmount;
}
void taxSquare::setTaxAmount(int amount)
{
	this->taxAmount = amount;
}
//Gets actions at taxSquare
vector<string> taxSquare::getActions(player& player)
{
	vector<string> actionsVector;
	this->required(player);
	if (player.getPlayerProperty().size() > 0) {
		actionsVector.push_back("Buy Houses / Hotels");
		actionsVector.push_back("Trade Property");
	}
	actionsVector.push_back("End Turn");
	return actionsVector;
}
//Required actions at taxSquare
void taxSquare::required(player& player)
{
	cout << "You paid " << this->getTaxAmount() << " in tax" << endl;
	player.setPlayerMoney(player.getPlayerMoney() - this->getTaxAmount());
}
//Gets player selection from actions vector
int taxSquare::getPlayerSelection(vector<string> actions) {
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
void taxSquare::replyToPlayerSelection(vector<string>& actions, int selection, player& player) {
	if (actions[selection] == "Buy Houses / Hotels") {
		cout << "Buy Houses / Hotels" << endl;
	}
	else if (actions[selection] == "End Turn") {
		cout << "Ending Turn" << endl;
	}
	else {
		cout << "Invalid Selection" << endl;
	}
}