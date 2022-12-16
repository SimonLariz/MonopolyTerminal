#include <iostream>
#include <vector>
#include <string>
#include "boardTile.h"
using namespace std;

//Constructor for boardTile
boardTile::boardTile()
{
    this->tilePosition = 0;
    this->tileName = "Go";
}

//Constructor for boardTile with parameters
boardTile::boardTile(int tilePosition, string tileName)
{
    this->tilePosition = tilePosition;
    this->tileName = tileName;
}

//Destructor for boardTile
boardTile::~boardTile()
{
}

//Getters and setters
string boardTile::getTileName()
{
    return tileName;
}
int boardTile::getTilePosition()
{
    return tilePosition;
}
void boardTile::setTileName(string tileName)
{
    this->tileName = tileName;
}
void boardTile::setTilePosition(int tilePosition)
{
    this->tilePosition = tilePosition;
}

//Overloaded functions by derived classes
vector<string> boardTile::getActions(player& player)
{
    vector<string> actionsVector;
    cout << "overload me" << endl;
    return actionsVector;
}

int boardTile::getPlayerSelection(vector<string> actionsVect)
{
	cout << "overload me" << endl;
	return 0;
}

void boardTile::replyToPlayerSelection(vector<string>& actions, int selection, player& player)
{
	cout << "overload me" << endl;
}