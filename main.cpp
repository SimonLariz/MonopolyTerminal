#include <iostream>
#include "chanceSquare.h"
#include "player.h"
#include "property.h"
#include "utilSquare.h"

using namespace std;


int main()
{
    srand((unsigned int)time(NULL));
    cout << "Hello world\n";
    /*
    chanceSquare mySquare(10, "Community Chest");
    cout << "Done\n";
    cout << mySquare.getCardType() << "\n";
    cout << mySquare.getSpacesFromStart() << "\n";
    
    player myPlayer("Simon", "Car");
    cout << myPlayer.getPlayerName() << "\n";

    mySquare.getRequiredActions(myPlayer);
    cout << "Updated money: " << myPlayer.getPlayerMoney() << "\n";
    myPlayer.addPlayerProperty(23);
    myPlayer.addPlayerProperty(31);
    cout << "Prop size: " << myPlayer.getPlayerProperty().size() << "\n";
    vector<string> myActions;
    mySquare.getDefaultActions(myPlayer, myActions);
    for (string str : myActions) {
        cout << str << "\n";
    }

    property myProperty("Casa Lariz", 400, 15);
    cout << "Property Name: " << myProperty.getName() << "\n";
    cout << "Property Cost: " << myProperty.getCost() << "\n";
    cout << "Property Owner: " << myProperty.getName() << "\n";
    */
    player playerOne("Simon", "Car");
    player playerTwo("Mike", "Shoe");

    utilSquare testUtil(10, "Water Works", 150);
    testUtil.setOwner(&playerOne);

    cout << "Water works owner: " << testUtil.getOwner()->getPlayerName() << "\n";

    testUtil.calcRent(playerTwo);

    cout << "playerOne money:" << playerOne.getPlayerMoney() << "\n";
    cout << "playerTwo money:" << playerTwo.getPlayerMoney() << "\n";


}


