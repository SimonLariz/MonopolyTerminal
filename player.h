#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class player {
private:
	string playerName;
	int playerMoney;
	string playerToken;
	int playerDebt;
	vector<int> playerProperty;
	vector<int> playerMortgage;
	vector<string> playerActions;
	int boardPosition;

public:
	player(string name, int money, string token);
	//Setters
	void setPlayerName(string name);
	void setPlayerMoney(int money);
	void setPlayerToken(string icon);
	void setPlayerDebt(int money);
	void setPlayerPosition(int position);
	void addPlayerProperty(int asset);
	void removePlayerProperty(int asset);

	//Getters
	string getPlayerName();
	int getPlayerMoney();
	string getPlayerToken();
	int getPlayerDebt();
	int getPlayerPostion();
	vector<int> getPlayerProperty();
	vector<int> getPlayerMortgage();

	bool getBankrupt();
};