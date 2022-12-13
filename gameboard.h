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

class gameboard
{
private:
	vector<boardTile*> board;
	int diceValue;
	int playerNum;
	player* currentPlayer;
	vector<player*> players;
public:
	gameboard();
	bool isGameOver();
	void rollDice();
	void movePlayer(int position);
	void nextTurn();
	void endTurn();

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
};

