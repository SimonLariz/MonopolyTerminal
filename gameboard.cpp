#include <iostream>
#include <vector>
#include <string>
#include "gameboard.h"

using namespace std;

gameboard::gameboard() 
{
}

bool gameboard::isGameOver() {
	int playerBankrupt = 0;
	for (player* player : players) {
		if (player->getBankrupt()) {
			playerBankrupt++;
		}
	}
	if (playerBankrupt == players.size() - 1) {
		return true;
	}
	return false;
}

void gameboard::rollDice() {
	int value = 0;
	diceValue = rand() % 6 + 1;
	value += diceValue;
	diceValue = rand() % 6 + 1;
	value += diceValue;
	this->setDiceValue(value);
}

void gameboard::movePlayer(int position) {
	bool passGoSquare = false;
	if (currentPlayer->getPlayerPostion() + position > 39) {
		passGoSquare = true;
	}
	int newPosition = currentPlayer->getPlayerPostion() + position;
	if (newPosition > 39) {
		newPosition -= 40;
	}
	if (passGoSquare) {
		cout << "You passed Go Square, you have earned $200\n";
		currentPlayer->setPlayerMoney(currentPlayer->getPlayerMoney() + 200);
	}
	currentPlayer->setPlayerPosition(newPosition);
}

void gameboard::nextTurn() {
	rollDice();
	movePlayer(diceValue);
}

void gameboard::endTurn() {
	int currentPlayerIndex = 0;
	for (int i = 0; i < players.size(); i++) {
		if (players[i] == currentPlayer) {
			currentPlayerIndex = i;
		}
	}
	if (currentPlayerIndex == players.size() - 1) {
		currentPlayerIndex = 0;
	}
	else {
		currentPlayerIndex++;
	}
	currentPlayer = players[currentPlayerIndex];
}

int gameboard::getDiceVale() {
	return diceValue;
}

int gameboard::getPlayerNum() {
	return playerNum;
}

player* gameboard::getCurrentPlayer() {
	return currentPlayer;
}

vector<player*> gameboard::getPlayers() {
	return players;
}

void gameboard::setDiceValue(int value) {
	diceValue = value;
}

void gameboard::setPlayerNum(int num) {
	playerNum = num;
}

void gameboard::setCurrentPlayer(player* player) {
	currentPlayer = player;
}

void gameboard::setupPlayers() {
	cout << "How many players are playing? (2-4)\n";
	cin >> playerNum;
	while (playerNum < 2 || playerNum > 4) {
		cout << "Invalid number of players, please enter a number between 2 and 4\n";
		cin >> playerNum;
	}
	for (int i = 0; i < playerNum; i++) {
		string name;
		string token;
		cout << "Enter player " << i + 1 << "'s name:\n";
		cin >> name;
		cout << "Enter player " << i + 1 << "'s token:\n";
		cin >> token;
		player* newPlayer = new player(name, 2000, token);
		players.push_back(newPlayer);
	}
	currentPlayer = players[0];
}

vector<boardTile*> gameboard::getBoard() {
	return this->board;
}

void gameboard::setupBoard() {
	this->board.push_back(new cornerSquare(0, "GO"));
	this->board.push_back(new lotSquare(1, "Mediterranean Avenue", 60, 2, "BROWN", 50));
	this->board.push_back(new chanceSquare(2, "Community Chest"));
	this->board.push_back(new lotSquare(3, "Baltic Avenue", 60, 4, "BROWN", 50));
	this->board.push_back(new taxSquare(4, "Income Tax", 200));
	this->board.push_back(new railroadSquare(5, "Reading Railroad", 200));
	this->board.push_back(new lotSquare(6, "Oriental Avenue", 100, 6, "TEAL", 50));
	this->board.push_back(new chanceSquare(7, "Chance"));
	this->board.push_back(new lotSquare(8, "Vermont Avenue", 100, 6, "TEAL", 50));
	this->board.push_back(new lotSquare(9, "Connecticut Avenue", 120, 8, "TEAL", 50));
	this->board.push_back(new cornerSquare(10, "Jail"));
	this->board.push_back(new lotSquare(11, "St. Charles Place", 140, 10, "PINK", 100));
	this->board.push_back(new utilSquare(12, "Electric Company", 150));
	this->board.push_back(new lotSquare(13, "States Avenue", 140, 10, "PINK", 100));
	this->board.push_back(new lotSquare(14, "Virginia Avenue", 160, 12, "PINK", 100));
	this->board.push_back(new railroadSquare(15, "Pennsylvania Railroad", 200));
	this->board.push_back(new lotSquare(16, "St. James Place", 180, 14, "ORANGE", 100));
	this->board.push_back(new chanceSquare(17, "Community Chest"));
	this->board.push_back(new lotSquare(18, "Tennessee Avenue", 180, 14, "ORANGE", 100));
	this->board.push_back(new lotSquare(19, "New York Avenue", 200, 16, "ORANGE", 100));
	this->board.push_back(new cornerSquare(20, "Free Parking"));
	this->board.push_back(new lotSquare(21, "Kentucky Avenue", 220, 18, "RED", 150));
	this->board.push_back(new chanceSquare(22, "Chance"));
	this->board.push_back(new lotSquare(23, "Indiana Avenue", 220, 18, "RED", 150));
	this->board.push_back(new lotSquare(24, "Illinois Avenue", 240, 20, "RED", 150));
	this->board.push_back(new railroadSquare(25, "B. & O. Railroad", 200));
	this->board.push_back(new lotSquare(26, "Atlantic Avenue", 260, 22, "YELLOW", 150));
	this->board.push_back(new lotSquare(27, "Ventnor Avenue", 260, 22, "YELLOW", 150));
	this->board.push_back(new utilSquare(28, "Water Works", 150));
	this->board.push_back(new lotSquare(29, "Marvin Gardens", 280, 24, "YELLOW", 150));
	this->board.push_back(new cornerSquare(30, "Go To Jail"));
	this->board.push_back(new lotSquare(31, "Pacific Avenue", 300, 26, "GREEN", 200));
	this->board.push_back(new lotSquare(32, "North Carolina Avenue", 300, 26, "GREEN", 200));
	this->board.push_back(new chanceSquare(33, "Community Chest"));
	this->board.push_back(new lotSquare(34, "Pennsylvania Avenue", 320, 28, "GREEN", 200));
	this->board.push_back(new railroadSquare(35, "Short Line", 200));
	this->board.push_back(new chanceSquare(36, "Chance"));
	this->board.push_back(new lotSquare(37, "Park Place", 350, 35, "BLUE", 200));
	this->board.push_back(new taxSquare(38, "Luxury Tax", 100));
	this->board.push_back(new lotSquare(39, "Boardwalk", 400, 50, "BLUE", 200));
}
