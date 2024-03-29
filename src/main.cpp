#include <iostream>
#include "classes/Fighter/Fighter.h"
#include "classes/Map/Map.h"
#include "classes/Dice/Dice.h"
#include "classes/Helmet/Helmet.h"
#include "classes/CharacterStrategy/CharacterStrategy.h"
#include "classes/GameLogger/GameLogger.h"
#include "classes/Shield/Shield.h"
#include "classes/Ring/Ring.h"
#include "classes/ObserverPattern/CharacterObserver.h"


void displayCharacter();
void displayStretegy();
//void characterObserver();
//void displayMap();
//void displayItemContainer();
//void displayDice();
//void displayMapBuilder();
//void displayGameLevelMapBuilder();
//void displayMapEditor();
//void displayCharacterBuilder();

int main() {


    displayCharacter();
    displayStretegy();
//    displayMap();
//    displayMapBuilder();
//    displayGameLevelMapBuilder();
//    displayMapEditor();
//    displayItemContainer();
//    displayDice();
//    displayCharacterBuilder();

    return 0;
}



void displayCharacter(){
    Fighter f1("test1", 5);

    cout << "\nShowing that the initialization of the two fighter is generated randomly. \n\n";
    Fighter f2("test2", 10);

    Item* shield = new Shield("Defender's Shield", Enchantment{3, EnhancementType::ArmorClass});
    Item* ring = new Ring("Ring of Strength", Enchantment{1, EnhancementType::Strength});

    f1.levelUp();
    f1.levelUp();
    f1.equip(shield);
    f1.equip(ring);
    f1.wearItem(0);
    f1.wearItem(0);
    f1.remove();

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