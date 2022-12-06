#include <iostream>
#include <vector>
#include "taxSquare.h"
#include "player.h"

using namespace std;

taxSquare::taxSquare(int position, int taxAmount)
	: boardSquare(position) {
	this->taxAmount = taxAmount;
}

void taxSquare::setTaxAmount(string cardTypeStr) {
	this->taxAmount = taxAmount;
}

int taxSquare::getTaxAmount() {
	return this->taxAmount;
}

vector<string> taxSquare::getRequiredActions(player& player) {
	vector<string> playerActions;
	cout << "You paid $" << this->taxAmount << "in taxes\n";

	player.setPlayerMoney(player.getPlayerMoney() - this->taxAmount);

	return playerActions;
}