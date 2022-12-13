#include <iostream>
#include <vector>
#include <string>
#include "boardTile.h"
using namespace std;

boardTile::boardTile()
{
    this->tilePosition = 0;
    this->tileName = "Go";
}

boardTile::boardTile(int tilePosition, string tileName)
{
    this->tilePosition = tilePosition;
    this->tileName = tileName;
}

boardTile::~boardTile()
{
}

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

vector<string> boardTile::getActions()
{
    vector<string> actionsVector;
    cout << "overload me" << endl;
    return actionsVector;
}