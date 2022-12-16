#include <iostream>
#include <vector>
#include <string>
#include "gameboard.h"

using namespace std;

//gameboard constructor
gameboard::gameboard()
{
}

//Returns if the game is over
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

//Simualtes dice roll
void gameboard::rollDice() {
	//Roll dice twice since it is not a normal distribution
	int value = 0;
	diceValue = rand() % 6 + 1;
	value += diceValue;
	diceValue = rand() % 6 + 1;
	value += diceValue;
	this->setDiceValue(value);
}
//Moves player to new position
void gameboard::movePlayer(int position) {
	bool passGoSquare = false;
	if (currentPlayer->getPlayerPostion() + position > 39) {
		passGoSquare = true;
	}
	//Bounds checking
	int newPosition = currentPlayer->getPlayerPostion() + position;
	if (newPosition > 39) {
		newPosition -= 40;
	}
	//If player passes go, add $200 to their balance
	if (passGoSquare) {
		cout << "You passed Go Square, you have earned $200\n";
		currentPlayer->setPlayerMoney(currentPlayer->getPlayerMoney() + 200);
	}
	currentPlayer->setPlayerPosition(newPosition);
}

//Move to next turn
void gameboard::nextTurn() {
	rollDice();
	movePlayer(diceValue);
}

//End current turn
void gameboard::endTurn() {
	int currentPlayerIndex = 0;
	//Update player index
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

//Getters and setters
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
//Setup players
void gameboard::setupPlayers() {
	//Ask for number of players
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

//Returns the board
vector<boardTile*> gameboard::getBoard() {
	return this->board;
}

//Select a property to trade
int gameboard::selectPropertyTrade(player& player) {
	int propertyIndex = 0;
	cout << "Select a property to trade:\n";
	cout << "0. Cancel\n";
	for (int i = 0; i < player.getPlayerProperty().size(); i++) {
		cout << i + 1 << ". " << board[player.getPlayerProperty()[i]]->getTileName() << "\n";
	}
	cin >> propertyIndex;
	//Cancel == return -1
	if (propertyIndex == 0) {
		return -1;
	}
	return player.getPlayerProperty()[propertyIndex - 1];
}

//Trade property function 
//LOTS OF C++ MAGIC HAPPENS HERE
void gameboard::tradeProperty() {
	//Keep track of players with properties
	int playersWithProperty = 0;
	//Vector of player class REFERENCES
	vector<player*> playersWithPropertyVector;
	int numPlayers = players.size();
	//Update playersWithPropertyVector
	for (auto player : players) {
		if (player != currentPlayer) {
			if (player->getPlayerProperty().size() > 0) {
				playersWithPropertyVector.push_back(player);
			}
		}
	}
	//If there are no players with properties, return
	if (playersWithPropertyVector.size() == 0) {
		cout << "No other players have any properties to trade\n";
		return;
	}
	//Select player to trade with
	else {
		cout << "Select a player to trade with:\n";
		cout << "0. Cancel\n";
		for (int i = 0; i < playersWithPropertyVector.size(); i++) {
			cout << i + 1 << ". " << playersWithPropertyVector[i]->getPlayerName() << "\n";
		}
		cout << "Player selection: ";
		int playerIndex = 0;
		cin >> playerIndex;
		if (playerIndex == 0) {
			return;
		}
		playerIndex--;
		int propertyIndex = selectPropertyTrade(*currentPlayer);
		if (propertyIndex == -1) {
			return;
		}
		int propertyIndex2 = selectPropertyTrade(*playersWithPropertyVector[playerIndex]);
		if (propertyIndex2 == -1) {
			return;
		}
		//Remove property from player 1
		currentPlayer->removePlayerProperty(propertyIndex);
		//Add property to player 2
		playersWithPropertyVector[playerIndex]->removePlayerProperty(propertyIndex2);
		//Remove property from player 2
		currentPlayer->addPlayerProperty(propertyIndex2);
		//Add property to player 1
		playersWithPropertyVector[playerIndex]->addPlayerProperty(propertyIndex);
		
		cout << "Trade successful\n";
		cout << "You traded " << board[propertyIndex]->getTileName() << " for " << board[propertyIndex2]->getTileName() << "\n";
		cout << "Your properties:" << "\n";
		//Print new properties for players
		for (int i = 0; i < currentPlayer->getPlayerProperty().size(); i++) {
			cout << "\t" << board[currentPlayer->getPlayerProperty()[i]]->getTileName() << "\n";
		}
		cout << playersWithPropertyVector[playerIndex]->getPlayerName() << "'s properties:" << "\n";
		for (int i = 0; i < playersWithPropertyVector[playerIndex]->getPlayerProperty().size(); i++) {
			cout << "\t" << board[playersWithPropertyVector[playerIndex]->getPlayerProperty()[i]]->getTileName() << "\n";
		}
	}
}

//Main game loop
void gameboard::playGame() {
	//Loop until game is over
	while (!isGameOver()) {
		cout << "\n\n\n";
		cout << currentPlayer->getPlayerName() << "'s turn\n";
		cout << "Money: " << currentPlayer->getPlayerMoney() << "\n";
		vector <int> playerProperties = currentPlayer->getPlayerProperty();

		if (playerProperties.size() > 0) {
			cout << "You own the following properties:\n";
			for (int i = 0; i < playerProperties.size(); i++) {
				cout << "\t" << i + 1 << ": " << board[playerProperties[i]]->getTileName() << endl;
			}
			cout << "\n\n";
		}
		cout << "Press enter to roll the dice\n";
		cin.ignore();
		nextTurn();
		cout << "You rolled a " << diceValue << endl;
		cout << "You landed on " << board[currentPlayer->getPlayerPostion()]->getTileName() << endl;

		vector<string> actions = board[currentPlayer->getPlayerPostion()]->getActions(*currentPlayer);

		while (!actions.empty()) {
			int playerSelection = board[currentPlayer->getPlayerPostion()]->getPlayerSelection(actions);
			if (actions[playerSelection] == "End Turn") {
				break;
			}
			else if (actions[playerSelection] == "Trade Property") {
				tradeProperty();
				break;
			}
			board[currentPlayer->getPlayerPostion()]->replyToPlayerSelection(actions, playerSelection, *currentPlayer);

		}

		endTurn();
	}
}

//board setup
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