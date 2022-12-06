#include <iostream>
#include <vector>
#include "boardSquare.h"
#include "player.h"

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

void boardSquare::setName(string name) {
	this->squareName = name;
}

int boardSquare::getSpacesFromStart() {
	return this->spacesFromStart;
}


string boardSquare::getName() {
	return this->squareName;
}


vector<string> boardSquare::getDefaultActions(player player, vector<string>& actionsVect) {
	
	if (player.getPlayerProperty().size() > 0) {
		actionsVect.push_back("Buy Houses / Hotels");
	}
	actionsVect.push_back("End Turn");
	cout << "done addDefaultActions\n";
	return actionsVect;
}

/*
void boardSquare::buyHouses(player player) {
	//Finish
	vector<property> propertyVect = player.getPlayerProperty();
	int userSelection;

	cout << "Select a property to buy houses/hotels on \n";
	for (property playerProperty : propertyVect) {
		if (playerProperty.getName() == "LOT") {

		}
	}
}


void boardSquare::purchaseHouses(player player, lotSquare lot, int amount) {
	//Finish
}
*/