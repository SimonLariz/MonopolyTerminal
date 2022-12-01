#pragma once

#include <iostream>
#include <vector>
using namespace std;

class lotSquare : public boardSquare {
private:
	string lotName;
	string lotColor;
	int lotPrice;
	int lotRent;
	int housePrice;
	int housesOwned;
	bool hotelOwned;

public:
	//Constructor
	lotSquare();
	lotSquare(string name, int price, string color, int location, int rent, int housePrice);
	
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

	string calcRent();
};