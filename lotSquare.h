#pragma once
#include <iostream>
#include <vector>
#include "propertySquare.h"

using namespace std;

class lotSquare : public propertySquare
{
private:
	typedef propertySquare inherited;
	int lotRent;
	string lotColor;
	int lotHouseCost;
	bool lotHotelOwned;
public:
	lotSquare(int position, string tileName, int cost, int rent, string color, int houseCost);

	int getLotRent();
	string getLotColor();
	int getLotHouseCost();
	bool getLotHotelOwned();

	void setLotRent(int rent);
	void setLotColor(string color);
	void setLotHouseCost(int houseCost);
	void setLotHotelOwned(bool hotelOwned);

	vector<string> getActions(player& player);
	
	void required(player& player);
};
