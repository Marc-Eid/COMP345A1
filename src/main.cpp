#include <iostream>
#include <fstream>
#include "classes/Fighter/Fighter.h"
#include "classes/Map/Map.h"
#include "classes/Dice/Dice.h"
#include "classes/Helmet/Helmet.h"
#include "classes/CharacterStrategy/CharacterStrategy.h"
#include "classes/GameLogger/GameLogger.h"
#include "classes/Shield/Shield.h"
#include "classes/ItemContainer/ItemContainer.h"
#include "classes/Ring/Ring.h"
#include "classes/ObserverPattern/CharacterObserver.h"
#include "classes/MapBuilders/MapEditorBuilder.h"
#include "classes/MapBuilders/GameLevelMapBuilder.h"
#include "classes/MapEditor/MapEditor.h"
#include "classes/CharacterEditor/CharacterEditor.h"
#include "classes/ItemContainerEditor/ItemContainerEditor.h"
#include "classes/Armor/Armor.h"


void displayCharacter();
void displayStretegy();
void displayMapBuilder();
//void characterObserver();
//void displayMap();
//void displayMapEditor();
//void displayItemContainer();
//void displayDice();
//void displayMapBuilder();
//void displayGameLevelMapBuilder();
//void displayMapEditor();
//void displayCharacterBuilder();
//void displayFileContent(const std::string& filePath);
//void displayCharacterEditor();
//void  displayChestEditor();
void displayNpcEditor();

int main() {


//    displayCharacter();
//    displayFileContent("../src/map_example.txt");
//    displayStretegy();
//    displayMap();
//    displayMapBuilder();
//    displayGameLevelMapBuilder();
//    displayMapEditor();
//    displayItemContainer();
//    displayDice();
//    displayCharacterBuilder();
//    displayCharacterEditor();
//    displayChestEditor();
displayStretegy();

    return 0;

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

void displayCharacter(){
    Fighter f1("test1", 5);

    cout << "\nShowing that the initialization of the two fighter is generated randomly. \n\n";
    Fighter f2("test2", 10);

    Item* shield = new Shield("Defender's Shield");
    Item* ring = new Ring("Ring of Strength");

    f1.levelUp();
    f1.levelUp();
    f1.equip(shield);
    f1.equip(ring);
    f1.wearItem(0);
    f1.wearItem(0);
//    f1.remove();

    f1.displayCharacterSheet();
    f2.displayCharacterSheet();

    // Demonstrate utility function usage
    int diceRoll = Character::rollDice(1, 20); // Simulating a d20 roll
    std::cout << "\nSimulating a d20 roll: " << diceRoll << std::endl;
};

void characterObserver(){
    Fighter* fighter = new Fighter("fighter 1", 10);
    CharacterObserver* characterObserver = new CharacterObserver(fighter);

    cout << "calling the display method of the character to show initial state \n\n";
    fighter->displayCharacterSheet();

    cout << "\ncharacter sheet updated following a change to hitPoints \n\n";
    fighter->setHitpoints(20);

    cout << "\n";

}

void displayStretegy(){
    auto *p1 = new Fighter("Player1",4);
    auto *npc = new Fighter("NPC",4);
    p1->getAbilityScores();
    npc->getAbilityScores();

    // Create a Map and a Dice
    Map* map = new Map(10,5);
    Dice* dice = new Dice();

    //Create a Game Logger
    auto* log = new GameLogger();
    dice->attach(log);
    map->attach(log);
    p1->attach(log);
    npc->attach(log);

    // Design the Map
    map->Place(1,2,'#');
    map->Place(2,2,'#');
    map->Place(0,3,'S');
    map->Place(0,1,'E');

    // Check if the Map is valid or not
    map->isValid();

    // Start Game for the fighters
    map->startGame(p1, 1, 3);
    map->startGame(npc, 8, 2);
    map->printMap();

    // Player1's turn (Human Strategy)
    auto* humanStrategy = new HumanPlayerStrategy();
    p1->setStrategy(humanStrategy);
    p1->move(map);
    p1->attack(map);
    p1->freeAction();

    // NPC's turn (Friendly Strategy)
    auto* friendlyStrategy = new FriendlyStrategy();
    npc->setStrategy(friendlyStrategy);
    npc->move(map);
    npc->attack(map);

    // Player1's turn (Human Strategy)
    p1->move(map);
    p1->attack(map);
    p1->freeAction();

    // NPC's turn (Aggressor Strategy)
    npc->move(map);
    npc->attack(map);

    // switch on/off logging sources
    npc->setLogging(false);

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
    loadedMap->startGame(f1,2,2);
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
    std::cout << "\n\n-----------------------------------------------" << std::endl;
    std::cout << "\tWemcome to the Map/Campaign Editor" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    MapEditor editor;
    editor.runEditor();
}

void displayCharacterEditor(){
    std::cout << "\n\n-----------------------------------------------" << std::endl;
    std::cout << "\tWemcome to the Character Editor" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    CharacterEditor characterEditor;
    characterEditor.runCharacterEditor();

}

//void displayChestEditor(){
//    std::cout << "\n\n-----------------------------------------------" << std::endl;
//    std::cout << "\tWemcome to the Chest Editor" << std::endl;
//    std::cout << "-----------------------------------------------" << std::endl;
//
//    ItemContainerEditor itemContainerEditor;
//    itemContainerEditor.run();
//
//}
//
//void displayNpcEditor() {
//    std::cout << "\n\n-----------------------------------------------" << std::endl;
//    std::cout << "\tWemcome to the NPC Editor" << std::endl;
//    std::cout << "-----------------------------------------------" << std::endl;
//
//    CharacterEditor *editor = new CharacterEditor();
//    editor->runNpcEditor();
//};

