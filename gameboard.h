#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "boardTile.h"
#include "chanceSquare.h"
#include "cornerSquare.h"
#include "lotSquare.h"
#include "propertySquare.h"
#include "railroadSquare.h"
#include "taxSquare.h"
#include "utilSquare.h"

using namespace std;


//gameboard class
class gameboard
{
private:
	//Private variables
	vector<boardTile*> board;
	int diceValue;
	int playerNum;
	player* currentPlayer;
	vector<player*> players;
public:
	//Constructor
	gameboard();
	//Checks if the game is over
	bool isGameOver();
	//Simulates dice roll
	void rollDice();
	//Moves player to new position
	void movePlayer(int position);
	// Move to next turn
	void nextTurn();
	//Ends current turn
	void endTurn();

	//Getters and setters
	int getDiceVale();
	int getPlayerNum();
	player* getCurrentPlayer();
	vector<player*> getPlayers();
	vector<boardTile*> getBoard();
	void setDiceValue(int value);
	void setPlayerNum(int num);
	void setCurrentPlayer(player* player);
	void setupPlayers();
	void setupBoard();

	//Trade property with another player
	int selectPropertyTrade(player& player);
	void tradeProperty();
	//Main game loop
	void playGame();
};

