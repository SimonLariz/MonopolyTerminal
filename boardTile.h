#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class player;

class boardTile
{
private:
    int maxTiles = 40;
    int tilePosition;
    string tileName;

public:
    boardTile();
    boardTile(int tilePosition, string tileName);
    ~boardTile();

    virtual vector<string> getActions();
    
    int getTilePosition();
    string getTileName();
    void setTilePosition(int tilePosition);
    void setTileName(string tileName);
};