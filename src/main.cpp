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
#include "classes/ObserverPattern/CharacterObserver.h"
#include "classes/ObserverPattern/MapObserver.h"
#include "classes/MapEditor/MapEditor.h"
#include "classes/Campaign/Campaign.h"
#include "classes/MapBuilders/MapEditorBuilder.h"
#include "classes/MapBuilders/GameLevelMapBuilder.h"

void displayCharacter();
void displayMap();
void displayItemContainer();
void displayDice();
void displayMapBuilder();
void displayGameLevelMapBuilder();
void displayMapEditor();

int main() {
//
//    Fighter* fighter = new Fighter("fighter 1", 10);
//    CharacterObserver* characterObserver = new CharacterObserver(fighter);
//
//    cout << "calling the display method of the character to show initial state \n\n";
//    fighter->displayCharacterSheet();
//
//    cout << "\n character sheet updated following a change to hitPoints \n\n";
//    fighter->setHitpoints(20);

//    displayCharacter();

    displayMap();
    displayMapBuilder();
    displayGameLevelMapBuilder();
    displayMapEditor();
//    displayItemContainer();
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
    // Create Characters
    Fighter *f1 = new Fighter("mubashir",4);
    Fighter *f2 = new Fighter("Marc",4);
    f1->getAbilityScores();


    // Create a Map
    Map* map = new Map(5,5);

    //Create an Observer

    MapObserver mapObserver = MapObserver(map);

    // Design the Map
    map->Place(1,2,'#');
    map->Place(2,2,'#');
    map->Place(0,3,'S');
    map->Place(1,3,'E');

    // Check if the Map is valid or not
    map->isValid();

    // Start Game for the fighter
    map->startGame(f1);

    // Try moving the character on the map
    map->TryMove(f1,"right");
    map->TryMove(f1,"right");
    map->TryMove(f1,"right");
    map->TryMove(f1,"right");
    map->TryMove(f1,"down");
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
            "\nDice Input: ";
    cin >> diceInput;
    try {
        int diceResult = dice.roll(diceInput);
        cout << "\tRolled: " << diceInput << ", Result: " << diceResult << endl;
        cout << "\nMore Dice Roll Examples:"<< endl;
        cout << "\tRolled: " << "55d100-26" << ", Result: " << dice.roll("55d100-26") << endl;
        cout << "\tRolled: " << "3d20" << ", Result: " << dice.roll("3d20") << endl;
        cout << "\tRolled: " << "3d8-0" << ", Result: " << dice.roll("3d8-0") << endl;
        cout << "\tRolled: " << "3d4+15" << ", Result: " << dice.roll("3d4+15") << endl;
        cout << "\tRolled: " << "9d20+1" << ", Result: " << dice.roll("9d20+1") << endl;
        cout << "\tRolled: " << "7d6" << ", Result: " << dice.roll("7d6") << endl;
        cout << "\tRolled: " << "1d6-100" << ", Result: " << dice.roll("1d6-100") << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

}


void displayFileContent(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for comparison: " << filePath << std::endl;
        return;
    }

    std::cout << "Original map content from file:\n";
    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
    file.close();
}

void displayMapBuilder() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Display Map Builder: Part 4.1" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    MapEditorBuilder builder;
    std::string filePath = "../src/map_example.txt";
    std::cout << "Building the Map from: " <<filePath << std::endl;

    builder.loadMap(filePath);
    Map* loadedMap = builder.getMap();

    if (loadedMap != nullptr) {
        std::cout << "Map loaded successfully.\n";
        loadedMap->printMap(); // This will print the map to the console
    } else {
        std::cerr << "Failed to load map.\n";
    }
    displayFileContent(filePath);

}

void displayGameLevelMapBuilder() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Display Map Builder with Level Adjustments: Part 4.2" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    GameLevelMapBuilder builder;
    std::string filePath = "../src/map_example.txt";

    builder.loadMap(filePath);
    Map* loadedMap = builder.getMap();

    std::cout << "---------------------------------" << std::endl;
    std::cout << "Displaying the Fighter sheet before entering the game:" << std::endl;
    std::cout << "---------------------------------" << std::endl;

    Fighter *f1 = new Fighter("teemo",4);
    loadedMap->startGame(f1);
    f1->displayCharacterSheet();

    std::cout << "---------------------------------" << std::endl;
    std::cout << "Building the Map from: " <<filePath << std::endl;
    std::cout << "---------------------------------" << std::endl;

    if (loadedMap != nullptr) {
        std::cout << "Map loaded successfully.\n";
        loadedMap->printMap(); // This will print the map to the console
    } else {
        std::cerr << "Failed to load map.\n";
    }
    displayFileContent(filePath);

    std::cout << "---------------------------------" << std::endl;
    std::cout << "Displaying the Fighter sheet after entering the game with level 15:" << std::endl;
    std::cout << "---------------------------------" << std::endl;

    builder.adaptToLevel(15);
    f1->displayCharacterSheet();
}

void displayMapEditor() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "\t\tThe Map/Campaign Editor" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    MapEditor editor;
    editor.runEditor();
}