//
// Created by marki on 2024-02-04.
//

#pragma once //Instead of ifndef
#include <string>

using namespace std;


//enum for the Character class
enum class CharacterClass{
    Fighter,
    Wizard,
    Rogue
};



class Character{
public:

    //constructor
    Character(int level, CharacterClass characterClass);

    //destructor
    ~Character();

    //Method to generate ability scores randomly
    void generatedAbilityScores();

    //getters and setters


private:

    //ability scores, generated randomly
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;


    int level;
    CharacterClass characterClass;

    //calculated from ability score subtract 10 from the ability score and then divide the total by 2 (round down)
    int abilityModifier;

    //based on constitution modifier and level
    int hitPoints;

    //based on dexterity modifier
    int armorClass;

    //based on level and strength/dexterity modifiers
    int attackBonus;

    //based on strength modifier
    int damageBonus;

    int item;

    //helper method to calculate ability modifiers.
    int calculateModifier();


};
