#pragma once
#include <iostream>
#include <vector>

using namespace std;

class player;


class boardSquare {
private:
	int boardSpaces = 40;
	int spacesFromStart;
	string squareName;
public:
	boardSquare(int position);

	//Setter
	void setSpacesFromStart(int spaces);
	void setName(string name);


	//Getter
	int getSpacesFromStart();
	string getName();

	vector<string> getDefaultActions(player player, vector<string>& actionsVect);

	//Want to buy houses
	//void buyHouses(player);

	//Purchase actual houses
	//void purchaseHouses(player player, lotSquare lot, int amount);

};