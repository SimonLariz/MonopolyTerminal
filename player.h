#pragma once
#include <iostream>
#include <vector>

using namespace std;


class player {
private:
	string playerName;
	int playerMoney;
	string playerIcon;
	int playerDebt;
	vector<int> playerProperty;
	vector<int> playerMortgage;
	
public:
	player(string name, string token);
	//Setters
	void setPlayerName(string name);
	void setPlayerMoney(int money);
	void setPlayerIcon(string icon);
	void setPlayerDebt(int money);
	void addPlayerProperty(int asset);
	void removePlayerProperty(int asset);

	//Getters
	string getPlayerName();
	int getPlayerMoney();
	string getPlayerIcon();
	int getPlayerDebt();
	vector<int> getPlayerProperty();
	vector<int> getPlayerMortgage();
};