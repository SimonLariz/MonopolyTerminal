#pragma once
#include <iostream>
#include <vector>
#include "boardSquare.h"

using namespace std;

class chanceSquare : public boardSquare {
private:
	typedef boardSquare inherited;
	string cardType;
public:
	chanceSquare(int position, string cardType);

	//Setter
	void setCardType(string card);

	//Getter
	string getCardType();

	vector<string> getRequiredActions(player& player);
};