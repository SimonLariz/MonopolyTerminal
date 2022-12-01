#include <iostream>
#include <vector>
#include "boardSquare.h";
using namespace std;

boardSquare::boardSquare(int spaces) {
	if (spaces >= 0 && spaces < boardSpaces) {
		this->spacesFromStart = spaces;
	}
	else {
		cout << "ERROR INVALID SPACE FROM START\n";
		exit(-1);
	}
}

void boardSquare::setSpacesFromStart(int spaces) {
	if (spaces >= 0 && spaces < boardSpaces) {
		this->spacesFromStart = spaces;
	}
}

int boardSquare::getSpacesFromStart() {
	return this->spacesFromStart;
}

vector<string> boardSquare::addDefaultActions(player player, vector<string> actionsVect) {
	if (player.getPlayerProperty().size() > 0) {
		actionsVect.push_back("Buy Houses / Hotels");
	}
	actionsVect.push_back("End Turn");
	return actionsVect;

}

void boardSquare::purchaseHouses(player player, lotSquare lot, int amount) {
	//Finish
}