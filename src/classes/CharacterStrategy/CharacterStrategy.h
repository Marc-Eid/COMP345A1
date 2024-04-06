//
// Created by Oliver Hassan on 2024-03-23.
//

#ifndef COMP345A1_CHARACTERSTRATEGY_H
#define COMP345A1_CHARACTERSTRATEGY_H


#include "../Character/Character.h"
#include "../Map/Map.h"

class Character;

class CharacterStrategy {

public:
    virtual string round(Character* c,Map* map) = 0;
    virtual void move(Character* c, Map* map) = 0;
    virtual void attack(Character* source, Map* map) = 0;
    virtual ~CharacterStrategy() {}
};



class HumanPlayerStrategy : public CharacterStrategy {

public:
    string round(Character *c, Map *map) override;
    void move(Character* c, Map* map) override;
    void attack(Character* source, Map* map) override;
    void freeAction();
};



class AggressorStrategy : public CharacterStrategy {

public:
    string round(Character *c, Map *map) override;
    void move(Character* c, Map* map) override;
    void attack(Character* source, Map* map) override;
};

class FriendlyStrategy : public CharacterStrategy {

public:
    string round(Character *c, Map *map) override;
    void move(Character* c, Map* map) override;
    void attack(Character* source, Map* map) override;
};


#endif //COMP345A1_CHARACTERSTRATEGY_H
