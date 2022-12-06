#pragma once
#include <iostream>
#include <vector>
#include "boardSquare.h"

using namespace std;

class taxSquare : public boardSquare {
private:
	typedef boardSquare inherited;
	int taxAmount;
public:
	taxSquare(int position, int taxAmount);

	//Setter
	void setTaxAmount(string card);

	//Getter
	int getTaxAmount();

	vector<string> getRequiredActions(player& player);
};