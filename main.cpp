#include <iostream>
#include "Fighter.h"

int main() {

    Fighter f1("test1", 5);
    f1.displayCharacterSheet();

    cout << "\nShowing that the initialization of the two fighter is generated randomly. \n\n";

    Fighter f2("test2", 5);
    f2.displayCharacterSheet();

    // Demonstrate utility function usage
    int diceRoll = Character::rollDice(1, 20); // Simulating a d20 roll
    std::cout << "\nSimulating a d20 roll: " << diceRoll << std::endl;

    return 0;
}
