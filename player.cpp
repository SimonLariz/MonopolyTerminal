#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

player::player(string name, string token) {
	this->playerName = name;
	this->playerIcon = token;
	this->playerMoney = 2000;
	this->playerProperty = vector<int>();

}

void player::setPlayerName(string name) {
	this->playerName = name;
}
void player::setPlayerMoney(int money) {
	this->playerMoney = money;
}
void player::setPlayerIcon(string icon) {
	this->playerIcon = icon;
}
void player::setPlayerDebt(int debt) {
	this->playerDebt = debt;
}
void player::addPlayerProperty(int property) {
	this->playerProperty.push_back(property);
}
void player::removePlayerProperty(int property) {
	//Complete;
}

string player::getPlayerName() {
	return this->playerName;
}
int player::getPlayerMoney() {
	return this->playerMoney;
}
string player::getPlayerIcon() {
	return this->playerIcon;
}
int player::getPlayerDebt() {
	return this->playerDebt;
}
vector<int> player::getPlayerProperty() {
	return this->playerProperty;
}
vector<int> player::getPlayerMortgage() {
	return this->playerMortgage;
}



