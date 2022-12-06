#include <iostream>
#include <vector>
#include "chanceSquare.h"
#include "player.h"

using namespace std;

chanceSquare::chanceSquare(int position, string cardType)
	: boardSquare(position) {
	this->cardType = cardType;
}

string chanceSquare::getCardType() {
	return this->cardType;
}

void chanceSquare::setCardType(string cardTypeStr) {
	this->cardType = cardTypeStr;
}

vector<string> chanceSquare::getRequiredActions(player& player) {
	vector<string> playerActions;
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

	return playerActions;
}
