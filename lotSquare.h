#pragma once

#include <iostream>
#include <vector>
#include "property.h"

using namespace std;

class lotSquare : public property {
private:
	typedef property inherited;
	string lotColor;
	int lotRent;
	int housePrice;
	int housesOwned;
	bool hotelOwned;

public:
	//Constructor
	lotSquare(int position, string name, int price, string color, int rent, int housePrice);
	
	//Setter
	void setColor(string color);
	void setRent(int rent);
	void setHousePrice(int price);
	void setHousesOwned(int numHouses);
	void setHotelOwned(bool hotelOwned);
	

	//Gettter
	string getColor();
	int getRent();
	int getHousePrice();
	int getHousesOwned();
	bool isHotelOwned();

	void calcRent(player& player);

	vector<string> getRequiredActions(player& player);
};