#include <iostream>
#include "Fighter.h"
#include "Map.h"

int main() {

    Fighter f1("test1", 5);
    f1.displayCharacterSheet();

    cout << "\nShowing that the initialization of the two fighter is generated randomly. \n\n";

    Fighter f2("test2", 5);
    f2.displayCharacterSheet();

    // Demonstrate utility function usage
    int diceRoll = Character::rollDice(1, 20); // Simulating a d20 roll
    std::cout << "\nSimulating a d20 roll: " << diceRoll << std::endl;


    // Create a Map
    Map map = Map(5,5);
    //map.Place(2,3,'#');

    map.Place(1,2,'#');
    map.Place(2,2,'#');
    map.Place(0,3,'S');
    map.Place(1,3,'E');
    map.isValid();


    // Print the Map
    map.printMap();



    return 0;
}
