#pragma once
#include <iostream>
#include <vector>
#include "propertySquare.h"

using namespace std;

//utilSquare inherits from propertySquare
class utilSquare : public propertySquare
{
private:
	//Private variables
	typedef propertySquare inherited;
	int utilRent;
	int utilMulti;
public:
	//Constructor for utilSquare
	utilSquare(int position, string tileName, int cost);
	//Getters and Setters
	int getUtilRent();
	int getUtilMulti();
	void setUtilRent(int rent);
	void setUtilMulti(int multi);
	//Purchase utilSquare
	void purchaseUtilSquare(player& player);
	//Gets actions for utilSquare overrides propertySquare
	vector<string> getActions(player& player);
	//Gets player selection from actions vector overrides propertySquare
	int getPlayerSelection(vector<string> actionsVect);
	//Responds to player selection for utilSquare overrides propertySquare
	void replyToPlayerSelection(vector<string>& actions, int selection, player& player);
	//Require actions for utilSquare
	void required(player& player);
};

