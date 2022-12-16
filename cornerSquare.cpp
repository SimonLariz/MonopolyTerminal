#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "cornerSquare.h"

using namespace std;

//cornerSquare constructor with parameters
cornerSquare::cornerSquare(int tilePosition, string tileName) : inherited(tilePosition, tileName)
{
}
//Gets actions at current square
vector<string> cornerSquare::getActions(player& player)
{
	vector<string> actionsVector;
	if (player.getPlayerProperty().size() > 0) {
		actionsVector.push_back("Buy Houses / Hotels");
		actionsVector.push_back("Trade Property");
	}
	actionsVector.push_back("End Turn");
	return actionsVector;
}
//Required actions at current square
void cornerSquare::required(player& player)
{
}
//Gets player selection from actions vector
int cornerSquare::getPlayerSelection(vector<string> actions) {
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
void cornerSquare::replyToPlayerSelection(vector<string>& actions, int selection, player& player) {
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