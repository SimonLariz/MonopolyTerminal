#include <iostream>
#include <vector>
#include "gameboard.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
	
	gameboard myBoard = gameboard();
	myBoard.setupPlayers();
	myBoard.setupBoard();

	vector<boardTile*> currentBoard = myBoard.getBoard();
	for (boardTile* tile : currentBoard) {
		cout << tile->getTileName() << endl;
	}

	return 0;
	
}