#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

//player class constructor
player::player(string name, int money, string token) {
	this->playerName = name;
	this->playerMoney = money;
	this->playerToken = token;
	this->playerDebt = 0;
	this->playerProperty = vector<int>();
	this->playerMortgage = vector<int>();
	this->playerActions = vector<string>();
}
//Setters and getters
void player::setPlayerName(string name) {
	this->playerName = name;
}
void player::setPlayerMoney(int money) {
	this->playerMoney = money;
}
void player::setPlayerToken(string icon) {
	this->playerToken = icon;
}
void player::setPlayerDebt(int debt) {
	this->playerDebt = debt;
}
void player::addPlayerProperty(int property) {
	this->playerProperty.push_back(property);
}
void player::removePlayerProperty(int property) {
	for (int i = 0; i < this->playerProperty.size(); i++) {
		if (this->playerProperty[i] == property) {
			this->playerProperty.erase(this->playerProperty.begin() + i);
		}
	}
}
string player::getPlayerName() {
	return this->playerName;
}
int player::getPlayerMoney() {
	return this->playerMoney;
}
string player::getPlayerToken() {
	return this->playerToken;
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
void player::setPlayerPosition(int position) {
	this->boardPosition = position;
}
void player::setPlayerProperty(vector<int> property) {
	this->playerProperty = property;
}
int player::getPlayerPostion() {
	return this->boardPosition;
}

bool player::getBankrupt() {
	if (this->getPlayerMoney() <= 0) {
		return true;
	}
	return false;
}