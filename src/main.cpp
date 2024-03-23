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
#include "classes/Builder/BullyBuilder.h"
#include "classes/CharacterStrategy/CharacterStrategy.h"

int main() {
    Fighter *p1 = new Fighter("mubashir",4);
    Fighter *npc = new Fighter("x",4);
    p1->getAbilityScores();
    npc->getAbilityScores();

    // Create a Map
    Map* map = new Map(10,5);

    //Create an Observer
    MapObserver mapObserver = MapObserver(map);

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

    // Human Player Strategy
    HumanPlayerStrategy* humanStrategy = new HumanPlayerStrategy();
    p1->setStrategy(humanStrategy);
    p1->move(map);
    p1->attack(map);
    p1->freeAction();

    // Friendly Strategy
    FriendlyStrategy* friendlyStrategy = new FriendlyStrategy();
    npc->setStrategy(friendlyStrategy);
    npc->move(map);
    npc->attack(map);

    // Human Player Strategy
    p1->attack(map);

    // Aggressor Strategy
    npc->move(map);
    npc->attack(map);


    return 0;
}
