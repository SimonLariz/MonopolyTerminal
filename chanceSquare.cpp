#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "chanceSquare.h"
using namespace std;

//chanceSquare constructor
chanceSquare::chanceSquare()
{
}
//chanceSquare constructor with parameters
chanceSquare::chanceSquare(int tilePosition, string tileName) : boardTile(tilePosition, tileName)
{
}
//chanceSquare destructor
chanceSquare::~chanceSquare()
{
}
//Gets current tile actions
vector<string> chanceSquare::getActions(player& player)
{
    vector<string> actionsVector;
	required(player);
	if (player.getPlayerProperty().size() > 0) {
		actionsVector.push_back("Buy Houses / Hotels");
		actionsVector.push_back("Trade Property");
	}
	actionsVector.push_back("End Turn");
	return actionsVector;
}

//Required actions for chanceSquare
void chanceSquare::required(player& player) {
	int max = 400, min = -400;
	int randomInt = rand() % (max - min + 1) + min;
	cout << "Chance has chosen your fate\n";
	if (randomInt >= 0) {
		cout << "You have won $" << randomInt << "\n";
	}
	else {
		cout << "You lost $" << randomInt << "\n";
	}
	player.setPlayerMoney(player.getPlayerMoney() + randomInt);
}

//Gets player selection from actions vector
int chanceSquare::getPlayerSelection(vector<string> actions) {
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
void chanceSquare::replyToPlayerSelection(vector<string>& actions, int selection, player& player) {
	if (actions[selection] == "Buy Houses / Hotels") {
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

