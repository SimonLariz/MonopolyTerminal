#pragma once
#include <iostream>
#include <vector>
#include "propertySquare.h"

using namespace std;

//lotSquare class inherits from propertySquare class
class lotSquare : public propertySquare
{
	//Private variables
private:
	//Inherited from propertySquare
	typedef propertySquare inherited;
	int lotRent;
	string lotColor;
	int lotHouseCost;
	bool lotHotelOwned;
public:
	//Constructor for lotSquare
	lotSquare(int position, string tileName, int cost, int rent, string color, int houseCost);

	//Getters and Setters
	int getLotRent();
	string getLotColor();
	int getLotHouseCost();
	bool getLotHotelOwned();
	void setLotRent(int rent);
	void setLotColor(string color);
	void setLotHouseCost(int houseCost);
	void setLotHotelOwned(bool hotelOwned);
	//purchase lot function takes player as parameter
	void purchaseLot(player& player);
	
	//getActions function takes player as parameter
	vector<string> getActions(player& player);
	//Gets player selection from actions vector
	int getPlayerSelection(vector<string> actionsVect);
	//Responds to player selection from actions vector
	void replyToPlayerSelection(vector<string>& actions, int selection, player& player);
	//Require action at current square
	void required(player& player);
};
