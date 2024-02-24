#include <iostream>
#include "classes/Fighter/Fighter.h"
#include "classes/Map/Map.h"
#include "classes/Dice/Dice.h"

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


    Dice dice;
    string diceInput;
    cout << "Enter a string of the form xdy[+z], where:\n"
            "\tx is the number of dice,\n"
            "\tdy the kind of dice (d4, d6, d8, d10, d12, d20 or d100),\n"
            "\tz is a negative of positive number added after all the dice results have been added (optional).\n"
            "Dice Input: ";
    cin >> diceInput;
    try {
        int diceResult = dice.roll(diceInput);
        cout << "Rolled: " << diceInput << ", Result: " << diceResult << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
