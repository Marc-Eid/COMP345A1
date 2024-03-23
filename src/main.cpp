#include <iostream>
#include "classes/Fighter/Fighter.h"
#include "classes/Map/Map.h"
#include "classes/Dice/Dice.h"
#include "classes/Helmet/Helmet.h"
#include "classes/CharacterStrategy/CharacterStrategy.h"
#include "classes/GameLogger/GameLogger.h"


int main() {
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

    return 0;
}
