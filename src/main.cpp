#include <iostream>
#include "classes/Fighter/Fighter.h"
#include "classes/Map/Map.h"
#include "classes/Dice/Dice.h"
#include "classes/ItemContainer/ItemContainer.h"
#include "classes/Helmet/Helmet.h"
#include "classes/Armor/Armor.h"
#include "classes/Shield/Shield.h"
#include "classes/Boots/Boots.h"
#include "classes/Ring/Ring.h"

void displayCharacter();
void displayMap();
void displayItemContainer();
void displayDice();

int main() {
    displayCharacter();
    displayMap();
    displayItemContainer();
//    displayDice();
    return 0;
}

void displayCharacter(){
    Fighter f1("test1", 5);
    f1.displayCharacterSheet();

    cout << "\nShowing that the initialization of the two fighter is generated randomly. \n\n";

    Fighter f2("test2", 5);
    f2.displayCharacterSheet();

    // Demonstrate utility function usage
    int diceRoll = Character::rollDice(1, 20); // Simulating a d20 roll
    std::cout << "\nSimulating a d20 roll: " << diceRoll << std::endl;


};
void displayMap(){
    displayCharacter();
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
};

void displayItemContainer(){
    ItemContainer container;

    // Create items and add them to the container
    Item* helmet(new Helmet("Knight's Helmet", Enchantment{5, EnhancementType::ArmorClass}));
    Item* armor(new Armor("Warrior's Armor", Enchantment{2, EnhancementType::ArmorClass}));
    Item* shield(new Shield("Defender's Shield", Enchantment{3, EnhancementType::ArmorClass}));
    Item* ring(new Ring("Ring of Strength", Enchantment{1, EnhancementType::Strength}));
    Item* boots = new Boots("Swiftstride Boots", Enchantment{4, EnhancementType::Dexterity});

    container.addItem(helmet);
    container.addItem(armor);
    container.addItem(shield);
    container.addItem(ring);
    container.addItem(boots);

    cout << endl;
    cout << "Printing elements in the Item Container: " << endl;
    container.printItems();
    cout << endl;

}

void displayDice() {
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

    displayItemContainer();
};