#include <iostream>
#include <vector>
#include "gameboard.h"

using namespace std;

int main()
{
	//Set random seed
	srand((unsigned int)time(NULL));
	//Create gameboard
	gameboard myBoard = gameboard();
	//Set up players
	myBoard.setupPlayers();
	//Set up board
	myBoard.setupBoard();
	//Play monopoly
	myBoard.playGame();
	return 0;
}
