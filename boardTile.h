#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class player;

//boardTile abstract class, Parent class of all board tiles
class boardTile
{
	//Private data members
private:
    int maxTiles = 40;
    int tilePosition;
    string tileName;

public:
	//Constructors and destructors
    boardTile();
    boardTile(int tilePosition, string tileName);
    ~boardTile();

	//Gets all possible actions for the player at current tile
    virtual vector<string> getActions(player& player);
	//Gets player selection from the vector of actions
	virtual int getPlayerSelection(vector<string> actionsVect);
	//Responds to player selection
    virtual void replyToPlayerSelection(vector<string>& actions, int selection, player& player);
    
	//Getters and setters
    int getTilePosition();
    string getTileName();
    void setTilePosition(int tilePosition);
    void setTileName(string tileName);
};