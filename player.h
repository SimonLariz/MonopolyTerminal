#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "boardTile.h"

using namespace std;

//player class
class player {
private:
	//Private variables
	string playerName;
	int playerMoney;
	string playerToken;
	int playerDebt;
	vector<int> playerProperty;
	vector<int> playerMortgage;
	vector<string> playerActions;
	int boardPosition;

public:
	//Constructor
	player(string name, int money, string token);
	//Setters
	void setPlayerName(string name);
	void setPlayerMoney(int money);
	void setPlayerToken(string icon);
	void setPlayerDebt(int money);
	void setPlayerPosition(int position);
	void setPlayerProperty(vector<int> property);
	void addPlayerProperty(int property);
	void removePlayerProperty(int property);
	//Getters
	string getPlayerName();
	int getPlayerMoney();
	string getPlayerToken();
	int getPlayerDebt();
	int getPlayerPostion();
	vector<int> getPlayerProperty();
	vector<int> getPlayerMortgage();
	//Determines if player is bankrupt
	bool getBankrupt();
};